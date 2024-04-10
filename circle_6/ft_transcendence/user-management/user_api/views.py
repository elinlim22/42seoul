from rest_framework import status
from rest_framework.response import Response
from rest_framework.views import APIView
from social_login.serializers import UserSerializer
from rest_framework.permissions import AllowAny
from social_login.models import User

class VerifyUserView(APIView):
    def get(self, request):
        try:
            serializers = UserSerializer(request.user)
            return Response(serializers.data, status=status.HTTP_200_OK)
        except Exception as e:
            return Response({'error': str(e)}, status=status.HTTP_400_BAD_REQUEST)

class UpdateUserGameStatusView(APIView):
    permission_classes = [AllowAny]
    def patch(self, request):
        winner = User.objects.get(id=request.data['winner_id'])
        loser = User.objects.get(id=request.data['loser_id'])
        game_type = request.data['game_type']
        winner.increase_win()
        loser.increase_lose()
        if game_type == 'Tournament-First Round':
            loser.change_rank(-20)
        elif game_type == 'Tournament-Final Round':
            winner.change_rank(40)
            loser.change_rank(20)
        return Response(status=status.HTTP_201_CREATED)