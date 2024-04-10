from rest_framework import serializers
from django.shortcuts import get_object_or_404
from .models import Friendship
from social_login.models import User

class AddFriendSerializer(serializers.Serializer):
    id = serializers.IntegerField()

    class Meta:
        fields = ['id']

    def save(self, **kwargs):
        for key, value in kwargs.items():
            self.validated_data[key] = value
        return super().save(**kwargs)
    def create(self, validated_data):
        user = self.validated_data.get('user', None)
        friend = User.objects.get(pk=validated_data['id'])
        if user == friend:
            raise serializers.ValidationError({'error': 'You cannot add yourself as a friend'})
        if Friendship.objects.filter(user=user, friend=friend).exists():
            raise serializers.ValidationError({'error': 'You are already friends'})
        friendship = Friendship.objects.create(user=user, friend=friend)
        return friendship

class FriendshipSerializer(serializers.ModelSerializer):
    friend = serializers.CharField(allow_blank=True, required=False)

    class Meta:
        model = Friendship
        fields = ['friend']

    def get_friend_list(self, user):
        friendships = Friendship.objects.filter(user=user)
        friend_list = []
        for friendship in friendships:
            friend_data = {
                'id': friendship.friend.id,
                'nickname': friendship.friend.nickname,
                'profile': friendship.friend.profile
            }
            friend_list.append(friend_data)
        return friend_list

class GetUserFriendSerializer(serializers.ModelSerializer):
    id = serializers.IntegerField(source='user.id', read_only=True)
    class Meta:
        model = Friendship
        fields = ['id']
