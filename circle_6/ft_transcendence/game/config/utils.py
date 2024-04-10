from rest_framework import exceptions

def get_token(request):
    header = request.META.get('HTTP_AUTHORIZATION')
    if header is None:
        raise exceptions.AuthenticationFailed('Missing authorization header')
    token = header.split()[1]

    return token