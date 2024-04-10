from config.verifying_user import verifying_user
# 인증 서버에서 인증 받아 오는 함수,
from channels.db import database_sync_to_async

async def authenticate(token):
    try:
        return await database_sync_to_async(verifying_user)(token)
    except Exception as e:
        print(e)
        return None

