import { routes } from "../route.js";
import {modalRender, setAvatar} from "../Profile/modalUtils.js";
import {
    SYSTEM_MESSAGE,
    CHATLOG_PREFIX,
    renderChatBox,
    showChatList,
    renderSystemChatAdmin,
    rerenderChatRoom, rerenderSystemRoom
} from "./chatPageUtils.js";
import {readChatLog, readSystemLog} from "./chatSocketUtils.js";
import {openInfoModal} from "../Game/gameUtils.js";

export function getSystemLog() {
    const systemLog = localStorage.getItem(SYSTEM_MESSAGE);

    return systemLog? JSON.parse(systemLog) : [];
}

function getChatLog(userId) {
    /*
    * return: [{
    *   from: <string>,
    *   from_id: <int>,
    *   message: <string>,
    *   time: <string>,
    *   isRead: <boolean>
    * }]
    * */
    const chatLog = localStorage.getItem(CHATLOG_PREFIX + userId);

    return chatLog ? JSON.parse(chatLog) : [];
}

export async function loadSystemChatLog(chatContainer, chatApp) {
    const frameNode = chatContainer.querySelector('.chat__body--frame');

    if (frameNode !== null) {
        frameNode.innerHTML = "";

        const systemLog = getSystemLog();
        systemLog.forEach(log => {
            log.isRead = true;
            renderSystemChatAdmin(chatContainer, log, chatApp);
        });
        if (systemLog.length > 0) {
            await rerenderSystemRoom(systemLog[systemLog.length - 1], chatApp);
        }
    }
}

export async function loadChatLog(chatContainer, userId, chatApp) {
    const frameNode = chatContainer.querySelector('.chat__body--frame');

    if (frameNode !== null) {
        frameNode.innerHTML = "";

        const chatLog = getChatLog(userId);
        chatLog.forEach(log => {
            log.isRead = true;
            renderChatBox(chatContainer, log, chatApp);
        });
        if (chatLog.length > 0) {
            await rerenderChatRoom(userId, chatLog[chatLog.length - 1], chatApp);
        }
    }
}

function handleInvite(chatApp, userData) {
    /*
    * userData: {id: <string>, nickname: <string>, profile: <string>}
    * */
    chatApp.inviteGame(userData.id);
}

async function handleBlockToggle(chatApp, userData, blockToggleBtn, isBlocked) {
    const blockIcon = `<i class="bi bi-person-slash"></i>`;
    try {
        await chatApp.userBlock(userData.id, isBlocked);

        if (isBlocked) {
            blockToggleBtn.innerHTML = `${blockIcon} Block`;
        } else {
            blockToggleBtn.innerHTML = `${blockIcon} Unblock`;
        }
        blockToggleBtn.onclick = () => {
            handleBlockToggle(chatApp, userData, blockToggleBtn, !isBlocked);
        };
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
}

export async function showSystemRoom(chatApp) {
    const chatModal = modalRender('chat', routes["/chat"].modalTemplate());
    const chatContainer = chatModal.querySelector('.chat__container');
    const avatar = chatContainer.querySelector('.chat__header--avatar');
    const chatHeaderBtns = chatContainer.querySelectorAll(".chat__header--btn");
    const controller = chatContainer.querySelector('.chat__body--controller');
    const roomName = chatContainer.querySelector('.chat__header--name');

    chatContainer.classList.add('system__chat--container');

    avatar.classList.add('system__avatar');
    chatHeaderBtns.forEach(btn => btn.remove());
    controller.remove();
    roomName.innerHTML = 'System';

    await loadSystemChatLog(chatContainer, chatApp);

    readSystemLog();
}

export async function showChatroom(chatApp, userData) {
    /*
    * userData: {
    *   id: <int>,
    *   nickname: <string>,
    *   profile: <string>,
    *   status_message: <string>,
    *   win: <int>,
    *   lose: <int>,
    *   rank: <int>,
    *   is_friend: <boolean>,
    * }
    * */
    const chatModal = modalRender("chat", routes["/chat"].modalTemplate());
    const chatContainer = chatModal.querySelector('.chat__container');
    const avatar = chatContainer.querySelector('.chat__header--avatar');
    const chatHeaderBtns = chatContainer.querySelectorAll(".chat__header--btn");
    const sendBtn = chatContainer.querySelector('.chat__send--btn');
    const msgInput = chatContainer.querySelector('.chat__body--text');

    chatContainer.id = userData.id;
    setAvatar(userData.profile, avatar);

    try {
        const data = await chatApp.isBlocked(userData.id);
        const blockIcon = `<i class="bi bi-person-slash"></i>`;

        if (data.is_blocked === true) {
            chatHeaderBtns[1].innerHTML = `${blockIcon} Unblock`;
            chatHeaderBtns[1].classList.replace("block", "unblock");
        }

        chatHeaderBtns[0].onclick = () => { handleInvite(chatApp, userData) };
        chatHeaderBtns[1].onclick = async e => { await handleBlockToggle(chatApp, userData, e.target, data.is_blocked) };

        chatModal.querySelector(".chat__header--name").innerHTML = userData.nickname;

        await loadChatLog(chatContainer, userData.id, chatApp);

        sendBtn.addEventListener('click', e => {
            if (msgInput.value.length > 0) {
                chatApp.sendMessage(userData.id, msgInput.value);
                msgInput.value = "";
            }
        });

        msgInput.addEventListener('keydown', e => {
            if (e.keyCode === 13) {
                e.preventDefault();
                sendBtn.click();
            }
        });
        readChatLog(userData.id);
        chatContainer.querySelector('.chat__body--text').focus();
    } catch(e) {
        openInfoModal(`Something was wrong .. Error code: ${e}`);
    }
}
