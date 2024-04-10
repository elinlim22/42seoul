from rest_framework import serializers
from social_login.serializers import UserSerializer
from social_login.models import User
from friends.models import Friendship
import re
from django.utils.html import conditional_escape

class ProfileSerializer(UserSerializer):
    profile_to = serializers.CharField(source='profile')
    nickname_to = serializers.CharField(source='nickname', max_length=15)
    status_message_to = serializers.CharField(source='status_message', max_length=50, allow_blank=True)
    set_2fa_to = serializers.BooleanField(source='set_2fa')

    class Meta:
        model = User
        fields = ['profile_to', 'nickname_to', 'status_message_to', 'set_2fa_to']

    def get_user_info(self, user, friend):
        info = {
            'id': friend.id,
            'nickname': friend.nickname,
            'profile': friend.profile,
            'status_message': friend.status_message,
            'win': friend.win,
            'lose': friend.lose,
            'rank': friend.rank,
        }
        if user == friend:
            info['set_2fa'] = friend.set_2fa
        else:
            info['is_friend'] = Friendship.objects.filter(user=user.id, friend=friend.id).exists()
        return info

    def update(self, user, validated_data):
        fields = ['profile', 'nickname', 'status_message', 'set_2fa']
        for field in fields:
            value = validated_data.get(field, getattr(user, field))
            if value != getattr(user, field):
                if field == 'nickname':
                    value = check_nickname(value)
                value = conditional_escape(value)
                setattr(user, field, value)
        user.save()
        return user

def check_nickname(nickname):
    if re.match(r"^User\d*$", nickname, re.IGNORECASE):
        raise serializers.ValidationError({'error': 'Please avoid using default nickname'})
    if "\n" in nickname:
        raise serializers.ValidationError({'error': 'Nickname should not contain newline character'})
    if User.objects.filter(nickname=nickname).exists():
        raise serializers.ValidationError({'error': 'This nickname is already in use'})
    return nickname

class RankerUserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ["id", "nickname", "profile"]
