"""
URL configuration for userManagement project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from friends.views import s2s_FriendshipView, s2s_FriendAddMeview

urlpatterns = [
    path('api/user-management/admin/', admin.site.urls),
    path('api/user-management/accounts/', include('social_login.urls')),
    path('api/user-management/profile/', include('user_profile.urls')),
    path('api/user-management/friends/', include('friends.urls')),
    path('s2sapi/user-management/friends/friendaddme/', s2s_FriendAddMeview.as_view()),
    path('s2sapi/user-management/friends/', s2s_FriendshipView.as_view()),
    path('s2sapi/user-management/user-api/', include('user_api.urls')),
]
