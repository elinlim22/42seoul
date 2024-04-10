# Game Server
- websocket을 이용한 Pong 게임 서버

---

## 

게임 시작 요청 -> uuid를 통해 링크 생성 -> 최대 2명 접속 가능한 웹소켓 그룹 생성
-> 2명 접속완료 시 게임 시작 -> 실시간 공 및 패들 위치 전송 

점수 
- 벽에 닿으면 득점 메시지 전송 후 위치 초기화


좌표
- 공 위치 x,y
- 공 방향 벡터
- 패들 위치 x1, x2
---

## API Specification

### 게임 기본 설정(추후 수정)

```python
# settings
self.map_width = 720
self.map_height = 480
self.ball_speed = 5
self.move_speed = 5
self.winning_score = 5
self.paddle_height = 50
self.paddle_speed = 5
```

### 멀티 게임 1대1

#### 대기방
> Protocol : Websocket  
> Path : `/ws/game/waitingroom/random/`
#### 인증

> description : 소켓 접속 후
```json
{
  "token" : "<token 정보>"
}
```

#### 방 정보 전송

```json
{
    "room_id": "<uuid4>",
    "user_ids": [
        "<player1 id>",
        "<player2 id>"
    ],
    "player": "<1 or 2>"
}
```

#### 접속
> Protocol : Websocket   
> Path : `/ws/game/<uuid>/`   

#### 인증

> description : 소켓 접속 후
```json
{
  "token" : "<token 정보>"
}
```
해당 json 전송 해야 함.   
##### 인증 실패 시
```json
{
  'type':"send_system_message",
  'message': 'Someone Unauthorized'
}
```
> 정상적으로 플레이어가 두명 다 인증 성공 시 게임준비 완료
> 게임 준비 완료 시 각 플레이어에게 player 정보 제공
> 게임시작 전까지 10초 카운트
```json
{
    "type": "send_system_message",
    "message": "Game Ready",
    'counter': <10~1>,
    "player": <1 or 2>
}
```
> 게임시작 메시지 전송
```json
{
    "type": "send_system_message",
    "message": "Game Start"
}
```


#### 게임 상태 응답
```json
{
    "ball_coords": [
        <공 x좌표>,
        <공 y좌표>
    ],
    "player1_coords": [
        <p1 paddle x좌표>,
        <p1 paddle y좌표>
    ],
    "player2_coords": [
        <p2 paddle x좌표>,
        <p2 paddle y좌표>
    ],
    "type": "send_game_status"
}
```

#### paddle 움직임 전송
```json
{
    "move" : "<up 또는 down 또는 stop>"
}
```
description : keydown-> up or down, keyup -> stop

#### 게임 종료 응답
```json
{
  "type": "send_system_message",
  "message": "Game End",
  "score": [<player1:int>, <player2:int>]
}
```

### 토너먼트 플로우 
1. /ws/game/waitingroom/tournament/ 에 웹소켓 접속 및 인증
```json
{
  "token": "<token 정보>"
}
```
1-1. 대기자 수 실시간 전송
```json
{
  "type": "send_waiting_number",
  "waiting_number": <1, 2, 3 or 4>
}
```
2. 4명이 모이면 room_id 반환 및 종료
```json
{
  "room_id": "<uuid4>",
  "user_ids": ["<player1 id>","<player2 id>","<player3 id>","<player4 id>"],
  "player" : "<1,2,3 or 4>"
}
```
3. 해당 room_id로 2명씩 게임 플레이
4. 게임 종료 시 chatting을 통해 다음 게임 정보 전송
```json
{
    "type": "system_message",
    "from": "admin",
    "message": "Next Match",
    "room_id" : "<room id>",
    "time": "<ISO 8601 형식의 시각>",
    "to_id": "<수신자 id>",
    "opponent_id" : "<결승 상대id>"
}
```
5. 해당 room id 로 게임 후 최종 승자 결정되면 우승자에게 chatting 전송
```json
{
    "type": "system_message",
    "from": "admin",
    "message": "YOU WIN!",
    "time": "<ISO 8601 형식의 시각>",
    "to_id": "<수신자 id>"
}
```

---
## Local play
#### 접속

#### 접속
> Protocol : Websocket   
> Path : `/ws/game/local/<uuid>/`   

#### 인증

> description : 소켓 접속 후
```json
{
  "token" : "<token 정보>"
}
```

> 인증 후 바로 게임 시작
```json
{
    "type": "send_system_message",
    "message": "Game Start"
}
```

#### 게임 상태   
> - 위와 동일
> 
> 
#### paddle 움직임 전송
```json
{
    "player" : "<1 or 2>",
    "move" : "<up 또는 down 또는 stop>"
}
```

#### 게임 종료 응답
> 위와 동일