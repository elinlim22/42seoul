import requests, os
from rest_framework import exceptions


def verifying_user(access_token):
    headers = {'Authorization': 'Bearer ' + access_token}
    response = requests.get(os.environ.get('USER_MANAGEMENT_SERVER') + f's2sapi/user-management/user-api/verify/', headers=headers)

    if response.status_code != 200:
        raise exceptions.AuthenticationFailed('token is invalid')
    return response.json()
