import {getInfoJWT} from "./loginUtils.js";
import { USER_MANAGEMENT_DOMAIN, USER_SERVER_DOMAIN, GAME_SERVER_DOMAIN, GAME_API_DOMAIN } from "../Public/global.js";

export const PROFILE_DEFAULT_IMAGE = ['cat', 'bird', 'crocodile', 'deer', 'whale'];
const USER_MANAGEMENT = `${USER_SERVER_DOMAIN}/${USER_MANAGEMENT_DOMAIN}`;
const GAME_API = `${GAME_SERVER_DOMAIN}/${GAME_API_DOMAIN}`;

export const USER_STATUS = {
    "DOSE_NOT_EXIST": 0,
    "NOT_AUTHORIZED": 1,
    "AUTHORIZED": 2
}

export const DOING = {
    "ADD": 0,
    "UPDATE": 1,
    "DELETE": 2,
}

class Player {
    constructor() {
        this._status = USER_STATUS.DOSE_NOT_EXIST;
    }

    async whoAmI(token = this._token) {
        this._token = token;

        if (token === undefined) {
            this._status = USER_STATUS.DOSE_NOT_EXIST;
            return ;
        }

        const { user_id } = getInfoJWT(this._token);
        this._id = user_id;

        const res = await this._getServer(`${USER_MANAGEMENT}/profile/?id=${user_id}`);
        if (res.status === 200) {
            this._status = USER_STATUS.AUTHORIZED;

            const {
                nickname,
                profile,
                status_message,
                win,
                lose,
                rank,
                set_2fa
            } = await res.json();

            this._nickName = nickname;
            this._profile = profile;
            this._status_message = status_message;
            this._win = win;
            this._lose = lose;
            this._rank = rank;
            this._set_2fa = set_2fa;
        } else if (res.status === 403) {
            this._status = USER_STATUS.NOT_AUTHORIZED;
        }
    }

    async send2FACode(code) {
        const { status } = await this._getServer(`${USER_MANAGEMENT}/accounts/email_verification/?verification_code=${code}`);
        if (status !== 200) {
            throw {error: status};
        }
        this._status = USER_STATUS.AUTHORIZED;
    }

    async getFriendList() {
        this._friendList = [];
        const res = await this._getServer(`${USER_MANAGEMENT}/friends/`);
        if (res.status !== 200) {
            throw {error: res.status};
        }
        const data = await res.json();
        data.forEach(friend => this._friendList.push(friend));
        // friendList 형식 : [{id: <int>, nickname: <string>, profile: <string>},]
        return this._friendList;
    }

    async setProfile(data) {
        const { status } = await this._getServer(`${USER_MANAGEMENT}/profile/`, 'PATCH', data);

        if (status !== 200) {
            throw {error: status};
        }
        this._profile = data.profile_to;
        this._nickName = data.nickname_to;
        this._status_message = data.status_message_to;
    }

    async getUserDetail(id) {
        const res = await this._getServer(`${USER_MANAGEMENT}/profile/?id=${id}`);

        /* DetailData: {
            nickname: <string>,
            profile: <string>,
            status_message: <string>,
            win: <int>,
            lose: <int>,
            rank: <int>,
            is_friend: <boolean>
        } */
        if (res.status !== 200) {
            throw {'error': res.status};
        }
        return await res.json();
    }

    async friend(id, doing = DOING.ADD) {
        const method = doing === DOING.ADD? 'POST' : 'DELETE';

        const data = await this._getServer(`${USER_MANAGEMENT}/friends/`, method, {id: id});

        if (!data.ok) {
            throw {error: data.status};
        }
    }

    async searchUser(keyword) {
        const data = await this._getServer(`${USER_MANAGEMENT}/profile/search/?keyword=${keyword}`);

        if (data.status !== 200) {
            /*
            * [{id: <int>, nickname: <string>, profile: <string>}]
            */
            throw {error: data.status};
        }
        return await data.json();
    }

    async getMatchHistoryById(userId) {
        const data = await this._getServer(`${GAME_API}/game-data/history/?id=${userId}`);
        /*
        * gameHistory : {
        *   id: <int>,
        *   match_type: <string>,
        *   user1_id: <int>,
        *   user2_id: <int>,
        *   user1_score: <int>,
        *   user2_score: <int>,
        *   created_at: <date>
        * }
        * */
        if (!data.ok) {
            throw {error: data.status};
        }
        return await data.json();
    }

    async getRankerList() {
        const data = await this._getServer(`${USER_MANAGEMENT}/profile/ranker/`);

        if (!data.ok) {
            throw {error: data.status};
        }
        return await data.json();
    }

    async _getServer(url, method = 'GET', bodyData) {
        let sendData = {
            method: method,
            headers: {
                'Authorization': `Bearer ${this._token}`
            }
        }
        if (bodyData) {
            sendData.body = JSON.stringify(bodyData);
            sendData.headers['Content-Type'] = 'application/json';
        }
        return await fetch(url, sendData);
    }

    getId() {
        return this._id;
    }
    getNickName() {
        return this._nickName;
    }
    getProfile() {
        return this._profile;
    }
    getStatusMessage() {
        return this._status_message;
    }
    getWin() {
        return this._win;
    }
    getLose() {
        return this._lose;
    }
    getRank() {
        return this._rank;
    }
    getSet2fa() {
        return this._set_2fa;
    }
    getStatus() {
        return this._status;
    }
    getChatApp() {
        return this._chatApp;
    }
    getInfo() {
        return {
            id: this._id,
            nickname: this._nickName,
            profile: this._profile,
            status_message: this._status_message,
            win: this._win,
            lose: this._lose,
            rank: this._rank,
            set_2fa: this._set_2fa,
            status: this._status
        };
    }

    setChatApp(chatApp) {
        this._chatApp = chatApp;
    }

    forgetMe() {
        this._status = USER_STATUS.DOSE_NOT_EXIST;
        this._token = undefined;
        this._id = undefined;
        this._nickName = undefined;
        this._profile = undefined;
        this._status_message = undefined;
        this._win = undefined;
        this._lose = undefined;
        this._rank = undefined;
        this._set_2fa = undefined;

        if (this._chatApp !== undefined) {
            this._chatApp.closeSocket();
            this._chatApp = undefined;
        }
    }
}

export default new Player();
