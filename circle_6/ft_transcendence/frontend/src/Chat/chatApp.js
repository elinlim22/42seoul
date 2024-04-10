import {player} from "../app.js";
import {CHAT_API_DOMAIN, CHAT_SERVER_DOMAIN, CHAT_WEBSOCKET} from "../Public/global.js";
import {
    findItemFromFriendList,
    setFriendStatus,
    setupFriendListStatus
} from "../Profile/modalUtils.js";
import {renderSystemChatBox} from "./chatPageUtils.js";
import {closedChatLog, getOpponent, processMessage, processNextMatch, processSystemMessage} from "./chatSocketUtils.js";
import {SOCKET_STATE} from "../Game/SocketApp.js";
import SocketApp from "../Game/SocketApp.js";
import {DOING} from "../Login/player.js";
import {openInfoModal} from "../Game/gameUtils.js";

const CHAT_API = `${CHAT_SERVER_DOMAIN}/${CHAT_API_DOMAIN}`;

class ChatApp {
    constructor(app) {
        this._app = app;
        this._friendsOnline = [];

        const chatSocket = new WebSocket(`${CHAT_WEBSOCKET}/ws/chatting/`);
        this._chatSocket = chatSocket;

        chatSocket.onopen = e => {
            this._send({token: player._token});
        }

        chatSocket.onerror = e => {
            openInfoModal(`Something was wrong .. Error code: ${e.error}`);
        }

        chatSocket.onmessage = async e => {
            const data = JSON.parse(e.data);

            if (data.type === 'system_message') {
                if (data.message === 'You have successfully logged in') {
                    this._friendsOnline = data.online_friends;
                    delete data.online_friends;

                    setupFriendListStatus();
                } else if (data.message === 'Next Match') {
                    const room_id = data.room_id;
                    delete data.room_id;

                    await processNextMatch(this);
                    const socketApp = SocketApp;

                    socketApp.closeGameModal();
                    socketApp.appearBoardModal();
                    socketApp.nextMatch(room_id, data.opponent_id);
                } else if (data.message === 'YOU WIN!') {
                    const socketApp = SocketApp;

                    socketApp.closeGameModal();
                    socketApp.finalWinner();
                } else if (data.error === 'No User or Offline') {
                    // TODO: offline message
                    renderSystemChatBox(this._app, 'Offline User', data.from_id);
                    return;
                }
                await processSystemMessage(this, data);
            } else if (data.type === 'send_status') {
                const friendItem = findItemFromFriendList(this._friendListNode, data.from_id);
                if (friendItem !== undefined) {
                    if (data.status === 'online'){
                        setFriendStatus(friendItem, true);
                        this.setFriendsOnline(data.from_id);
                    } else if (data.status === 'offline') {
                        setFriendStatus(friendItem, false);
                        this.setFriendsOnline(data.from_id, DOING.DELETE);
                    }
                }
            } else if (data.type === 'chat_message') {
                /*
                * {
                *   type: "chat_message",
                *   from: <string>,
                *   from_id: <int>,
                *   to_id: <int>,
                *   message: <string>,
                *   time: <string>
                * }
                * */
                await processMessage(this, data);
            } else if (data.type === 'invite_game') {
                /*
                * type: <string>,
                * from_id: <int>,
                * to_id: <int>,
                * room_id: <string>,
                * time: <string>
                * */
                const opponent = getOpponent(data);
                const userDetail = await player.getUserDetail(opponent);
                data.opponentNickname = userDetail.nickname;

                closedChatLog(opponent, this);
                await processMessage(this, data);

                if (data.status === 'invite' && player.getId() === data.from_id) {
                    closedChatLog(opponent, this);

                    const socketApp = SocketApp;

                    socketApp.inviteGameRoom(data.room_id, [player.getInfo(), userDetail], this);
                }
            }
        }
    }

    async userBlock(id, isBlocked) {
        const data = {target_id: id};
        if (!isBlocked) {
            const res = await player._getServer(`${CHAT_API}/blockedusers/`, 'POST', data);
            if (res.status !== 201) {
                throw {error: res.status};
            }
            this.sendMessage(id, `you are now blocked by ${player.getNickName()} ❤️`);
        } else {
            const res = await player._getServer(`${CHAT_API}/blockedusers/`, 'DELETE', data)
            if (res.status !== 200) {
                throw {error: res.status};
            }
        }
    }

    async isOnline(id) {
        const res = await player._getServer(`${CHAT_API}/is-online/?id=${id}`);
        if (!res.ok) {
            throw {error: res.status};
        }
        return await res.json();
    }

    async isBlocked(id) {
        const res = await player._getServer(`${CHAT_API}/blockedusers/?target_id=${id}`);
        if (!res.ok) {
            throw {error: res.status};
        }
        return await res.json();
    }

    inviteGame(userId) {
        /*
        *   "target_id": "<초대하고자 하는 대상 id>",
        *   "type" : "invite_game",
        *   "status: "invite"
        * */
        this._send({target_id: userId, type: "invite_game", status: 'invite'});
    }

    cancelInviteGame(userId) {
        /*
        *   "target_id": "<초대하고자 하는 대상 id>",
        *   "type" : "invite_game",
        *   "status: "cancel"
        * */
        this._send({target_id: userId, type: "invite_game", status: 'cancel'});
    }

    sendMessage(userId, message) {
        this._send({target_id: userId, message});
    }

    _send(data) {
        if (this.isState() === SOCKET_STATE.OPEN) {
            this._chatSocket.send(JSON.stringify(data));
        }
    }

    setFriendsOnline(id, doing = DOING.ADD) {
        if (doing === DOING.ADD) {
            this._friendsOnline.push(id);
        } else if (doing === DOING.DELETE) {
            this._friendsOnline = this._friendsOnline.filter(userId => userId !== id);
        }
    }

    setFriendListNode(friendListNode) {
        this._friendListNode = friendListNode;
    }

    isState() {
        if (this._chatSocket !== undefined)
            return this._chatSocket.readyState;
        return SOCKET_STATE.CLOSED;
    }

    getApp() {
        return this._app;
    }

    getFriendListNode() {
        return this._friendListNode;
    }

    getFriendsOnline() {
        return this._friendsOnline;
    }

    closeSocket() {
        if (this._chatSocket !== undefined) {
            this._chatSocket.close();
        }
    }
}

export default ChatApp;