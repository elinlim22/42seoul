from rest_framework import serializers
from rest_framework.validators import ValidationError
from .models import *

class GameDataSerializer(serializers.ModelSerializer):
    class Meta(object):
        model = GameDataModel
        fields = ('id', 'user1_id', 'user1_score', 'user2_id',
                  'user2_score', 'match_type', 'created_at')

    def to_representation(self, instance):
        data = super().to_representation(instance)
        if self.context['id'] == data['user2_id']:
            data['user1_id'], data['user2_id'] \
                = data['user2_id'], data['user1_id']
            data['user1_score'], data['user2_score'] \
                = data['user2_score'], data['user1_score']
        return data

