from django.urls import path

from . import consumers
from . import views

websocket_urlpatterns = [
    path("ws/chatting/", consumers.ChattingConsumer.as_asgi()),
]

http_urlpatterns = [
    path("blockedusers/", views.BlockingView.as_view()),
    path("is-online/", views.OnlineView.as_view())
]

http_server_to_server_urlpatterns = [
    path("system-message/", views.SystemMessageView.as_view())
]