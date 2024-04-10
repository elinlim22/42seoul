from . import models
from django.core.mail import send_mail
import os, requests
import random

LOGIN_URL, USER_INFO_URL, TOKEN_URL, REDIRECT_URI, CLIENT_ID, CLIENT_SECRET, FE_URL = \
    None, None, None, None, None, None, None

def set_env(request):
    global LOGIN_URL, USER_INFO_URL, TOKEN_URL, REDIRECT_URI, CLIENT_ID, CLIENT_SECRET, FE_URL
    path = request.path
    FE_URL = os.environ.get('FE_URL')
    if 'google' in path:
        LOGIN_URL = (
                'https://accounts.google.com/o/oauth2/v2/auth' +
                '?client_id=' + os.environ.get('GOOGLE_CLIENT_ID') +
                '&redirect_uri=' + os.environ.get('GOOGLE_URI') +
                '&response_type=code' +
                '&scope=email%20profile'
        )
        USER_INFO_URL = 'https://www.googleapis.com/oauth2/v1/tokeninfo'
        TOKEN_URL = 'https://oauth2.googleapis.com/token'
        REDIRECT_URI = os.environ.get('GOOGLE_URI')
        CLIENT_ID = os.environ.get('GOOGLE_CLIENT_ID')
        CLIENT_SECRET = os.environ.get('GOOGLE_SECRET')
    elif '42intra' in path:
        LOGIN_URL = (
                os.environ.get('INTRA_API_URL') + '/oauth/authorize' +
                '?client_id=' + os.environ.get('INTRA_CLIENT_ID') +
                '&redirect_uri=' + os.environ.get('INTRA_URI') +
                '&response_type=code'
        )
        USER_INFO_URL = os.environ.get('INTRA_API_URL') + '/v2/me'
        TOKEN_URL = os.environ.get('INTRA_API_URL') + '/oauth/token'
        REDIRECT_URI = os.environ.get('INTRA_URI')
        CLIENT_ID = os.environ.get('INTRA_CLIENT_ID')
        CLIENT_SECRET = os.environ.get('INTRA_SECRET')


def generate_new_nickname():
    last_record = models.User.objects.last()
    last_id = last_record.id if last_record else None
    return f'User{last_id + 1}' if last_id else 'User1'


def generate_verification_code():
    return ''.join(random.sample('0123456789', 6))

def random_profile():
    default_profiles = ['cat', 'bird', 'deer', 'crocodile', 'whale']
    return random.choice(default_profiles)

def send_verification_email(user, request):
    verification_code = generate_verification_code()

    user.email_verification_code = verification_code
    user.save()

    subject = 'Email Verification'
    message = f'Hello from Pong Beat Makers!\nPlease enter this code to verify your email: {user.email_verification_code}'
    from_email = 'elinlim22@gmail.com'
    recipient_list = [user.email]

    send_mail(subject, message, from_email, recipient_list)


def get_user_info(access_token):
    response = requests.get(USER_INFO_URL + f'?access_token={access_token}')
    if response.status_code == 200:
        return response.json()
    return None


def get_access_token(code):
    data = {
        'grant_type': 'authorization_code',
        'client_id': CLIENT_ID,
        'client_secret': CLIENT_SECRET,
        'code': code,
        'redirect_uri': REDIRECT_URI,
    }
    response = requests.post(TOKEN_URL, data=data)
    if response.status_code == 200:
        return response.json().get('access_token')
    return None
