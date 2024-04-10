import { USER_SERVER_DOMAIN, USER_MANAGEMENT_DOMAIN } from "../Public/global.js"
import LoginSuccess from "./loginSuccessTemplate.js";
import Login from "./loginTemplate.js";
import ProfileModal from "../Profile/profileModalTemplate.js";
import player, {USER_STATUS} from "./player.js";
import changeUrl, { setPages } from "../route.js";
import {handleLoginBtn, handleNaviClick} from "../Public/clickUtils.js";
import {
    friendModalClick,
    handleEditUserModalUtils,
    modalRender,
    setAvatar, setupFriendListStatus
} from "../Profile/modalUtils.js";
import Player from "./player.js";
import {openInfoModal} from "../Game/gameUtils.js";

export const loginSuccessTemplate = LoginSuccess;
export const profileModalTemplate = ProfileModal;

export async function socialLogin(site) {
    const response = await fetch(`${USER_SERVER_DOMAIN}/${USER_MANAGEMENT_DOMAIN}/accounts/${site}/login/`, {
        method: 'GET',
    });
    if (!response.ok)
        throw new Error(`Error : ${response.status}`);

    const data = await response.json();
    window.location.href = data.login_url;
}

export function setFriendItem(chatApp, friendListElement, friendData, status = true) {
    /*
    * friendData : {
    *   id: <int>,
    *   nickname: <string>,
    *   profile: <string>
    * }
    * */
    const itemContainer = document.createElement('div');
    itemContainer.classList.add('profile-section__friends--item');
    itemContainer.id = friendData.id;

    itemContainer.innerHTML = loginSuccessTemplate.friendBoxTemplate(friendData.nickname, status);
    const avatarNode = itemContainer.querySelector('.profile-section__friends--pic');

    setAvatar(friendData.profile, avatarNode);

    friendListElement.appendChild(itemContainer);

    itemContainer.addEventListener('click', async () => {
        await friendModalClick(friendData.id, chatApp);
    });
}

export async function setFriendList(chatApp) {
    // make friends elements
    const friendListElement = chatApp.getApp().querySelector(".profile-section__friends--list");
    try {
        const friendList = await Player.getFriendList();

        friendListElement.innerHTML = "";

        if (friendList.length > 0) {
            friendList.forEach(friendData => {
                setFriendItem(chatApp, friendListElement, friendData);
            });
        } else {
            friendListElement.innerHTML = `<div class="profile-section__friends--msg">
        Let's play the game
        <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        & make new friends 🤝</div>`;
        }
    } catch (e) {
        console.error(e.error);
        friendListElement.innerHTML = `<div class="profile-section__friends--msg">
        User Server is wrong 🥲 ..</div>`;
    }
}

async function handleProfileSearch(listNode, keyword, chatApp) {
    listNode.innerHTML = "";

    if (keyword === "") {
        return;
    }

    try {
        const data = await player.searchUser(keyword);

        data.forEach(user => {
            const itemContainer = document.createElement('div');
            itemContainer.classList.add('friend-item__container');
            itemContainer.style.width = '300px';
            itemContainer.style.marginBottom = '10px';

            setFriendItem(chatApp, itemContainer, user, false);

            listNode.appendChild(itemContainer);
        });
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
}

export async function handleAddFriendBtn(chatApp) {
    const addFriendModal = modalRender('add-friend', profileModalTemplate.profileSearchTemplate())

    const profileSearchInput = addFriendModal.querySelector(".search-friend__body--input");
    const profileSearchList = addFriendModal.querySelector('.search-friend__body--list');

    let timeoutFunction;

    profileSearchInput.onkeyup = async () => {
        clearTimeout(timeoutFunction);
        timeoutFunction = setTimeout(async () => {
            await handleProfileSearch(profileSearchList, profileSearchInput.value, chatApp);
        }, 500);
    };
}

export function changeTo2FAPage(loginUser) {
    const loginBody = document.querySelector(".login__container--body");

    loginBody.querySelector(".login__wrapper--header").innerHTML = "<span class='login__wrapper--header_'>Verification</span>";
    loginBody.querySelector(".login__wrapper--list").innerHTML = Login.twoFATemplate();

    const codeInput = loginBody.querySelector('.login__body--input');
    const twoFABtn = loginBody.querySelector('.login__2fa-btn');

    codeInput.addEventListener('keyup', e => {
        twoFABtn.disabled = e.target.value.length !== 6;
        if (e.keyCode === 13) {
            twoFABtn.click();
        }
    });

    twoFABtn.addEventListener('click', async () => {
        const infoContainer = loginBody.querySelector('.login__body--info');

        try {
            await loginUser.send2FACode(codeInput.value);

            infoContainer.innerHTML = "";
            await loginUser.whoAmI();
            await renderMainPage();
        } catch (e) {
            infoContainer.innerHTML = "Wrong code!";
        }
    });
}

export function getInfoJWT(token) {
    const base64Payload = token.split('.')[1];
    const base64 = base64Payload.replace(/-/g, '+').replace(/_/g, '/');
    const jsonPayload = decodeURIComponent(atob(base64).split('').map(function(c) {
        return '%' + ('00' + c.charCodeAt(0).toString(16)).slice(-2);
    }).join(''));

    return JSON.parse(jsonPayload);
}

export async function renderMainPage() {
    const app = document.getElementById('app');

    if (player !== undefined && player.getStatus() === USER_STATUS.AUTHORIZED) {
        app.innerHTML = LoginSuccess.template();

        const logo = app.querySelector('.header__logo--text');

        logo.onclick = () => changeUrl('/home', true);

        const requestedUrl = (window.location.pathname === '/' ? "/home" : window.location.pathname);
        history.replaceState(requestedUrl, null, requestedUrl);
        await setPages(player.getChatApp());

        setProfileSection(app, player);
        handleNaviClick(player.getChatApp());
        await setFriendList(player.getChatApp());

        const friendAddButton = app.querySelector(".profile-section__friends--button");
        friendAddButton.onclick = () => {
            handleAddFriendBtn(player.getChatApp());
        };
        const friendListNode = app.querySelector('.profile-section__friends--list');
        player.getChatApp().setFriendListNode(friendListNode);

        setupFriendListStatus();
    } else {
        app.innerHTML = Login.template();
        handleLoginBtn();
        if (player !== undefined && player.getStatus() === USER_STATUS.NOT_AUTHORIZED) {
            changeTo2FAPage(player);
        }
    }
}

export function setProfileSection(app, player) {
    const profileSection = app.querySelector('.profile-section');

    const profile = profileSection.querySelector('.profile-section__profile');
    const avatar = profile.querySelector('.profile-section__profile--avatar');
    const infoNode = profile.querySelector('.profile-section__profile--info').children;

    setAvatar(player.getProfile(), avatar);

    if (/^User(\d+)?$/i.test(player.getNickName())) {
        infoNode[0].innerHTML = "We advise you to change your nickname!";
    } else {
        infoNode[0].innerHTML = "";
    }
    infoNode[1].children[0].innerHTML = player.getNickName();
    infoNode[2].innerHTML = player.getStatusMessage();

    handleEditUserModalUtils(app);
}
