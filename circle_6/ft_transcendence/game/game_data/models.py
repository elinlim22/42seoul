from django.db import models
from django.utils import timezone

# Create your models here.

class GameDataModel(models.Model):
    created_at = models.DateTimeField()
    user1_id = models.IntegerField(default=0)
    user2_id = models.IntegerField(default=0)
    user1_score = models.IntegerField(default=0)
    user2_score = models.IntegerField(default=0)
    match_type = models.CharField(max_length=30, null=False, blank=False)

    class Meta:
        db_table = 'game_data'

    @staticmethod
    def create_match_and_save_game(game_info: dict):
        user1_id = game_info['user1_id']
        user2_id = game_info['user2_id']
        user1_score = game_info["user1_score"]
        user2_score = game_info["user2_score"]
        match_type = game_info["match_type"]

        GameDataModel.objects.create(
            created_at=timezone.now(),
            user1_id=user1_id,
            user2_id=user2_id,
            user1_score=user1_score,
            user2_score=user2_score,
            match_type=match_type,
        )