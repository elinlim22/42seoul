from django.urls import path
from . import views

# localhost:8000/friends/
urlpatterns = [
    path('', views.FriendshipView.as_view(), name='friend'),
]
