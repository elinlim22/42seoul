# game
drf + channel를 이용한 실시간 ping-pong game server

# 실행 방법
```shell
pip install -r requirements.txt
python manage.py makemigrations game_data game_server
python manage.py migrate game_data
python manage.py migrate game_server
python manage.py runserver
```

***
# game_data
***
## 게임 데이터 요청 방법
#### Http Method: GET
#### Path: /game/histroy/?id="대상 id"
***
## 응답예시
#### 형식: Json
***
### 성공
#### status code: 200 OK
<pre>
<code>
{
  "id": "< 게임 데이터 id>",
  "user1_id": "<요청 유저의 id>"
  "user1_nickname": "<요청 유저의 닉네임>",
  "user1_score": "<요청 유저의 점수>",
  "user2_id": "<유저1 상대의 id>"
  "user2_nickname": "<유저1 상대의 닉네임>",
  "user2_score": "<유저1 상대의 점수>",
  "match_type": "<랜덤인지 토너먼트인지 type>",
  "created_at": "<게임이 끝난 날짜와 시간>",
}
</code>
</pre>
***
### 실패
#### status code: 404 Not Found
<pre>
<code>
{
  "error": "data not found"
}
</code>
</pre>
***
## 유저 인증, 권한 확인
****
### 사용법
<pre>
<code>
verify_user.py의 verifying_user를 import

view나 인증이 필요한 작업전에 
    try:
        verifying_user(get_token(request))
        authenticate 후 처리할 로직들 ...
</code>
</pre>
***
### 성공
해당 USER의 nickname
***
### 실패
NONE 반환