from rest_framework import status
from rest_framework.response import Response
from rest_framework.views import APIView
from django.shortcuts import get_object_or_404

from chatting import serializers
from .authentication import authenticate
from .models import ChattingUser
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync
from .serializers import OnlineUsersSerializer

class BlockingView(APIView):
    def post(self, request):
        # 임시 인증
        user_data = authenticate(request.headers.get('Authorization').split()[1])
        if user_data is None:
            return Response(status=status.HTTP_401_UNAUTHORIZED)

        serializer = serializers.BlockingSerializer(data=request.data)
        if serializer.is_valid():
            data = serializer.validated_data
            user = ChattingUser.objects.get(id=user_data['id'])
            blocked_user = ChattingUser.objects.get(id=data['target_id'])

            # 차단 안되어 있는 경우만 추가
            if not user.blocked_users.contains(blocked_user):
                user.blocked_users.add(blocked_user)

            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    def get(self, request):
        user_data = authenticate(request.headers.get('Authorization').split()[1])
        if user_data is None:
            return Response(status=status.HTTP_401_UNAUTHORIZED)
        user = ChattingUser.objects.get(id=user_data['id'])
        target_id = request.GET.get('target_id')

        # query parameter 없을 때 - 전부 조회
        if target_id is None:
            serializer = serializers.BlockedUsersSerializer(user.blocked_users, many=True)
            return Response(serializer.data, status=status.HTTP_200_OK)
        # query parameter 있을 때 - 한명만 조회
        else:
            data = {
                'is_blocked': False
            }
            if user.blocked_users.contains(get_object_or_404(ChattingUser, id=target_id)):
                data['is_blocked'] = True

            return Response(data, status=status.HTTP_200_OK)

    def delete(self, request):
        user_data = authenticate(request.headers.get('Authorization').split()[1])
        if user_data is None:
            return Response(status=status.HTTP_401_UNAUTHORIZED)

        serializer = serializers.BlockingSerializer(data=request.data)
        if serializer.is_valid():
            data = serializer.validated_data
            user = ChattingUser.objects.get(id=user_data['id'])
            blocked_user = ChattingUser.objects.get(id=data['target_id'])

            # 이미 차단된 경우만 제거
            if user.blocked_users.contains(blocked_user):
                user.blocked_users.remove(blocked_user)
                return Response(status=status.HTTP_200_OK)
            else:
                return Response(status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


class SystemMessageView(APIView):
    def post(self, request):
        serializer = serializers.SystemMessageSerializer(data=request.data)
        if serializer.is_valid():
            data = serializer.validated_data
            target_id = data['target_id']
            message = data['message']
            target_user = ChattingUser.objects.filter(id=target_id).first()
            if target_user is None or target_user.is_online is False:
                return Response(status=status.HTTP_404_NOT_FOUND)
            else:
                channel_layer = get_channel_layer()
                message_to_send = {
                    'type': 'system_message',
                    'from': 'admin',
                    'message': message,
                }
                if data.get('type') == 'invite_game' and data.get('room_id') is not None:
                    message_to_send['room_id'] = data['room_id']
                    message_to_send['opponent_id'] = data['opponent_id']

                async_to_sync(channel_layer.send)(target_user.channel_name, message_to_send)
                return Response(status=status.HTTP_200_OK)
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class OnlineView(APIView):
    def get(self, request):
        try:
            user_data = authenticate(request.headers.get('Authorization').split()[1])
        except Exception as e:
            return Response({'error': 'Authorization header is required'}, status=status.HTTP_401_UNAUTHORIZED)
        if user_data is None:
            return Response(status=status.HTTP_401_UNAUTHORIZED)
        id = request.query_params.get('id')
        if not id:
            return Response({'error': 'id parameter is required'}, status=status.HTTP_400_BAD_REQUEST)
        query = ChattingUser.objects.filter(id=id)
        if query.count() == 0:
            return Response({'error': 'User not found'}, status=status.HTTP_404_NOT_FOUND)

        serializer = OnlineUsersSerializer(query.first())
        return Response(serializer.data, status=status.HTTP_200_OK)