from rest_framework.views import APIView
from rest_framework import status
from rest_framework.response import Response
from django.http import HttpResponseRedirect
from rest_framework.permissions import AllowAny, IsAuthenticated
from .models import User
from . import utils
from .serializers import MyTokenObtainPairSerializer # access토큰 payload에 nickname추가


class SocialLogin(APIView):
    permission_classes = [AllowAny]
    def get(self, request):
        utils.set_env(request)
        print(utils.LOGIN_URL)
        return Response({
            'login_url': utils.LOGIN_URL
        }, status=status.HTTP_200_OK)


class SocialLoginCallBack(APIView):
    permission_classes = [AllowAny]
    def get(self, request):
        if request.user.is_authenticated:
            return Response({'error': 'already logged in'}, status=status.HTTP_200_OK)
        code = request.GET['code']

        if not code:
            return Response({'error': 'code is required'}, status=status.HTTP_400_BAD_REQUEST)

        access_token = utils.get_access_token(code)
        if not access_token:
            return Response({'error': 'invalid code'}, status=status.HTTP_400_BAD_REQUEST)

        user_info = utils.get_user_info(access_token)
        email = user_info.get('email')
        user = User.objects.filter(email=email).first()

        if not user:
            user = User.objects.create_user(email=email, nickname=utils.generate_new_nickname())
        if user.set_2fa:
            utils.send_verification_email(user, request)

        response = HttpResponseRedirect(utils.FE_URL)
        refresh_token = MyTokenObtainPairSerializer.get_token(user)
        access_token = refresh_token.access_token
        response.set_cookie('access_token', str(access_token))#, httponly=True)

        return response

class EmailVerificationView(APIView):
    permission_classes = [IsAuthenticated]
    def get(self, request):
        verification_code = request.GET['verification_code']
        user = request.user
        if user.email_verification_code == verification_code:
            user.email_verification_code = None
            user.save()
            return HttpResponseRedirect(utils.FE_URL)
        else:
            return Response({'error': 'invalid code'}, status=status.HTTP_400_BAD_REQUEST)
