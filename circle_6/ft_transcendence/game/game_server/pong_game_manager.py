import os
import uuid

from .models import TournamentTable
from .pong_game import PongGame
from channels.layers import get_channel_layer
import asyncio
from game_data.models import GameDataModel
from channels.db import database_sync_to_async
import requests

class PongGameManager:
    def __init__(self):
        self.games = dict()
        self.playing_tournament = dict()  # uuid -> table id

    async def create_game(self, room_group_name):
        game = PongGame()
        self.games[room_group_name] = game

    async def enroll_player1(self, room_group_name):
        game = self.games[room_group_name]
        channel_layer = get_channel_layer()

        game.player1_channel_name = list(channel_layer.groups[room_group_name].keys())[0]

    async def enroll_player2(self, room_group_name):
        game = self.games[room_group_name]
        channel_layer = get_channel_layer()

        game.player2_channel_name = list(channel_layer.groups[room_group_name].keys())[1]

    async def start_game(self, room_group_name):
        game = self.games[room_group_name]
        channel_layer = get_channel_layer()

        await self.wait_before_game_start(10, room_group_name)
        await self.send_game_start(room_group_name)

        while len(channel_layer.groups[room_group_name]) == 2 and game.status == 'play':
            data = game.next_frame()
            data['type'] = 'send_game_status'

            await channel_layer.group_send(room_group_name, data)
            await asyncio.sleep(0.05)

        await self.handle_escape(room_group_name)
        game_type = await self.check_tournament(room_group_name)
        await self.game_end(room_group_name, game_type)

    @database_sync_to_async
    def check_tournament(self, room_group_name):
        if room_group_name not in self.playing_tournament:
            return 'Random'
        table_id, game_id = self.playing_tournament[room_group_name]
        self.playing_tournament.pop(room_group_name)
        table = TournamentTable.objects.get(id=table_id)
        game: PongGame = self.games[room_group_name]
        win_id = None
        if game.winning_score == game.score[0]:
            win_id = game.player1_id
        elif game.winning_score == game.score[1]:
            win_id = game.player2_id

        if game_id == 1:
            table.winner1 = win_id
        elif game_id == 2:
            table.winner2 = win_id
        elif game_id == 3:  # tournament end
            url = os.environ.get('CHATTING_SERVER')
            data = {
                'target_id': win_id,
                'message': 'YOU WIN!'
            }
            requests.post(url, json=data)
            table.delete()
            return 'Tournament-Final Round'

        table.save()
        if table.winner1 is not None and table.winner2 is not None:
            url = os.environ.get('CHATTING_SERVER')
            room_id = str(uuid.uuid4())
            data = {
                'type': 'invite_game',
                'target_id': table.winner1,
                'room_id': room_id,
                'message': 'Next Match',
                'opponent_id': table.winner2
            }
            response = requests.post(url, json=data)
            data = {
                'type': 'invite_game',
                'target_id': table.winner2,
                'room_id': room_id,
                'message': 'Next Match',
                'opponent_id': table.winner1
            }
            response = requests.post(url, json=data)
            self.playing_tournament[room_id] = [table_id, 3]

        return 'Tournament-First Round'

    async def game_end(self, room_group_name, game_type):
        game: PongGame = self.games[room_group_name]
        channel_layer = get_channel_layer()
        message = {
            'type': 'send_system_message',
            'message': 'Game End',
            'score': game.score,
        }

        await database_sync_to_async(GameDataModel.create_match_and_save_game)({
            "user1_id": game.player1_id,
            "user2_id": game.player2_id,
            "user1_score": game.score[0],
            "user2_score": game.score[1],
            "match_type": game_type,
        })
        await self.update_user_stat(room_group_name, game_type)

        await channel_layer.group_send(room_group_name, message)
        self.games.pop(room_group_name)

    async def update_user_stat(self, room_group_name, game_type):
        game: PongGame = self.games[room_group_name]

        url = os.environ.get('USER_MANAGEMENT_SERVER') + 's2sapi/user-management/user-api/update-stat/'
        winning_id = None
        loser_id = None
        if game.score[0] == game.winning_score:
            winning_id = game.player1_id
            loser_id = game.player2_id
        else:
            winning_id = game.player2_id
            loser_id = game.player1_id
        message = {
            'winner_id': winning_id,
            'loser_id': loser_id,
            'game_type': game_type
        }
        res = requests.patch(url, json=message, timeout=5)
        if res.status_code != 201:
            raise Exception('User Update Error')

    def get_game(self, room_group_name):
        return self.games.get(room_group_name)

    # 각 channel에 플레이어 정보 및 10초 카운트
    async def wait_before_game_start(self, second:int, room_group_name):
        channel_layer = get_channel_layer()
        game = self.games[room_group_name]
        message = {
            'type': 'send_system_message',
            'message': 'Game Ready',
            'counter': second,
        }
        for i in range(second, 0, -1):
            message['counter'] = i
            message['player'] = 1
            await channel_layer.send(game.player1_channel_name, message)
            message['player'] = 2
            await channel_layer.send(game.player2_channel_name, message)
            await asyncio.sleep(1)

    async def send_game_start(self, room_group_name):
        channel_layer = get_channel_layer()
        game = self.games[room_group_name]
        message = {
            'type': 'send_system_message',
            'message': 'Game Start'
        }
        await channel_layer.send(game.player1_channel_name, message)
        await channel_layer.send(game.player2_channel_name, message)


    async def handle_escape(self, room_group_name):
        game: PongGame = self.games[room_group_name]
        channel_layer = get_channel_layer()

        if game.status != 'end':  # 탈주 종료
            if game.player1_channel_name not in channel_layer.groups[room_group_name].keys():  # player 1 탈주
                game.score[0], game.score[1] = [0, game.winning_score]
            elif game.player2_channel_name not in channel_layer.groups[room_group_name].keys():  # player 2 탈주
                game.score[0], game.score[1] = [game.winning_score, 0]
