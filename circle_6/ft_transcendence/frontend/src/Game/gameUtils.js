import { routes } from "../route.js";
import {modalRender, setAvatar} from "../Profile/modalUtils.js";
import SocketApp, {SOCKET_STATE} from "./SocketApp.js";
import { GAME_TYPE } from "./gameTemplate.js";
import {player} from "../app.js";
import {PROFILE_DEFAULT_IMAGE} from "../Login/player.js";

export function generateGuest(guestName = 'GUEST', avoidList = []) {
    let profileIdx = Math.floor(Math.random() * PROFILE_DEFAULT_IMAGE.length);
    const avoidIdx = avoidList.map(item => PROFILE_DEFAULT_IMAGE.indexOf(item));

    for (let i = 0; i < PROFILE_DEFAULT_IMAGE.length; ++i) {
        if (avoidIdx.includes(profileIdx)) {
            profileIdx = (profileIdx + 1) % PROFILE_DEFAULT_IMAGE.length;
        }
    }

    return {
        'profile': PROFILE_DEFAULT_IMAGE[profileIdx],
        'nickname': guestName
    };
}

export async function getInfoPlayerList(playerIds) {
    let players = [];
    for (const playerId of playerIds) {
        let data;
        try {
            data = await player.getUserDetail(playerId);
        } catch (e) {
            // TODO: alert user server status
            let avoidAvatar = [];
            data = generateGuest('player', avoidAvatar);
            avoidAvatar.push(data.profile);
        }

        players.push(data);
    }
    return players;
}

export function orderPlayers(playerNumber, players) {
    if (playerNumber === 2) {
        [players[0], players[1]] = [players[1], players[0]];
    } else if (playerNumber === 3) {
        [players[0], players[1], players[2], players[3]] = [players[2], players[3], players[0], players[1]];
    } else if (playerNumber === 4) {
        [players[0], players[1], players[2], players[3]] = [players[3], players[2], players[0], players[1]];
    }
    return players;
}

export function getPlayerIdxInPlayerList(includeId = [], playerList = []) {
    const data = {
        includeUser: [],
        unIncludeUser: []
    };
    playerList.forEach((user, i) => {
        user.profile_idx = i;
        if (includeId.includes(user.id)) {
            data.includeUser.push(user);
        } else {
            data.unIncludeUser.push(user);
        }
    });
    /*
    * data {
    *   includeUser: [ userData: {profile_idx} ],
    *   unIncludeUser: [ userData: {profile_idx} ]
    * }
    * */
    return data;
}

export function openPlayGameModal(socketApp, players) {
    const modalContainer = modalRender('play-game', routes['/game'].playGameTemplate(), false);
    const playGround = modalContainer.querySelector('#game_playground');

    modalContainer.querySelector('.exitgame__btn').addEventListener('click', () => {
        socketApp.gameClose();
        socketApp.cancelRenderGameApp();
        socketApp.closeAllModal();
    });
    setupInfoAtModal(modalContainer, players);

    socketApp.setGameContainer(modalContainer);
    socketApp.setGameCanvas(playGround);

    playGround.focus();

    playGround.addEventListener('focusout', () => {
        toggleFocusOut(playGround, true);
    });

    playGround.addEventListener('focusin', () => {
        toggleFocusOut(playGround, false);
    })
}

export function openMatchingModal(socketApp, gameType) {
    const modalContainer = modalRender('matching-game', routes['/game'].matchModalTemplate(gameType), false);

    socketApp.matching(gameType);

    modalContainer.querySelector('.matching-game__btn').addEventListener('click', () => {
        closeMatchingModal(modalContainer, socketApp);
    });

    socketApp.setMatchingContainer(modalContainer);
}

export function openBoardModal(socketApp, gameType, players) {
    let modalName;
    let modalHtml;

    if (gameType === GAME_TYPE.TOURNAMENT || gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
        modalName = "tournament";
        modalHtml = routes['/game'].tournamentModalTemplate();
    } else {
        modalName  = "versus";
        modalHtml = routes['/game'].versusModalTemplate();
    }

    const modalContainer = modalRender(modalName, modalHtml, false);

    if (gameType === GAME_TYPE.LOCAL_TWO || gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
        modalContainer.querySelector('.modal__ready-btn').addEventListener('click', () => {
            socketApp.readyToPlay();
        });
    }

    socketApp.setBoardContainer(modalContainer);
    setupInfoAtModal(modalContainer, players, gameType === GAME_TYPE.RANDOM || gameType === GAME_TYPE.LOCAL_TWO);
}

export function closeMatchingModal(matchingContainer, socketApp) {
    socketApp.waitClose();
    matchingContainer.remove();
}

export function setFinalWinnerBoardModal(socketApp, container) {
    const avatar = container.querySelector('.insert-finalAvatar');
    const winnerAvatars = container.querySelectorAll('.insert-winnerAvatar');
    const title = container.querySelector('.tournament__header');

    title.innerText = "Congratulations! You are the winner 🏆";
    winnerAvatars[1].classList.add('loser-avatar');

    avatar.classList.remove('anonymous-avatar');
    setAvatar(player.getProfile(), avatar);

    container.querySelector('.board-modal__info').style.opacity = '0';

    const btn = container.querySelector('.modal__ready-btn');
    btn.innerHTML = '<i class="bi bi-door-closed"></i> Exit';

    btn.onclick = () => {
        socketApp.closeAllModal();
    }

    btn.disabled = false;
    btn.style.opacity = '1';
    container.style.opacity = '1';
}

export function setupNextMatchAtBoardModal(container, includeData) {
    const winnerAvatars = container.querySelectorAll('.insert-winnerAvatar');
    const avatarNodes = container.querySelectorAll('.insert-playerAvatar');

    includeData.includeUser.forEach((winnerData, i) => {
        const {profile} = winnerData;

        if (winnerAvatars[i] !== undefined) {
            winnerAvatars[i].classList.remove('anonymous-avatar');
            setAvatar(profile, winnerAvatars[i]);
        }
    });

    includeData.unIncludeUser.forEach(userData => {
        const { profile_idx } = userData;

        avatarNodes[profile_idx].classList.add('loser-avatar');
    });
}

export function setupInfoAtModal(container, players, setName = true) {
    const avatarNodes = container.querySelectorAll('.insert-playerAvatar');
    const nameNodes = container.querySelectorAll('.insert-playerName');

    players.forEach((playerData, i) => {
        const {profile, nickname} = playerData;

        if (avatarNodes[i] !== undefined) {
            setAvatar(profile, avatarNodes[i]);
            if (setName) {
                nameNodes[i].innerHTML = nickname;
            }
        }
    });
}

export function setupConnectPeopleAtMatchingModal(container, playerNumber) {
    const statusInfo = container.querySelector('.matching-game__status');

    statusInfo.querySelector('span').innerHTML = playerNumber;
}

export function setupDeActiveReadyBtn(container) {
    container.querySelector('.modal__ready-btn').disabled = true;
}

export function setupActiveReadyBtn(container) {
    container.querySelector('.modal__ready-btn').disabled = false;
}

export function changeGiveUpToEnd(container) {
    if (container !== undefined) {
        const giveUpBtn = container.querySelector('.exitgame__btn');

        giveUpBtn.innerHTML = '<i class="bi bi-door-closed"></i> Exit';
    }
}

export function changeEndToNextMatch(container) {
    const endBtn = container.querySelector('.exitgame__btn');

    endBtn.innerHTML = '<i class="bi bi-door-closed"></i> Next Match';
}

export function setInfoMessageAtModal(modalContainer, message, ingAnimation = false) {
    const info = modalContainer.querySelector('.board-modal__info');

    if (ingAnimation) {
        info.classList.add('ingAnimation');
    }

    info.innerHTML = message;
}

function handleLocalGame(socketApp) {
    const modalHtml = routes['/game'].localGameModalTemplate();
    const modalContainer = modalRender('local-play__select', modalHtml, false);
    const modalBtns = modalContainer.querySelectorAll('.game__playbtn');
    
    modalBtns[0].addEventListener('click', () => {
        socketApp.localTwo();
        closeMatchingModal(modalContainer, socketApp);
    });
    modalBtns[1].addEventListener('click', () => {
        const aliasModalTemplate = routes['/game'].localTournamentAliasTemplate();
        const aliasModalContainer = modalRender('local-tournament-alias', aliasModalTemplate, false);
        const aliasModalBtns = aliasModalContainer.querySelectorAll('.matching-game__btn');

        aliasModalBtns[0].addEventListener('click', () => {
            const aliasNames = aliasModalContainer.querySelectorAll('.local-game__alias--input');
            const userList = [];

            for (let i = 0; i < 4; i++) {
                if (aliasNames[i].value.length < 1) {
                    openInfoModal("Alias name is required for every player!");
                    return ;
                }
            }
            
            aliasNames.forEach((aliasName) => {
                const opponent = generateGuest(aliasName.value, userList.map(user => user.profile));
                userList.push(opponent);
            });

            socketApp.localTournament(userList);
            closeMatchingModal(aliasModalContainer, socketApp);
            closeMatchingModal(modalContainer, socketApp);
        })
        aliasModalBtns[1].addEventListener('click', () => {
            closeMatchingModal(aliasModalContainer, socketApp);
        })
    });
    modalContainer.querySelector('.matching-game__btn').addEventListener('click', () => {
        closeMatchingModal(modalContainer, socketApp);
    });
}

export function setLocalNextMatchBoard(boardContainer) {
    const winnerAvatars = boardContainer.querySelectorAll('.insert-winnerAvatar');
    const avatarNodes = boardContainer.querySelectorAll('.insert-playerAvatar');
    
    const winners = JSON.parse(localStorage.getItem("local_tournament"));
    for (let i = 0; i < winners.length; i++) {
        winnerAvatars[i].setAttribute('data-image', winners[i].profile);
        winnerAvatars[i].classList.remove('anonymous-avatar');
    }
    for (let i = 0; i < winners.length * 2; i++) {
        if (avatarNodes[i].getAttribute('data-image') !== winners[i < 2 ? 0 : 1].profile)
            avatarNodes[i].classList.add('loser-avatar');
    }
    boardContainer.style.opacity = '1';
}

export function setLocalFinalBoard(boardContainer, score, socketApp) {
    const winners = JSON.parse(localStorage.getItem("local_tournament"));
    const finalAvatar = boardContainer.querySelector('.insert-finalAvatar');
    const winnerAvatars = boardContainer.querySelectorAll('.insert-winnerAvatar');

    const title = boardContainer.querySelector('.tournament__header');
    title.innerText = "Result of the tournament";

    let winnerIdx;
    score[0] > score[1] ? winnerIdx = 0 : winnerIdx = 1;
    
    winnerAvatars[1 - winnerIdx].classList.add('loser-avatar');

    finalAvatar.classList.remove('anonymous-avatar');
    finalAvatar.setAttribute('data-image', winners[winnerIdx].profile);

    // boardContainer.querySelector('.board-modal__info').style.opacity = '0';

    const btn = boardContainer.querySelector('.modal__ready-btn');
    btn.innerHTML = '<i class="bi bi-door-closed"></i> Exit';
    btn.onclick = () => {
        socketApp.closeAllModal();
    }
    btn.disabled = false;
    btn.style.opacity = '1';

    socketApp.closeGameModal();
    boardContainer.style.opacity = '1';
    socketApp.appearBoardModal();

    localStorage.removeItem("local_tournament");
}

export function handleGameModal() {
    const playBtn = document.querySelectorAll('.game__playbtn');

    playBtn[GAME_TYPE.LOCAL_GAME].addEventListener('click', () => {
        const socketApp = SocketApp;

        if (socketApp.isWaitNextMatch() || socketApp.isGaming() || socketApp.isGameState() === SOCKET_STATE.OPEN || socketApp.isGameState() === SOCKET_STATE.CONNECTING) {
            openInfoModal('you are already in game !');
            return ;
        }
        handleLocalGame(socketApp);
    });

    playBtn[GAME_TYPE.RANDOM].addEventListener('click', () => {
        const socketApp = SocketApp;

        if (socketApp.isWaitNextMatch() || socketApp.isGaming() || socketApp.isGameState() === SOCKET_STATE.OPEN || socketApp.isGameState() === SOCKET_STATE.CONNECTING) {
            openInfoModal('you are already in game!');
            return ;
        }
        openMatchingModal(socketApp, GAME_TYPE.RANDOM);
    });

    playBtn[GAME_TYPE.TOURNAMENT].addEventListener('click', () => {
        const socketApp = SocketApp;

        if (socketApp.isWaitNextMatch() || socketApp.isGaming() || socketApp.isGameState() === SOCKET_STATE.OPEN || socketApp.isGameState() === SOCKET_STATE.CONNECTING) {
            openInfoModal('you are already in game!');
            return ;
        }
        openMatchingModal(socketApp, GAME_TYPE.TOURNAMENT);
    });
}

export function toggleFocusOut(gameContainer, isNotFocus = true) {
    if (gameContainer.querySelector('.game-modal-name__end') !== null) {
        return ;
    }

    if (isNotFocus) {
        const modalContainer = document.createElement('div');
        modalContainer.classList.add('game-modal__container', 'game-modal-name__focus');

        modalContainer.innerHTML = routes['/game'].gameInfoModalTemplate('Out of focus');

        gameContainer.appendChild(modalContainer);
    } else {
        const modalContainer = gameContainer.querySelector('.game-modal__container.game-modal-name__focus');
        if (modalContainer !== null) {
            modalContainer.remove();
        }
    }
}

export function isWin(gamePlayer, score) {
    return (gamePlayer === 1 && score[0] > score[1]) || (gamePlayer === 2 && score[0] < score[1]);
}

export function renderEndStatus(gameContainer, gamePlayer, score, gameType) {
    const modalContainer = document.createElement('div');
    modalContainer.classList.add('game-modal__container', 'game-modal-name__end');

    let status = 'YOU <span class="game-modal__win">WIN!</span>';

    if (gameType === GAME_TYPE.LOCAL_TWO && !localStorage.getItem("local_tournament")) {
        if (score[0] > score[1]) {
            status = `${player.getNickName()} <span class="game-modal__win">WIN!</span>`;
        } else {
            status = `GUEST <span class="game-modal__win">WIN!</span>`;
        }
    } else if (gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
        const players = gameContainer.parentNode.parentNode.querySelectorAll('.playgame__header--profile');
        let winnerIdx = 0;

        if (score[0] > score[1]) {
            status = `${players[0].children[1].innerText} <span class="game-modal__win">WIN!</span>`;
        } else {
            winnerIdx = 1;
            status = `${players[1].children[1].innerText} <span class="game-modal__win">WIN!</span>`;
        }
        let winnerProfile = players[winnerIdx].children[0].getAttribute('data-image');
        let winnerName = players[winnerIdx].children[1].innerText;

        let winners;
        localStorage.getItem("local_tournament") ? winners = JSON.parse(localStorage.getItem("local_tournament")) : winners = [];
        winners.push({profile: winnerProfile, nickname: winnerName});
        localStorage.setItem("local_tournament", JSON.stringify(winners));
    } else {
        if (!isWin(gamePlayer, score)) {
            status = 'YOU <span class="game-modal__lose">LOSE..</span>';
            if (gamePlayer === 2) {
                [score[0], score[1]] = [score[1], score[0]];
            }
        }
    }

    modalContainer.innerHTML = routes['/game'].gameEndModalTemplate(status, score);
    gameContainer.appendChild(modalContainer);
}

export function removeExitBtnInfoModal(container) {
    container.querySelector('.matching-game__btn').remove();
}

export function exitInviteGame(container, socketApp, chatApp, userDetail) {
    container.querySelector('.matching-game__btn').addEventListener('click', () => {
        socketApp.gameClose();
        // TODO: invite Game Cancel event
        chatApp.cancelInviteGame(userDetail.id);
    })
}

export function setCommentInfoModal(container, comment) {
    const commentNode = container.querySelector('.matching-game__wrapper span');

    commentNode.innerHTML = comment;
}

export function openInfoModal(comment, backgroundClick = true) {
    const modalContainer = modalRender('matching-game', routes['/game'].infoModalTemplate(comment), backgroundClick);

    modalContainer.querySelector('.matching-game__btn').addEventListener('click', () => {
        modalContainer.remove();
    });
    return modalContainer;
}