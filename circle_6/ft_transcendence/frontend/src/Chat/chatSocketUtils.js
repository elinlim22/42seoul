import {
    showChatList,
    renderChatBox,
    CHATLOG_PREFIX,
    SYSTEM_MESSAGE,
    renderSystemChatAdmin, rerenderChatRoom, rerenderSystemRoom
} from "./chatPageUtils.js";
import {player} from "../app.js";
import {loadChatLog, showChatroom} from "./chatRoomUtils.js";
import {routes} from "../route.js";
import {openInfoModal} from "../Game/gameUtils.js";

export function getChatLog(usersData = []) {
    /*
    * usersData : [{
    *   id: <int>,
    *   nickname: <string>,
    *   profile: <string>
    * }]
    * */
    const result = [];

    usersData.forEach(userData => {
        const localStorageLog = localStorage.getItem(CHATLOG_PREFIX + userData.id);
        let chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

        if (chatLog.length > 0) {
            userData.chatLog = chatLog[chatLog.length - 1];
            result.push(userData);
        }
    });
    return result;
}

export function getOpponent(newMsgObj) {
    let opponent = undefined;
    if (newMsgObj !== undefined || (player.getId() === newMsgObj.from_id || player.getId() === newMsgObj.to_id)) {
        opponent = player.getId() === newMsgObj.from_id? newMsgObj.to_id : newMsgObj.from_id;
    }
    return opponent;
}

export function foundChatContainer(userId, chatApp) {
    let foundContainer = undefined;
    const containers = chatApp.getApp().querySelectorAll('.chat__container');
    containers.forEach(container => {
        if (Number(container.id) === userId) {
            foundContainer = container;
        }
    })
    return foundContainer;
}

export function closedChatLog(userId, chatApp) {
    const localStorageLog = localStorage.getItem(CHATLOG_PREFIX + userId);
    let chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

    chatLog.forEach(log => {
        if (log.type === 'invite_game') {
            log.closed = true;
        }
    });

    localStorage.setItem(CHATLOG_PREFIX + userId, JSON.stringify((chatLog)));

    const chatContainer = foundChatContainer(userId, chatApp);
    if (chatContainer !== undefined) {
        const containerInviteBtn = chatContainer.querySelectorAll('.chat__header--btn')[0];
        const chatFrame = chatContainer.querySelector('.chat__body--frame');
        const inviteBtn = chatFrame.querySelectorAll('.chatbox__invite-btn');

        inviteBtn.forEach(btn => {
            btn.disabled = true;
            btn.onclick = () => {
                inviteBtn.innerText = "Hey! don't touch me!";
                inviteBtn.disabled = true;
            };
        });
        containerInviteBtn.disabled = false;
    }
}

export function readSystemLog() {
    const localStorageLog = localStorage.getItem(SYSTEM_MESSAGE);
    let chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

    chatLog.forEach(log => log.isRead = true);

    localStorage.setItem(SYSTEM_MESSAGE, JSON.stringify((chatLog)));
}

export function readChatLog(userId) {
    const localStorageLog = localStorage.getItem(CHATLOG_PREFIX + userId);
    let chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

    chatLog.forEach(log => log.isRead = true);

    localStorage.setItem(CHATLOG_PREFIX + userId, JSON.stringify((chatLog)));
}

export function saveSystemMsg(newMsgObj) {
    const localStorageLog = localStorage.getItem(SYSTEM_MESSAGE);
    let chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

    if (chatLog.length > 0) {
        if (newMsgObj.message === 'You have successfully logged in') {
            localStorage.setItem(SYSTEM_MESSAGE, JSON.stringify([newMsgObj]));
            return ;
        }
        chatLog.forEach(log => log.isRead = true);
    }
    chatLog.push(newMsgObj);

    localStorage.setItem(SYSTEM_MESSAGE, JSON.stringify(chatLog));
}

export function saveNewMsg(newMsgObj) {
    /*
    * newMsgObj: {
    *   from_id: <int>,
    *   to_id: <int>,
    *   message: <string>,
    *   time: <string>,
    *   isRead: <boolean>
    * }
    * */

    let opponent = getOpponent(newMsgObj);
    if (opponent !== undefined) {
        const localStorageLog = localStorage.getItem(CHATLOG_PREFIX + opponent);
        let chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

        if (chatLog.length > 0) {
            chatLog.forEach(log => log.isRead = true);
        }
        chatLog.push(newMsgObj);

        localStorage.setItem(CHATLOG_PREFIX + opponent, JSON.stringify(chatLog));
    }
}

async function handleAlertClick(chatApp, opponentId) {
    try {
        const userDetail = await player.getUserDetail(opponentId);

        await showChatroom(chatApp, userDetail);
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
}

export async function processNextMatch(chatApp) {
    const data = {
        type: "system_message",
        to_id: player.getId(),
        message: "Start after 5s",
        time: new Date().toISOString()
    }

    await processSystemMessage(chatApp, data);
}

export async function processSystemMessage(chatApp, messageData) {
    /*
    * messageData: {
    *   type: "system_message",
    *   to_id: <int>,
    *   message: <string>,
    *   time: <string>
    * }
    * */
    const systemChatContainer = chatApp.getApp().querySelector('.system__chat--container');

    if (systemChatContainer !== null) {
        renderSystemChatAdmin(systemChatContainer, messageData, chatApp, true);
    } else {
        const newToast = document.createElement('div');
        const msgTime = new Date(messageData.time);

        newToast.classList.add('chat__alert--container');
        // TODO : fromNickname 수정
        newToast.innerHTML = routes["/chat"].chatAlertTemplate("System Alert", messageData.message, `${msgTime.getHours()}:${msgTime.getMinutes()>10?msgTime.getMinutes():'0' + msgTime.getMinutes()}`);

        chatApp.getApp().querySelector(".toast").appendChild(newToast);
        newToast.querySelector(".chat__alert--close-btn").onclick = () => {
            newToast.remove();
        }
        setTimeout( function() { newToast.remove(); }, 3000);

        messageData.isRead = false;
        saveSystemMsg(messageData);
        rerenderSystemRoom(messageData, chatApp);
    }
}

export async function processMessage(chatApp, messageData) {
    /*
    * messageData: {
    *   type: "chat_message",
    *   from: <string>,
    *   from_id: <int>,
    *   to_id: <int>,
    *   message: <string>,
    *   time: <string>
    * }
    *
    * invite_game : add opponentNickname
    * */
    const chatContainers = chatApp.getApp().querySelectorAll('.chat__container');
    let isRender = false;

    chatContainers.forEach(container => {
        if (player.getId() === messageData.from_id || Number(container.id) === messageData.from_id) {
            // TODO: message render
            renderChatBox(container, messageData, chatApp, true);
            isRender = true;
        }
    });
    if (!isRender) {
        const newToast = document.createElement('div');
        const msgTime = new Date(messageData.time);
        const inviter = messageData.from_id === player.getId() ? player.getNickName() : messageData.opponentNickname;
        let title = 'New Message';
        let message = messageData.message;

        newToast.classList.add('chat__alert--container');
        if (messageData.type === 'invite_game') {
            newToast.classList.add('game-alert');
            title = 'Game Invitation';
            if (messageData.status === 'invite') {
                message = `${inviter} invited you!`;
            } else if (messageData.status === 'cancel') {
                message = `${inviter} Canceled The Game`;
            }
        }

        // TODO : fromNickname 수정
        newToast.innerHTML = routes["/chat"].chatAlertTemplate(title, message, `${msgTime.getHours()}:${msgTime.getMinutes()>10?msgTime.getMinutes():'0' + msgTime.getMinutes()}`);

        chatApp.getApp().querySelector(".toast").appendChild(newToast);
        newToast.querySelector(".chat__alert--close-btn").onclick = () => {
            newToast.remove();
        }
        setTimeout( function() { newToast.remove(); }, 3000);

        messageData.isRead = false;
        saveNewMsg(messageData);

        newToast.onclick = async () => await handleAlertClick(chatApp, getOpponent(messageData));

        await rerenderChatRoom(getOpponent(messageData), messageData, chatApp);
    }
}
