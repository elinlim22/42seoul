from rest_framework.permissions import BasePermission
from rest_framework import status
from rest_framework.exceptions import PermissionDenied


class IsAuthenticatedAndActive(BasePermission):
    def has_permission(self, request, view):
        if (request.user.is_authenticated and request.user.set_2fa
                and request.user.email_verification_code):
            raise PermissionDenied(detail='User is not active')
        return request.user and request.user.is_authenticated
