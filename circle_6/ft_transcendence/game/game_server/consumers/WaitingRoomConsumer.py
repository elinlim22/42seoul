from channels.db import database_sync_to_async
from channels.generic.websocket import AsyncJsonWebsocketConsumer

from game_server.consumers.GameServerConsumers import GameServerConsumer
from ..authentication import authenticate
import uuid
from ..models import TournamentTable

unauthenticated_room = 'unauthenticated_room'


class WaitingRoomConsumer(AsyncJsonWebsocketConsumer):
    async def connect(self):
        await self.accept()
        await self.channel_layer.group_add(unauthenticated_room, self.channel_name)

    async def disconnect(self, close_code):
        try:
            await self.channel_layer.group_discard(unauthenticated_room, self.channel_name)
        except:
            pass

    async def receive_json(self, content, **kwargs):
        if 'token' not in content.keys():
            await self.close(3401)
            return
        user = await authenticate(content['token'])
        if not user:
            await self.send_json({
                'error': 'Invalid token'
            })
            await self.close(3401)
            return
        self.scope['user'] = user
        await self.channel_layer.group_discard(unauthenticated_room, self.channel_name)


class TournamentWaitingRoomConsumer(WaitingRoomConsumer):
    waiting_list = {}  # channel_name -> user

    async def receive_json(self, content, **kwargs):
        await super().receive_json(content, **kwargs)
        self.waiting_list[self.channel_name] = self.scope['user']
        user_cnt = len(self.waiting_list)

        await self.send_waiting_list()

        if user_cnt == 4:
            channel_names = list(self.waiting_list.keys())
            message = {
                'type': 'send_room_id',
                'room_id': str(uuid.uuid4()),
                'user_ids': list(
                    map(lambda channel_name: self.waiting_list[channel_name]['id'], channel_names)),
            }
            table = await self.create_tournament_table(message['user_ids'])
            GameServerConsumer.game_manager.playing_tournament[message['room_id']] = [table.id, 1] # id 및 매칭 번호
            for idx, value in enumerate(list(self.waiting_list.keys())):
                if idx == 2:  # 3,4 Player는 개별의 room_id
                    message['room_id'] = str(uuid.uuid4())
                    GameServerConsumer.game_manager.playing_tournament[message['room_id']] = [table.id, 2]
                await self.channel_layer.send(value, message)


    async def disconnect(self, close_code):
        await super().disconnect(close_code)
        self.waiting_list.pop(self.channel_name)
        if close_code is None or close_code // 1000 != 3:  # 커스텀 코드가 아닐 때
            await self.send_waiting_list()

    # 실시간 웨이팅 숫자 전송
    async def send_waiting_list(self):
        user_cnt = len(self.waiting_list)
        for idx, value in enumerate(list(self.waiting_list.keys())):
            message = {
                "type": "send_waiting_number",
                "waiting_number": user_cnt,
            }
            await self.channel_layer.send(value, message)

    async def send_room_id(self, event):
        # room_id, player1_nick, player2_nick, who
        message: dict = event.copy()
        message.pop('type')
        for i in range(0, 4):
            if message['user_ids'][i] == self.scope['user']['id']:
                message['player'] = i + 1
        await self.send_json(message)
        await self.close(3001)

    async def send_waiting_number(self, event):
        await self.send_json(event)

    @database_sync_to_async
    def create_tournament_table(self, player_list):
        table: TournamentTable = TournamentTable()
        table.player1 = player_list[0]
        table.player2 = player_list[1]
        table.player3 = player_list[2]
        table.player4 = player_list[3]
        table.winner1 = None
        table.winner2 = None
        table.save()

        return table

class RandomWaitingRoomConsumer(WaitingRoomConsumer):
    waiting_list = {}  # channel_name -> user

    async def receive_json(self, content, **kwargs):
        await super().receive_json(content, **kwargs)
        self.waiting_list[self.channel_name] = self.scope['user']
        user_cnt = len(self.waiting_list)
        if user_cnt == 2:
            channel_names = list(self.waiting_list.keys())
            message = {
                'type': 'send_room_id',
                'room_id': str(uuid.uuid4()),
                'user_ids': list(
                    map(lambda channel_name: self.waiting_list[channel_name]['id'], channel_names)),

            }
            for i in self.waiting_list.keys():
                await self.channel_layer.send(i, message)

    async def disconnect(self, close_code):
        await super().disconnect(close_code)
        self.waiting_list.pop(self.channel_name)

    async def send_room_id(self, event):
        # room_id, player1_nick, player2_nick, who
        message: dict = event.copy()
        message.pop('type')
        if message['user_ids'][0] == self.scope['user']['id']:
            message['player'] = 1
        elif message['user_ids'][1] == self.scope['user']['id']:
            message['player'] = 2
        await self.send_json(message)
        await self.close()


