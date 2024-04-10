from channels.routing import URLRouter
from django.urls import path, include

from game_server.consumers import GameServerConsumers, WaitingRoomConsumer

sub_url_patterns = [
    path("<uuid:room_id>/", GameServerConsumers.GameServerConsumer.as_asgi()),
    path("local/<uuid:room_id>/", GameServerConsumers.LocalGameServerConsumer.as_asgi()),
    path("waitingroom/random/", WaitingRoomConsumer.RandomWaitingRoomConsumer.as_asgi()),
    path("waitingroom/tournament/", WaitingRoomConsumer.TournamentWaitingRoomConsumer.as_asgi()),
]

websocket_urlpatterns = [
    path("ws/game/", URLRouter(sub_url_patterns)),
]
