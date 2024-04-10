# chatting
drf + channels 를 이용한 실시간 채팅 서버

---
## 환경

- Python 3.11
    - 언어
- Django 5.0.1
    - 백엔드 서버
- Channels 4.0.0
    - HTTP 뿐만 아니라 Websocket, chatbot 등 다양한 프로토콜 지원하는 비동기 처리 패키지
- Daphne 4.0.0
    - ASGI(비동기 서버) application server 패키지
---

## 실행 방법
- python 3.11 환경에서 실행 가정

```shell
pip install -r requirements.txt
python manage.py makemigrations chatting
python manage.py migrate chatting
python manage.py runserver
```
---
## API Specification

## 채팅 웹소켓
### 접속

path : /ws/chatting/ <br>

### 인증

path : /ws/chatting/ (동일)

형식 : json

설명 : 최초 접속 후 token 정보 전송하여 인증
```json
{
  "token" : "<JWT token>"
}
```

응답

형식 : json

설명 : 온라인 상태의 유저 닉네임 제공
```json
{
    "type": "system_message",
    "message": "You have successfully logged in",
    "online_friends": [
        ["<user_id1>",
        "<user_id2>"]
    ],
    "to_id" : "<수신자 id>",
    "time": "<ISO 8601 형식의 시각>"
}
```



### 메시지 전송

path : /ws/chatting/ (동일)

형식 : json

```json
{
    "target_id" : "<대상 id>",
    "message" : "<메시지 내용>"
}
```
## 메시지 응답

```json
{
    "type": "chat_message",
    "message": "<메시지 내용>",
    "from_id" : "<발신자 id>",
    "to_id" : "<수신자 id>",  
    "time": "<ISO 8601 형식의 시각>",
}
```
#### 해당 유저가 존재하지 않거나 오프라인일 때
```json
{
    "type": "system_message",
    "error": "No User or Offline",
    "from_id": "<target_id>",
    "to_id" : "<수신자 id>",
    "time": "<ISO 8601 형식의 시각>"
}
```


---

## 채팅 rest api

----
### 차단 목록 추가

path : /api/chatting/blockedusers/ <br>
method : post <br>
authentication : bearer token

```json
{
    "target_id" : "<차단하고자 하는 유저 id : int, 필수>"
}
```

### 응답 예시

#### 성공
status : 201 created
```json
{
    "target_id": "<차단된 유저 id>"
}
```

#### 인증 실패
status : 401 UNAUTHORIZED


#### 차단할 유저 정보 없음

```json
{
    "target_id": [
        "해당 id가 존재하지 않습니다."
    ]
}
```
----
### 차단 해제 

path : /api/chatting/blockedusers/ <br>
method : delete <br>
authentication : bearer token

```json
{
    "target_id" : "<차단하고자 하는 유저 id : int, 필수>"
}
```

### 응답 예시

#### 성공
status : 200 OK

#### 인증 실패
status : 401 UNAUTHORIZED

---
### 차단 목록 조회
---
#### 전부 조회
path: /api/chatting/blockedusers/ <br>
method : GET

응답: json list

```json
[
    {
      "id" : "<차단된 id>"
    },
    //...
]
```
---
#### 한 유저만 조회
path: /blockedusers/?target_id=<차단 조회할 유저 id> <br>
method : GET

응답: json <br>

status : 200 OK
```json
{
    "is_blocked": <차단인지 아닌지 : boolean>
}
```

status : 404 NOT FOUND <br>
해당 유저 닉네임이 없을 때
```json
{
    "detail": "Not found."
}
```

---
### 시스템 메시지

path : /s2sapi/system-message/   
method : POST   
body : json
description : 외부에서 요청이 아닌 시스템 내부에서 요청

```json
{
  "target_id": "<전송하고자 하는 유저 id>",
  "message": "<메시지 내용>"
}
```

토너먼트 메시지 전송 시
```json
{
  "type" : "invite_game",
  "target_id": "<전송하고자 하는 유저 id>",
  "message" : "<메시지 내용>",
  "room_id" : "<uuid room id>"
}
```
   
응답 : json

status : 200 OK
```json
{
    "type": "system_message",
    "from": "admin",
    "message": "<메시지 내용>",
    "to_id" : "<수신자 id>",
    "time": "<ISO 8601 형식의 시각>"
}
```

status : 400 Bad Request   
description : 전송 형식 오류

status : 404 Not Found
description : 해당하는 유저가 없거나 오프라인일 때

---

## 온라인 상태 관련


### 웹소켓에서 실시간 온라인 상태 전송 

응답 : json

설명 : 새로 접속한 친구는 online 보냄, 접속 종료한 친구는 offline
```json
{
    "type": "send_status",
    "from_id": "<상태 업데이트 된 유저 id>",
    "to_id" : "<수신자 id>",
    "status": "<online or offline>",
    "time": "<ISO 8601 형식의 시각>"
}
```

### restapi를 통해 특정 유저 온라인 조회

- path : api/chatting/is-online/?id=<조회할 id>

- method : GET

- 필요 데이터 : 
  - id: query parameter
  - access_token : Authorization header

- 응답 : json

```json
{
    "id": "<user id : int>",
    "is_online":  "<true or false>"
}
```

---

### 게임 초대 메시지

요청 : json

설명 : 초대시 invite, 초대 취소 시 cancel

```json
{
  "target_id": "<초대하고자 하는 대상 id>",
  "type" : "invite_game",
  "status" : "<'invite' or 'cancel'>"
}
```

응답 : json

설명 : 수신자, 발신자 둘 다 보냄.
```json
{
  "type" : "invite_game",
  "from_id": "<수신자 id>",
  "to_id": "<발신자 id>",
  "time": "<ISO 8601 형식의 시각>",
  "room_id": "<uuid 형식>"
}
```

