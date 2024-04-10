from django.urls import path
from .views import *

urlpatterns = [
    path('verify/', VerifyUserView.as_view(), name='user_verify'),
    path('update-stat/', UpdateUserGameStatusView.as_view(), name='update_stat')
]