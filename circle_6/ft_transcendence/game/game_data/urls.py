from django.urls import path
from .views import *

urlpatterns = [
    path('history/', GameDataListView.as_view(), name='match_history'),
]
