"""
ASGI config for config project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/4.2/howto/deployment/asgi/
"""

import os

from django.core.asgi import get_asgi_application
django_asgi_app = get_asgi_application()

from channels.auth import AuthMiddlewareStack
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.security.websocket import AllowedHostsOriginValidator
import chatting.routing

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'config.settings')

application = ProtocolTypeRouter(
    {
        "http": django_asgi_app,
        "websocket": URLRouter(chatting.routing.websocket_urlpatterns)
        # "websocket": AllowedHostsOriginValidator(
        #     AuthMiddlewareStack(URLRouter(chatting.routing.websocket_urlpatterns))
        #     # URLRouter(chat.routing.websocket_urlpatterns)
        # )
    }
)
