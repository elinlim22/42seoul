import ProfileModal from "./profileModalTemplate.js";
import {DOING, PROFILE_DEFAULT_IMAGE} from '../Login/player.js';
import {player} from "../app.js";
import {openInfoModal} from "../Game/gameUtils.js";
import {showChatroom} from "../Chat/chatRoomUtils.js";
import {profileModalTemplate, renderMainPage, setFriendList} from "../Login/loginUtils.js";

export function decodeHtml(html) {
    const txt = document.createElement("textarea");
    txt.innerHTML = html;
    return txt.value;
}

export function orderPlayer(userId, data) {
    /*
    * data : {
    *   id: <int>,
    *   match_type: <string>,
    *   user1_id: <int>,
    *   user2_id: <int>,
    *   user1_score: <int>,
    *   user2_score: <int>,
    *   user1_profile: <string>,
    *   user2_profile: <string>
    * }
    * */
    if (userId !== data.user1_id) {
        let tmp = data.user1_id;
        data.user1_id = data.user2_id;
        data.user2_id = tmp;

        tmp = data.user1_score;
        data.user1_score = data.user2_score;
        data.user2_score = tmp;

        tmp = data.user1_profile;
        data.user1_profile = data.user2_profile;
        data.user2_profile = tmp;
    }
    return data;
}

export function toggleAddAndDeleteBtn(chatApp, btnNode, id, doing) {
    const buttonMsg = ['<i class="bi bi-person-plus"></i> add', '<i class="bi bi-person-dash-fill"></i> delete'];

    btnNode.innerHTML = doing === DOING.ADD? buttonMsg[0]:buttonMsg[1];
    try {
        btnNode.onclick = async () => {
            btnNode.disabled = true;
            await player.friend(id, doing);

            const { is_online } = await chatApp.isOnline(id, doing);
            if (is_online || doing === DOING.DELETE) {
                chatApp.setFriendsOnline(id, doing);
            }
            btnNode.innerHTML = buttonMsg[1];
            toggleAddAndDeleteBtn(chatApp, btnNode, id, doing === DOING.ADD? DOING.DELETE : DOING.ADD);
            await setFriendList(chatApp);
            setupFriendListStatus();
            btnNode.disabled = false;
        }
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
}

export function getGameHistoryItem(userId, data) {
    /*
    * data : {
    *   id: <int>,
    *   match_type: <string>,
    *   user1_id: <int>,
    *   user2_id: <int>,
    *   user1_score: <int>,
    *   user2_score: <int>,
    *   created_at: <date>,
    *   user1_profile: <string>,
    *   user2_profile: <string>
    * }
    * */
    const orderedData = orderPlayer(userId, data);

    const itemNode = document.createElement('div');
    itemNode.classList.add('friend-modal__history-item');

    itemNode.innerHTML = profileModalTemplate.matchHistoryTemplate();

    const dateNode = itemNode.querySelector('.history-item__day');
    const myAvatar = itemNode.querySelector('.match-my-avatar');
    const youAvatar = itemNode.querySelector('.match-your-avatar');
    const scoreNode = itemNode.querySelector('.history-item__score');
    const status = itemNode.querySelector('.history-item__status');

    const historyDate = new Date(orderedData.created_at);

    setAvatar(orderedData.user1_profile, myAvatar);
    setAvatar(orderedData.user2_profile, youAvatar);

    dateNode.innerHTML = `${historyDate.getFullYear() % 100}/${historyDate.getMonth() + 1}/${historyDate.getDate()}`;
    scoreNode.innerHTML = `Score ${orderedData.user1_score} : ${orderedData.user2_score}`;
    status.innerHTML = orderedData.user1_score > orderedData.user2_score? 'Win': 'Lose';

    return itemNode;
}

export async function renderGameHistoryList(userId, historyListNode, gameHistoryData = []) {
    for (let data of gameHistoryData) {
        const user1Detail = await player.getUserDetail(data.user1_id);
        const user2Detail = await player.getUserDetail(data.user2_id);

        data.user1_profile = user1Detail.profile;
        data.user2_profile = user2Detail.profile;
    }

    gameHistoryData.forEach(data => {
        const item = getGameHistoryItem(userId, data);
        historyListNode.appendChild(item);
    })
}

export function  modalRender(modalName, htmlCode, backgroundClick = true) {
    const modal = document.querySelector('.modal');
    const modalContainer = document.createElement('div');

    modalContainer.classList.add('modal__container', `modal-name__${modalName}`);
    modalContainer.innerHTML = htmlCode;

    modal.appendChild(modalContainer);

    if (backgroundClick) {
        modalContainer.querySelector('.modal__background').addEventListener('click', () => {
            if (modalContainer !== undefined) modalContainer.remove();
        });
    }
    return modalContainer;
}

export async function friendModalClick(id, chatApp) {
    try {
        const data = await player.getUserDetail(id);
        const modalContainer = modalRender("friend-profile", profileModalTemplate.friendModalTemplate());
        modalContainer.querySelector('.friend-modal__container').id = id;

        const {
            nickname: name,
            profile,
            status_message,
            win,
            lose,
            rank,
            is_friend
        } = data;

        const avatarNode = modalContainer.querySelector('.friend-modal__avatar');
        const friendInfo = modalContainer.querySelector('.friend-modal__info').children;
        const winRate = modalContainer.querySelector('.friend-modal__game-info--rate').children[0];
        const rankPoint = modalContainer.querySelector('.friend-modal__game-info--rank').children[0];
        const profileBtns = modalContainer.querySelectorAll(".friend-modal__btn");

        setAvatar(profile, avatarNode);

        friendInfo[0].innerHTML = name;
        friendInfo[1].innerHTML = status_message;

        winRate.innerHTML = (win + lose) ? `${(win / (win + lose) * 100).toPrecision(5)}%` : '0%';
        rankPoint.innerHTML = rank;

        const gameHistoryListNode = modalContainer.querySelector('.friend-modal__history-list');
        const gameHistory = await player.getMatchHistoryById(id);
        await renderGameHistoryList(id, gameHistoryListNode, gameHistory);

        if (player.getId() === id) {
            profileBtns.forEach(btn => btn.remove());
        } else {
            profileBtns[0].onclick = async () => {
                await showChatroom(chatApp, data);
            }
            toggleAddAndDeleteBtn(chatApp, profileBtns[1], id, is_friend ? DOING.DELETE : DOING.ADD);
        }
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
}

export function handleFileInputAtDiv(avatars, selectedClassName) {
    const fileInput = document.createElement('input');
    fileInput.type = 'file';
    fileInput.accept = 'image/*';

    fileInput.addEventListener('change', e => {
        if (e.target.files.length > 0) {
            const file = e.target.files[0];
            const reader = new FileReader();

            const maxSize = 1024 * 1024;
            if (file.size > maxSize) {
                openInfoModal('File size must be under 1MB');
                return ;
            }

            reader.onload = e => {
                avatars[1].style.backgroundImage = `url(${e.target.result})`;
                avatars[1].setAttribute('data-image', e.target.result);
            }

            reader.readAsDataURL(file);
        } else {
            avatars[0].classList.toggle(selectedClassName);
            avatars[1].classList.toggle(selectedClassName);
        }
    });

    fileInput.click();
}

function getAvatarData(avatars) {
    const selectedClassName = 'profile-modal__selected-avatar';

    if (avatars[1].classList.contains(selectedClassName) && avatars[1].getAttribute('data-image') !== 'upload') {
        return avatars[1].getAttribute('data-image');
    }
    return avatars[0].getAttribute('data-image');
}

function get2FAData(toggleItems) {
    const selectedClassName = 'profile-modal__toggle-selected';

    return toggleItems[0].classList.contains(selectedClassName);
}

export function handleEditUserModalUtils(app) {
    const profileBtn = app.querySelector('.profile-section__profile');
    const avatar = profileBtn.querySelector('.profile-section__profile--avatar');
    const editBtn = profileBtn.querySelector('.profile-section__profile--info > div:nth-child(2) div:last-child');

    avatar.addEventListener('click', async () => {
        await friendModalClick(player.getId());
    });

    editBtn.addEventListener('click', () => {
        const modalContainer = modalRender("profile", ProfileModal.template());

        const nickname = modalContainer.querySelector('.profile-modal__nickname');
        const status_message = modalContainer.querySelector('.profile-modal__status-message');

        nickname.value = decodeHtml(player.getNickName());
        status_message.value = decodeHtml(player.getStatusMessage());

        nickname.nextElementSibling.firstElementChild.innerHTML = nickname.value.length;
        status_message.nextElementSibling.firstElementChild.innerHTML = status_message.value.length;

        const nicknameContainer = modalContainer.querySelectorAll('.profile-modal__body--content')[1];
        const warningContainer = nicknameContainer.querySelector('.profile-modal__body--warn');
        const saveBtn = modalContainer.querySelector('.profile-modal__save-btn');

        modalContainer.querySelectorAll('textarea').forEach((element, i) => {
            element.addEventListener('keyup', e => {
                const textLenLimit = e.target.nextElementSibling.firstElementChild;

                textLenLimit.innerHTML = `${e.target.value.length}`;
            });
            if (i === 0) {
                let timeoutFunction;
                element.addEventListener('keyup', e => {
                    clearTimeout(timeoutFunction);
                    timeoutFunction = setTimeout(async () => {
                        e.target.classList.remove('warnColor');
                        warningContainer.innerHTML = '';
                        saveBtn.disabled = false;
                        if ((player.getNickName() !== e.target.value && /^User(\d+)?$/i.test(e.target.value)) || e.target.value.includes('\n')) {
                            warningContainer.innerHTML = `Invalid Nickname.`;
                            e.target.classList.add('warnColor');
                            saveBtn.disabled = true;
                            return ;
                        }
                        try {
                            const data = await player.searchUser(e.target.value);
                            data.forEach(user => {
                                if (user.nickname !== player.getNickName() && user.nickname === e.target.value) {
                                    warningContainer.innerHTML = 'duplicate name';
                                    e.target.classList.add('warnColor');
                                    saveBtn.disabled = true;
                                }
                            });
                        } catch (e) {
                            // TODO: error modal?
                        }
                    }, 500);
                });
            }
        });

        const avatars = modalContainer.querySelectorAll('.profile-modal__avatar');

        if (PROFILE_DEFAULT_IMAGE.indexOf(player.getProfile()) === -1) {
            setAvatar(player.getProfile(), avatars[1]);
            avatars[1].setAttribute('data-image', player.getProfile());
            avatars[0].classList.toggle('profile-modal__selected-avatar');
            avatars[1].classList.toggle('profile-modal__selected-avatar');
        } else {
            setAvatar(player.getProfile(), avatars[0]);
        }

        avatars.forEach((element, i) => {
            element.addEventListener('click', e => {
                const selectedClassName = 'profile-modal__selected-avatar';

                if (avatars[1] === e.target) {
                    handleFileInputAtDiv(avatars, selectedClassName);
                }

                if (e.target.classList.contains(selectedClassName)) {
                    if (i === 0) {
                        const curr = e.target.getAttribute('data-image');

                        e.target.setAttribute('data-image', PROFILE_DEFAULT_IMAGE[(PROFILE_DEFAULT_IMAGE.indexOf(curr) + 1) % PROFILE_DEFAULT_IMAGE.length]);
                    }
                } else {
                    avatars[0].classList.toggle(selectedClassName);
                    avatars[1].classList.toggle(selectedClassName);
                }
            })
        });

        const toggleItems = modalContainer.querySelectorAll('.profile-modal__toggle-item');

        if (!player.getSet2fa()) {
            toggleItems[0].classList.toggle('profile-modal__toggle-selected');
            toggleItems[1].classList.toggle('profile-modal__toggle-selected');
        }

        toggleItems.forEach((element, i) => {
            element.addEventListener('click', e => {
                const selectedClassName = 'profile-modal__toggle-selected';

                if (!(toggleItems[i].classList.contains(selectedClassName))) {
                    toggleItems[0].classList.toggle(selectedClassName);
                    toggleItems[1].classList.toggle(selectedClassName);
                }
            });
        });

        saveBtn.addEventListener('click', async () =>  {
            const data = {
                'profile_to': getAvatarData(avatars),
                'nickname_to': nickname.value,
                'status_message_to': status_message.value,
                'set_2fa_to': get2FAData(toggleItems)
            };
            try {
                await player.setProfile(data);
                await renderMainPage();
            } catch (e) {
                openInfoModal(`Something was wrong ..<br />Error code: ${e.error}`);
            }
        });
    });
}

export function setAvatar(playerProfile, divNode) {
    if (PROFILE_DEFAULT_IMAGE.indexOf(playerProfile) === -1) {
        divNode.style.backgroundImage = `url(${playerProfile})`;
    } else {
        divNode.setAttribute('data-image', playerProfile);
    }
}

export function setFriendStatus(friendItemNode, isOnline = true) {
    const friendStatus = friendItemNode.querySelector('.profile-section__friends--status');
    const statusText = friendStatus.children[0];


    if (isOnline) {
        statusText.innerHTML = 'online';
        friendStatus.classList.add('online');
    } else {
        statusText.innerHTML = 'offline';
        friendStatus.classList.remove('online');
    }
}

export function findItemFromFriendList(friendListNode, friendId) {
    const friendItems = friendListNode.querySelectorAll('.profile-section__friends--item');

    for (const friendItem of friendItems) {
        if (Number(friendItem.id) === friendId) {
            return friendItem;
        }
    }
    return undefined;
}

export function setupFriendListStatus() {
    const chatApp = player.getChatApp();
    const friendListNode = chatApp.getFriendListNode();
    const friendListData = chatApp.getFriendsOnline();

    if (friendListNode !== undefined) {
        const friendItems = friendListNode.querySelectorAll('.profile-section__friends--item');

        friendItems.forEach(item => {
            if (friendListData.includes(Number(item.id))) {
                setFriendStatus(item, true);
            }
        });
    }
}