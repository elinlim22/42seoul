from rest_framework.views import APIView
from rest_framework import status
from rest_framework.response import Response
from . import serializers
from social_login.models import User
from django.utils.datastructures import MultiValueDictKeyError
from rest_framework.permissions import AllowAny

from .models import Friendship


class FriendshipView(APIView):
    # 사용자의 친구목록 반환

    def get(self, request):
        user = request.user
        serializer = serializers.FriendshipSerializer()
        friend_list = serializer.get_friend_list(user)
        return Response(friend_list, status=status.HTTP_200_OK)

    # 친구 추가
    def post(self, request):  # 받는 데이터(Body): id
        try:
            user = request.user
            serializer = serializers.AddFriendSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save(user=user)
                return Response(
                    {'success': f"{user.id} added {serializer.validated_data['id']} as a friend"},
                    status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        except User.DoesNotExist:
            return Response({'error': f"id {serializer.validated_data['id']} not found"},
                            status=status.HTTP_404_NOT_FOUND)
    # 친구 삭제
    def delete(self, request):  # 받는 데이터(Body): id
        try:
            user = request.user
            serializer = serializers.AddFriendSerializer(data=request.data)
            if serializer.is_valid():
                friend = serializer.validated_data['id']
                friendship = Friendship.objects.get(user=user, friend=friend)
                friendship.delete()
                return Response({'success': f'{user.id} deleted id {friend}'}, status=status.HTTP_200_OK)
        except Friendship.DoesNotExist:
            return Response({'error': f"friend {friend} not found"},
                            status=status.HTTP_404_NOT_FOUND)

class s2s_FriendshipView(APIView):
    permission_classes = [AllowAny]

    def get(self, request):
        try:
            user_id = request.GET['id']
            user = User.objects.get(id=user_id)
            serializer = serializers.FriendshipSerializer()
            friend_list = serializer.get_friend_list(user)
            return Response(friend_list, status=status.HTTP_200_OK)
        except User.DoesNotExist:
            return Response({'error': "user not found"}, status=status.HTTP_404_NOT_FOUND)
        except MultiValueDictKeyError as e:
            return Response({'error': '"id" data is required'}, status=status.HTTP_400_BAD_REQUEST)

class s2s_FriendAddMeview(APIView):
    permission_classes = [AllowAny]

    def get(self, request):
        try:
            user_id = request.GET['id']
            friendship = Friendship.objects.filter(friend_id=user_id)
            serializer = serializers.GetUserFriendSerializer(friendship, many=True)
            return Response(serializer.data, status=status.HTTP_200_OK)
        except MultiValueDictKeyError as e:
            return Response({'error': '"id" data is required'}, status=status.HTTP_400_BAD_REQUEST)