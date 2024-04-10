from rest_framework import serializers
from rest_framework.exceptions import ValidationError

from .models import ChattingUser

class BlockingSerializer(serializers.Serializer):
    target_id = serializers.IntegerField()

    def validate_target_id(self, value):
        if ChattingUser.objects.filter(id=value).exists():
            return value
        else:
            raise ValidationError("해당 id가 존재하지 않습니다.")


class BlockedUsersSerializer(serializers.ModelSerializer):
    class Meta:
        model = ChattingUser
        fields = ['id']

class SystemMessageSerializer(serializers.Serializer):
    target_id = serializers.IntegerField()
    message = serializers.CharField()
    type = serializers.CharField(required=False)
    room_id = serializers.CharField(required=False)
    opponent_id = serializers.IntegerField(required=False)

class OnlineUsersSerializer(serializers.ModelSerializer):
    class Meta:
        model = ChattingUser
        fields = ['id', 'is_online']



