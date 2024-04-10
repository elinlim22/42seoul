from django.db import models
from social_login import models as social_login_models


class Friendship(models.Model):
    user = models.ForeignKey(social_login_models.User, on_delete=models.CASCADE, related_name='user')
    friend = models.ForeignKey(social_login_models.User, on_delete=models.CASCADE, related_name='friend')
