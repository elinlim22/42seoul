import os
import uuid

from channels.generic.websocket import AsyncJsonWebsocketConsumer
from channels.db import database_sync_to_async
from .models import ChattingUser
from .authentication import authenticate
import datetime
import requests
from asgiref.sync import sync_to_async
from django.utils.html import escape


class ChattingConsumer(AsyncJsonWebsocketConsumer):
    async def connect(self):
        await self.accept()

    async def disconnect(self, close_code):
        # DB에서 오프라인
        if await self.is_auth():
            await self.update_user_status_disconnect()
            await self.broadcast_status("offline")

    async def receive_json(self, content, **kwargs):
        # 인증 확인
        if not await self.is_auth():
            if 'token' in content:
                user_data = await sync_to_async(authenticate)(content['token'])
                if user_data is None:
                    await self.close(3401)
                    return
                self.user_id = user_data['id']

                # DB에 최초 접속이면 추가, 기존이면 온라인 갱신 및 채널 갱신.
                await self.update_user_status_connect()
                await self.broadcast_status("online")
                await self.send_successful_login()
                return
            else:
                await self.close(3401)
                return

        # 인증 후 일반 메시지
        target_id = content['target_id']
        target_channel_name = await self.get_target_channel_by_id(target_id)
        if target_channel_name is None:
            message = {
                "type": "system_message",
                "error": "No User or Offline",
                "from_id": target_id,
            }
            await self.system_message(message)
            return

        if 'message' in content.keys():
            data = {
                "type": "chat_message",
                "message": content['message'],
                "from_id": self.user_id,
            }
            await self.channel_layer.send(target_channel_name, data)  # 대상에게 보냄
            data['to_id'] = int(target_id)
            await self.chat_message(data)  # 자기자신에게도 보냄
            return

        if 'type' in content.keys() and content['type'] == 'invite_game':
            data = {
                "type": "invite_game",
                "from_id": self.user_id,
            }
            if 'status' in content.keys() and content['status'] == 'invite':
                data['room_id'] = str(uuid.uuid4())
                data['status'] = content['status']
            elif 'status' in content.keys() and content['status'] == 'cancel':
                data['status'] = content['status']
            else:
                print('wrong syntax in invite_game')
                return

            await self.channel_layer.send(target_channel_name, data)
            data['to_id'] = int(target_id)
            await self.invite_game(data)
            return

    # my function

    async def chat_message(self, event):
        # 시간 데이터 추가
        event['time'] = str(datetime.datetime.now().isoformat())

        # 대상 id 추가
        if 'to_id' not in event.keys():
            event['to_id'] = self.user_id

        event['message'] = escape(event['message'])

        # 차단 조회 후 전송
        from_id = event['from_id']
        is_blocked = await self.is_blocked_user(from_id)
        if not is_blocked:
            await self.send_json(event)

    async def system_message(self, event):
        event['time'] = str(datetime.datetime.now().isoformat())
        event['to_id'] = self.user_id

        await self.send_json(event)

    async def send_successful_login(self):
        self.friends_list = await self.get_friends_list()
        online_friends_list = await self.extract_online_friends()

        message = {
            "type": "system_message",
            "message": "You have successfully logged in",
            "online_friends": online_friends_list,
        }
        await self.system_message(message)

    async def invite_game(self, event):
        event['time'] = str(datetime.datetime.now().isoformat())
        if 'to_id' not in event.keys():
            event['to_id'] = self.user_id

        if not await self.is_blocked_user(event['from_id']):
            await self.send_json(event)

    @database_sync_to_async
    def extract_online_friends(self):
        users: list = ChattingUser.objects.all()
        friends_list = self.friends_list
        friends_id_list = []

        for friend in friends_list:
            friends_id_list.append(friend['id'])
        online_user = []

        for user in users:
            if user.id in friends_id_list and user.is_online:
                online_user.append(user.id)

        return online_user

    async def send_status(self, event):
        event['time'] = str(datetime.datetime.now().isoformat())
        event['to_id'] = self.user_id

        await self.send_json(event)

    async def broadcast_status(self, online_or_offline: str):
        friends_added_me_list = await self.get_friends_added_me_list()
        for friend in friends_added_me_list:
            message = {
                "type": "send_status",
                "from_id": self.user_id,
                "status": online_or_offline,
            }
            target_user: ChattingUser = await database_sync_to_async(
                ChattingUser.objects.filter(id=friend['id']).first)()
            if target_user is not None and target_user.is_online is True:
                await self.channel_layer.send(target_user.channel_name, message)

    async def get_friends_list(self):
        url = os.environ.get('USER_MANAGEMENT_URL')
        res = requests.get(url + f's2sapi/user-management/friends/?id={self.user_id}')
        if res.status_code != 200:
            return None
        return res.json()

    async def get_friends_added_me_list(self):
        url = os.environ.get('USER_MANAGEMENT_URL')
        res = requests.get(url + f's2sapi/user-management/friends/friendaddme/?id={self.user_id}')
        if res.status_code != 200:
            return None
        return res.json()

    @database_sync_to_async
    def get_target_channel_by_id(self, target_id):
        query = ChattingUser.objects.filter(id=target_id)
        if query.count() == 0:
            return None
        user = query.first()
        if not user.is_online:
            return None

        return user.channel_name

    @database_sync_to_async
    def update_user_status_connect(self):
        query = ChattingUser.objects.filter(id=self.user_id)
        if query.count() == 0:
            ChattingUser.objects.create(id=self.user_id, channel_name=self.channel_name,
                                        is_online=True)
        else:
            user = query.first()
            user.is_online = True
            user.channel_name = self.channel_name
            user.save()

    @database_sync_to_async
    def update_user_status_disconnect(self):
        query = ChattingUser.objects.filter(id=self.user_id)
        user = query.first()
        user.is_online = False
        user.channel_name = None
        user.save()

    @database_sync_to_async
    def is_blocked_user(self, from_id):
        from_user = ChattingUser.objects.get(id=from_id)
        if ChattingUser.objects.get(id=self.user_id).blocked_users.contains(from_user):
            return True
        else:
            return False

    @database_sync_to_async
    def is_auth(self):
        query = ChattingUser.objects.filter(channel_name=self.channel_name)
        if query.count() == 0:
            return False
        return True