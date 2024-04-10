from django.db import models
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager, PermissionsMixin
from .utils import random_profile

DEFAULT = False
UPLOAD = True

class CreateUser(BaseUserManager):
    def create_user(self, email, nickname, **kwargs):
        if not nickname:
            raise ValueError('Please write your nickname')
        user = self.model(
            email=self.normalize_email(email),
            nickname=nickname,
            profile=random_profile(),
        )
        user.save(using=self._db)
        return user


class User(AbstractBaseUser, PermissionsMixin):
    email = models.EmailField(max_length=30, unique=True, null=False, blank=False)
    nickname = models.CharField(
        max_length=15,
        unique=True,
    )
    profile = models.TextField(default="cat")
    status_message = models.CharField(default='', max_length=50, null=False, blank=True)
    email_verification_code = models.CharField(max_length=6, null=True, blank=True)
    set_2fa = models.BooleanField(default=False)
    win = models.IntegerField(default=0)
    lose = models.IntegerField(default=0)
    rank = models.IntegerField(default=0)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['nickname', ]
    objects = CreateUser()

    def increase_win(self):
        self.win += 1
        self.save()
    def increase_lose(self):
        self.lose += 1
        self.save()
    def change_rank(self, point):
        if self.rank + point >= 0:
            self.rank += point
            self.save()
    def __str__(self):
        return self.email
