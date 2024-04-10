from django.urls import path
from .views import *

# localhost:8000/profile/
urlpatterns = [
    path('', UserProfileView.as_view(), name='user_profile'),
    path('search/', SearchUserView.as_view(), name='user_search'),
    path('ranker/', GameRankerView.as_view(), name='ranker_user_profile'),
]
