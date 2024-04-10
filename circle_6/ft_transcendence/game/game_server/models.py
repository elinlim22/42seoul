from django.db import models

# Create your models here.
class TournamentTable(models.Model):
    player1 = models.IntegerField()
    player2 = models.IntegerField()
    player3 = models.IntegerField()
    player4 = models.IntegerField()

    winner1 = models.IntegerField(null=True)
    winner2 = models.IntegerField(null=True)
