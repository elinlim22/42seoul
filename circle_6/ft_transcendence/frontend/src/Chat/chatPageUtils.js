import { routes } from "../route.js";
import {showChatroom, showSystemRoom} from "./chatRoomUtils.js";
import {player} from "../app.js";
import {setAvatar} from "../Profile/modalUtils.js";
import {closedChatLog, getChatLog, getOpponent, saveNewMsg, saveSystemMsg} from "./chatSocketUtils.js";
import SocketApp from "../Game/SocketApp.js";
import {openInfoModal} from "../Game/gameUtils.js";

export const SYSTEM_MESSAGE = 'systemLog';
export const CHATLOG_PREFIX = 'chatLog_';

function getLastObj(key) {
    const localStorageLog = localStorage.getItem(key);
    const chatLog = localStorageLog ? JSON.parse(localStorageLog) : [];

    if (chatLog.length > 0) {
        return chatLog[chatLog.length - 1];
    }
    return undefined;
}

export function renderSystemChatAdmin(chatContainer, newMsgObj, chatApp, isNew = false) {
    /*
    * newMsgObj: {
    *   type: <string>,
    *   to_id: <int>,
    *   message: <string>,
    *   time: <string>,
    *   toRead: <boolean>
    * }
    * */
    const frameNode = chatContainer.querySelector('.chat__body--frame');

    const chatBoxItem = document.createElement('div');
    chatBoxItem.classList.add('chatbox__system');

    chatBoxItem.innerHTML = newMsgObj.message;

    frameNode.appendChild(chatBoxItem);

    if (isNew) {
        saveSystemMsg(newMsgObj);
        rerenderSystemRoom(newMsgObj, chatApp);
    }
}

export async function renderChatBox(chatContainer, newMsgObj, chatApp, isNew = false) {
    /*
    * newMsgObj: {
    *   type: <string>,
    *   from_id: <int>,
    *   to_id: <int>,
    *   message: <string>,
    *   time: <string>,
    *   isClose: <boolean>,
    *   isRead: <boolean>
    * }
    * */
    newMsgObj.isRead = true;

    const frameNode = chatContainer.querySelector('.chat__body--frame');

    const msgTime = new Date(newMsgObj.time);
    const chatBoxNode = document.createElement('div');
    chatBoxNode.classList.add('chatbox', `message_${player.getId() === newMsgObj.from_id? 'me':'you'}`);

    chatBoxNode.innerHTML += routes["/chat"].chatBoxTemplate(newMsgObj.message?newMsgObj.message:'', `${msgTime.getHours()}:${msgTime.getMinutes()>10?msgTime.getMinutes():'0' + msgTime.getMinutes()}`);

    frameNode.appendChild(chatBoxNode);
    if (newMsgObj.type === 'invite_game') {
        const containerInviteBtn = chatContainer.querySelectorAll('.chat__header--btn')[0];
        if (newMsgObj.status === 'invite') {
            const messageNode = chatBoxNode.querySelector('.chatbox__message');
            const inviteBtn = document.createElement('button');

            inviteBtn.classList.add('chatbox__invite-btn');
            inviteBtn.innerText = "Join the Game";

            if (newMsgObj.closed) {
                inviteBtn.disabled = true;
                inviteBtn.onclick = () => {
                    inviteBtn.innerText = "Hey! don't touch me!";
                    inviteBtn.disabled = true;
                };
            } else {
                inviteBtn.onclick = async () => {
                    const userDetail = await player.getUserDetail(getOpponent(newMsgObj));
                    const socketApp = SocketApp;

                    socketApp.inviteGameRoom(newMsgObj.room_id, [player.getInfo(), userDetail], chatApp);
                    closedChatLog(userDetail.id, chatApp);
                }
                containerInviteBtn.disabled = true;
            }
            messageNode.appendChild(inviteBtn);
        } else if (newMsgObj.status === 'cancel') {
            chatBoxNode.remove();

            const inviter = newMsgObj.from_id === player.getId() ? player.getNickName() : newMsgObj.opponentNickname;
            const cancelMessageNode = document.createElement('div');
            cancelMessageNode.classList.add('chatbox__system');

            cancelMessageNode.innerHTML = `${inviter} Canceled The Game`;

            frameNode.appendChild(cancelMessageNode);
            containerInviteBtn.disabled = false;
        }
    }
    frameNode.scrollTop = frameNode.scrollHeight;
    if (isNew) {
        saveNewMsg(newMsgObj);
        await rerenderChatRoom(getOpponent(newMsgObj), newMsgObj, chatApp);
    }
}

export function renderSystemChatBox(app, message, userId) {
    const chatContainers = app.querySelectorAll('.chat__container');

    chatContainers.forEach(container => {
        if (Number(container.id) === userId) {
            const frameNode = container.querySelector('.chat__body--frame');

            frameNode.innerHTML += routes['/chat'].systemChatBoxTemplate(message);
            frameNode.scrollTop = frameNode.scrollHeight;
        }
    });
}

export function rerenderSystemRoom(lastObj, chatApp) {
    const chatRoomList = chatApp.getApp().querySelector(".chat__room--list");

    if (chatRoomList === null) {
        return ;
    }
    const chatRoomItems = chatRoomList.querySelector('.chat__room--system');

    if (lastObj.isRead) {
        chatRoomItems.classList.remove('chat__room--no-read');
    } else {
        chatRoomItems.classList.add('chat__room--no-read');
    }
    chatRoomItems.querySelector('.system-room__msg').innerHTML = lastObj.message;
}

export function renderSystemRoom(chatRoomList, lastObj, chatApp) {
    /*
    * lastObj: {
    *   type: "system_message",
    *   from: "admin",
    *   room_id: <string>,
    *   message: <string>,
    *   time: <string>,
    *   isRead: <boolean>
    *   }
    * */
    const systemRoom = document.createElement('div');
    systemRoom.classList.add('chat__room', 'chat__room--system');

    let message = "";
    let timeStamp = "";

    if (lastObj !== undefined) {
        message = lastObj.message;
        const msgTime = new Date(lastObj.time);
        timeStamp = `${msgTime.getHours()}:${msgTime.getMinutes()>10?msgTime.getMinutes():'0' + msgTime.getMinutes()}`;

        if (!lastObj.isRead) {
            systemRoom.classList.add('chat__room--no-read');
        }
    }
    systemRoom.innerHTML = routes['/chat'].systemRoomTemplate(message, timeStamp);

    chatRoomList.appendChild(systemRoom);

    systemRoom.addEventListener('click', async () => {
        await showSystemRoom(chatApp);
    });
}

export async function rerenderChatRoom(id, lastObj, chatApp) {
    const chatRoomList = chatApp.getApp().querySelector(".chat__room--list");

    if (chatRoomList === null) {
        return ;
    }

    if (lastObj.type === 'invite_game') {
        const inviter = lastObj.from_id === player.getId() ? player.getNickName() : lastObj.opponentNickname;

        if (lastObj.status === 'invite') {
            lastObj.message = `${inviter} invited you!`;
        } else if (lastObj.status === 'cancel') {
            lastObj.message = `${inviter} Canceled The Game`;
        }
    }

    const chatRoomItems = chatRoomList.querySelectorAll('.chat__room');
    let isRender = false;

    chatRoomItems.forEach(roomItem => {
        if (Number(roomItem.id) === id) {
            if (lastObj.isRead) {
                roomItem.classList.remove('chat__room--no-read');
            } else {
                roomItem.classList.add('chat__room--no-read');
            }
            roomItem.querySelector('.chat__room--msg').innerHTML = lastObj.message;
            isRender = true;
        }
    });
    if (!isRender) {
        await renderChatRoom(chatRoomList, lastObj, chatApp);
    }
}

export async function renderChatRoom(chatRoomList, lastObj, chatApp) {
    /*
    * lastObj : {
    *   type: <string>,
    *   from_id: <int>,
    *   to_id: <int>,
    *   message: <string>,
    *   time: <string>,
    *   isRead: <boolean>
    * }
    * */
    if (lastObj === undefined) {
        return ;
    }

    const opponent = getOpponent(lastObj);
    try {
        const userDetail = await player.getUserDetail(opponent);

        const chatRoomItem = document.createElement('div');
        chatRoomItem.classList.add('chat__room');
        chatRoomItem.id = opponent;

        const inviter = lastObj.from_id === player.getId() ? player.getNickName() : lastObj.opponentNickname;
        const msgTime = new Date(lastObj.time);

        if (lastObj.type === 'invite_game') {
            if (lastObj.status === 'invite') {
                lastObj.message = `${inviter} invited you!`;
            } else if (lastObj.status === 'cancel') {
                lastObj.message = `${inviter} Canceled The Game`;
            }
        }

        chatRoomItem.innerHTML = routes['/chat'].chatRoomTemplate(userDetail.nickname, lastObj.message, `${msgTime.getHours()}:${msgTime.getMinutes()>10?msgTime.getMinutes():'0' + msgTime.getMinutes()}`);

        const avatar = chatRoomItem.querySelector('.chat__room--profile');

        setAvatar(userDetail.profile, avatar);

        if (!lastObj.isRead) {
            chatRoomItem.classList.add('chat__room--no-read');
        }

        chatRoomList.appendChild(chatRoomItem);

        chatRoomItem.addEventListener('click', async () => {
            await showChatroom(chatApp, userDetail);
        });
    } catch (e) {
        if (e.error === 404) {
            localStorage.removeItem(CHATLOG_PREFIX + opponent);
        } else {
            openInfoModal(`Something was wrong .. Error code: ${e.error}`);
        }
    }

}

export async function showChatList(chatApp) {
    const chatRoomList = chatApp.getApp().querySelector(".chat__room--list");

    if (chatRoomList !== null) {
        chatRoomList.innerHTML = "";

        renderSystemRoom(chatRoomList, getLastObj(SYSTEM_MESSAGE), chatApp);

        for (let i = 0; i < localStorage.length; i++) {
            const key = localStorage.key(i);
            if (key.startsWith(CHATLOG_PREFIX)) {
                const lastObj = getLastObj(key);
                if (lastObj !== undefined) {
                    await renderChatRoom(chatRoomList, lastObj, chatApp);
                }
            }
        }
        if (chatRoomList.innerHTML === "")
            chatRoomList.innerHTML = `<div class="chat__search--error">
        You haven't started chatting!
        </div>`
    }
}

async function getChatLogByKeyword(keyword) {
    if (keyword.length <= 0) {
        return [];
    }

    try {
        const searchUsers = await player.searchUser(keyword);
        return getChatLog(searchUsers);
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
    return [];
}

async function showSearchResult(keyword, chatApp) {
    const chatRoomList = chatApp.getApp().querySelector(".chat__room--list");
    const keywordRoomData = await getChatLogByKeyword(keyword);

    chatRoomList.innerHTML = "";
    if (keywordRoomData.length > 0) {
        keywordRoomData.forEach(roomData => {
            renderChatRoom(chatRoomList, roomData.chatLog, chatApp);
        });
    } else {
        chatRoomList.innerHTML = `<div class="chat__search--error">
        Nothing found for ${keyword}
        </div>`
    }
}

// 검색창 내부 input 달라질 때마다 호출되는 함수
async function checkChatroomSearch(chatApp) {
    const chatSearchInput = chatApp.getApp().querySelector("#chat__search--input");

    if (chatSearchInput !== null && chatSearchInput.value.length > 0)
        await showSearchResult(chatSearchInput.value, chatApp);
    else
        await showChatList(chatApp);
}

export async function setChatPage(chatApp) {
    await showChatList(chatApp);

    const chatSearchBtn = chatApp.getApp().querySelector(".chat__search");
    chatSearchBtn.onsubmit = function (e) {
        e.preventDefault();
    }

    let timeoutFunction;

    chatSearchBtn.onkeyup = async () => {
        clearTimeout(timeoutFunction);
        timeoutFunction = setTimeout(async () => {
            await checkChatroomSearch(chatApp);
        }, 500);
    };
}