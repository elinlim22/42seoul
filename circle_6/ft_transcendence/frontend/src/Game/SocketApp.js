import {
    closeMatchingModal,
    openPlayGameModal,
    openBoardModal,
    openInfoModal,
    setupConnectPeopleAtMatchingModal,
    changeGiveUpToEnd,
    changeEndToNextMatch,
    renderEndStatus,
    setupActiveReadyBtn,
    setInfoMessageAtModal,
    getInfoPlayerList,
    generateGuest,
    orderPlayers,
    exitInviteGame,
    toggleFocusOut,
    setLocalNextMatchBoard,
    setLocalFinalBoard,
    setupNextMatchAtBoardModal,
    setFinalWinnerBoardModal,
    getPlayerIdxInPlayerList,
    isWin
} from "./gameUtils.js";
import GameApp from "./gameApp.js";
import { GAME_TYPE } from "./gameTemplate.js";
import {player} from "../app.js";
import { GAME_WEBSOCKET } from '../Public/global.js';

export const SOCKET_STATE = {
    CONNECTING: 0,
    OPEN: 1,
    CLOSING: 2,
    CLOSED: 3,
}

class SocketApp {
    constructor() {
        this._waitSocket = undefined;
        this._gameSocket = undefined;

        this._matchingContainer = undefined;
        this._boardContainer = undefined;
        this._gameContainer = undefined;

        this._gameCanvas = undefined;

        this._allPlayerList = undefined;
        this._gaming = false;
        this._waitNextMatch = false;
        this._round = 0;
    }

    readyToPlay() {
        const data = {
            'token': player._token
        }
        if (this.isGameState() === SOCKET_STATE.OPEN) {
            this._gameSend(data);
        }
    }

     matching(gameType) {
        let gameTypeUrl;

        if (gameType === GAME_TYPE.RANDOM) {
            gameTypeUrl = "random";
        } else if (gameType === GAME_TYPE.TOURNAMENT) {
            gameTypeUrl = "tournament";
        }

        const waitSocket = new WebSocket(`${GAME_WEBSOCKET}/ws/game/waitingroom/${gameTypeUrl}/`);

        waitSocket.addEventListener('message', async e => {
            const data = JSON.parse(e.data);

            const {
                type,
                room_id,
                player: playerNumber,
                user_ids,
                waiting_number
            } = data;

            if (room_id !== undefined) {
                let userList= await getInfoPlayerList(user_ids);
                userList = orderPlayers(playerNumber, userList);

                this._allPlayerList = userList;
                openBoardModal(this, gameType, userList);
                this._boardContainer.querySelector('.modal__ready-btn').style.opacity = '0';
                this._enterGameRoom(room_id, gameType, userList);
            } else if (type === "send_waiting_number") {
                setupConnectPeopleAtMatchingModal(this._matchingContainer, waiting_number);
            }
        });

        waitSocket.onopen = () => {
            const data = {
                'token': player._token
            }

            this._waitSend(data);
        }

        waitSocket.onerror = () => {
            openInfoModal('There was a problem with the game server.');
        }

        waitSocket.onclose = () => {
            closeMatchingModal(this._matchingContainer, this);
        }

        this._waitSocket = waitSocket;
    }

    nextMatch(room_id, opponentId) {
        const includeData = getPlayerIdxInPlayerList([player.getId(), opponentId], this._allPlayerList);
        setupNextMatchAtBoardModal(this._boardContainer, includeData);
        this._boardContainer.style.opacity = '1';

        this._enterGameRoom(room_id, GAME_TYPE.TOURNAMENT, includeData.includeUser);
    }

    finalWinner() {
        setFinalWinnerBoardModal(this, this._boardContainer);
    }

    localTwo(playerInfo = player.getInfo(), guestInfo = generateGuest('GUEST', [player.getProfile()])) {
        const userList = [playerInfo, guestInfo];

        openBoardModal(this, GAME_TYPE.LOCAL_TWO, userList);
        this._enterGameRoom(`local/${crypto.randomUUID()}`, GAME_TYPE.LOCAL_TWO, userList);
    }

    localTournament(userList) {
        if (localStorage.getItem("local_tournament"))
            localStorage.removeItem("local_tournament");

        this._allPlayerList = userList;
        openBoardModal(this, GAME_TYPE.LOCAL_TOURNAMENT, userList);
        this._enterGameRoom(`local/${crypto.randomUUID()}`, GAME_TYPE.LOCAL_TOURNAMENT, userList);
    }

    inviteGameRoom(room_id, userList, chatApp) {
        const gameSocket = new WebSocket(`${GAME_WEBSOCKET}/ws/game/${room_id}/`);
        console.log(`enter the room id: ${room_id}`);

        this._matchingContainer = openInfoModal('Waiting for user', false);
        this._matchingContainer.querySelector('.matching-game__wrapper span').classList.add('ingAnimation');
        exitInviteGame(this._matchingContainer, this, chatApp, userList[1]);

        gameSocket.addEventListener('message', async e => {
            const data = JSON.parse(e.data);

            if (data.type === 'send_system_message') {
                if (data.message === 'Game Ready') {
                    if (data.counter === 10) {
                        this._matchingContainer.remove();
                        this._matchingContainer = undefined;

                        openBoardModal(this, GAME_TYPE.RANDOM, userList);
                        this._boardContainer.querySelector('.modal__ready-btn').remove();
                    } else if (5 < data.counter) {
                        setInfoMessageAtModal(this._boardContainer, data.counter - 5);
                    } else if (data.counter === 5) {
                        openPlayGameModal(this, userList);
                        this._gameApp = new GameApp(this._gameCanvas, GAME_TYPE.RANDOM);
                        this._gameApp.setPlayer(data.player);

                        this._boardContainer.opacity = 0;

                        this._gameApp.renderCounter(data.counter);
                    } else if (data.counter < 5) {
                        this._gameApp.renderCounter(data.counter);
                    }
                } else if (data.message === 'Game Start') {
                    this._gameApp.renderCounter(data.counter);

                    this._gameContainer.addEventListener('keydown', e => {
                        if (e.key === 'ArrowLeft') this._gameSend({'move': 'up'});
                        else if (e.key === 'ArrowRight') this._gameSend({'move': 'down'});
                    });

                    this._gameContainer.addEventListener('keyup', e => {
                        if (e.key === 'ArrowLeft' || e.key === 'ArrowRight') this._gameSend({'move': 'stop'});
                    });
                } else if (data.message === 'Game End') {
                    toggleFocusOut(this._gameCanvas, false);
                    renderEndStatus(this._gameCanvas, this._gameApp.getPlayer(), data.score, GAME_TYPE.RANDOM);
                    changeGiveUpToEnd(this._gameContainer);
                    this._gaming = false;
                }
            } else if (data.type === 'send_game_status') {
                this._gameApp.dataRander(data);
            }
        });

        gameSocket.onopen = () => {
            this.readyToPlay();
            this._gaming = true;
        }

        gameSocket.onerror = () => {
            this._matchingContainer.remove();
            this.gameClose();
            openInfoModal('There was a problem with the game server.');
        }

        gameSocket.onclose = () => {
            this._gaming = false;
        }

        this._gameSocket = gameSocket;
    }

    _enterGameRoom(room_id, gameType, userList) {
        const gameSocket = new WebSocket(`${GAME_WEBSOCKET}/ws/game/${room_id}/`);
        console.log(`enter the room id: ${room_id}`);

        gameSocket.addEventListener('message', async e => {
            const data = JSON.parse(e.data);

            if (data.type === 'send_system_message') {
                if (data.message === 'Game Ready') {
                    if (data.counter === 10) {
                        this._round += 1;
                        this._waitNextMatch = false;
                        setInfoMessageAtModal(this._boardContainer, data.counter - 5);
                    } else if (5 < data.counter) {
                        setInfoMessageAtModal(this._boardContainer, data.counter - 5);
                    } else if (data.counter === 5) {
                        openPlayGameModal(this, userList);
                        this._gameApp = new GameApp(this._gameCanvas, gameType);
                        this._gameApp.setPlayer(data.player);

                        this._boardContainer.style.opacity = '0';

                        this._gameApp.renderCounter(data.counter);
                    } else if (data.counter < 5) {
                        this._gameApp.renderCounter(data.counter);
                    }
                } else if (data.message === 'Game Start') {
                    if (gameType === GAME_TYPE.LOCAL_TWO || gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
                        openPlayGameModal(this, userList);
                        changeGiveUpToEnd(this._gameContainer);
                        this._gameApp = new GameApp(this._gameCanvas, gameType);
                        this._gameApp.setPlayer(2);

                        this._boardContainer.style.opacity = 0;

                        this._gameContainer.addEventListener('keydown', e => {
                            if (e.key === 'ArrowDown') this._gameSend({'player': 2, 'move': 'up'});
                            else if (e.key === 'ArrowUp') this._gameSend({'player': 2, 'move': 'down'});
                            else if (e.keyCode === 83) this._gameSend({'player': 1, 'move': 'up'});
                            else if (e.keyCode === 87) this._gameSend({'player': 1, 'move': 'down'});
                        });

                        this._gameContainer.addEventListener('keyup', e => {
                            if (e.key === 'ArrowDown' || e.key === 'ArrowUp') this._gameSend({'player': 2, 'move': 'stop'});
                            else if (e.keyCode === 83 || e.keyCode === 87) this._gameSend({'player': 1, 'move': 'stop'});
                        });
                    } else {
                        this._gameApp.renderCounter(data.counter);

                        this._gameContainer.addEventListener('keydown', e => {
                            if (e.key === 'ArrowLeft') this._gameSend({'move': 'up'});
                            else if (e.key === 'ArrowRight') this._gameSend({'move': 'down'});
                        });

                        this._gameContainer.addEventListener('keyup', e => {
                            if (e.key === 'ArrowLeft' || e.key === 'ArrowRight') this._gameSend({'move': 'stop'});
                        });
                    }
                } else if (data.message === 'Game End') {
                    if (gameType === GAME_TYPE.TOURNAMENT && this._round === 1 && isWin(this._gameApp.getPlayer(), data.score))
                        this._waitNextMatch = true;
                    else if (gameType === GAME_TYPE.LOCAL_TWO && localStorage.getItem("local_tournament")) // local_tournament final round
                        setLocalFinalBoard(this._boardContainer, data.score, this);
                    toggleFocusOut(this._gameCanvas, false);
                    renderEndStatus(this._gameCanvas, this._gameApp.getPlayer(), data.score, gameType);
                    changeGiveUpToEnd(this._gameContainer);
                    this._gaming = false;
                    if (gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
                        changeEndToNextMatch(this._gameContainer);
                        this._waitNextMatch = true;
                        this._gameContainer.querySelector('.exitgame__btn').onclick = () => {
                            this.gameClose();
                            this.cancelRenderGameApp();
                            this.closeAllModal(); // waitNextMatch === true => userList 초기화 안됨

                            setLocalNextMatchBoard(this._boardContainer);
                            this.appearBoardModal();
                            this._waitNextMatch = false; // exit버튼 시 나가게 하려고 false로 변경

                            if (JSON.parse(localStorage.getItem("local_tournament")).length === 2)
                                this._enterGameRoom(`local/${crypto.randomUUID()}`, GAME_TYPE.LOCAL_TWO, [JSON.parse(localStorage.getItem("local_tournament"))[0], JSON.parse(localStorage.getItem("local_tournament"))[1]]);
                            else
                                this._enterGameRoom(`local/${crypto.randomUUID()}`, GAME_TYPE.LOCAL_TOURNAMENT, userList.slice(-2));
                        };
                    }
                }
            } else if (data.type === 'send_game_status') {
                this._gameApp.dataRander(data);
            }
        });

       gameSocket.onopen = () => {
           if (gameType === GAME_TYPE.LOCAL_TWO || gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
               setupActiveReadyBtn(this._boardContainer);
           } else {
               this.readyToPlay();
           }
           this._gaming = true;
       }

       gameSocket.onerror = () => {
           this._boardContainer.remove();
           this.gameClose();
           openInfoModal('There was a problem with the game server.');
       }

       gameSocket.onclose = () => {
           this._gaming = false;
       }

        this._gameSocket = gameSocket;
    }

    _waitSend(data) {
        this._waitSocket.send(JSON.stringify(data));
    }

    isWaitState() {
        if (this._waitSocket !== undefined)
            return this._waitSocket.readyState;
        return SOCKET_STATE.CLOSED;
    }

    waitClose() {
        if (this.isWaitState() === SOCKET_STATE.OPEN || this.isWaitState() === SOCKET_STATE.CONNECTING) {
            this._waitSocket.close();
        }
    }

    _gameSend(data) {
        if (this.isGameState() === SOCKET_STATE.OPEN) {
            this._gameSocket.send(JSON.stringify(data));
        }
    }

    appearBoardModal() {
        if (this._boardContainer !== undefined) {
            this._boardContainer.style.display = '';
        }
    }

    closeGameModal() {
        if (this._gameContainer !== undefined) {
            this._gameContainer.remove();
        }
        this._gameContainer = undefined;
    }

    closeAllModal() {
        if (this._gameContainer !== undefined) {
            this._gameContainer.remove();
        }

        if (this.isGaming() || this.isWaitNextMatch()) {
            if (this._boardContainer !== undefined) {
                this._boardContainer.style.display = 'none';
            }
            return ;
        }
        this._gameContainer = undefined;
        if (this._boardContainer !== undefined) {
            this._boardContainer.remove();
        }
        this._boardContainer = undefined;
        if (this._matchingContainer !== undefined) {
            this._matchingContainer.remove();
        }
        this._matchingContainer = undefined;

        this._gameCanvas = undefined;
        this._allPlayerList = undefined;
        this._gaming = false;
        this._waitNextMatch = false;
        this._round = 0;
    }

    isGaming() {
        return this._gaming;
    }

    isWaitNextMatch() {
        return this._waitNextMatch;
    }

    isGameState() {
        if (this._gameSocket !== undefined)
            return this._gameSocket.readyState;
        return SOCKET_STATE.CLOSED;
    }

    gameClose() {
        if (this.isGameState() === SOCKET_STATE.OPEN || this.isGameState() === SOCKET_STATE.CONNECTING) {
            this._gameSocket.close();
        }
    }

    cancelRenderGameApp() {
        this._gameApp.cancelRender();
    }

    setGameContainer(gameContainer) {
        this._gameContainer = gameContainer;
    }

    setMatchingContainer(matchingContainer) {
        this._matchingContainer = matchingContainer;
    }

    setBoardContainer(boardContainer) {
        this._boardContainer = boardContainer;
    }

    setGameCanvas(gameCanvas) {
        this._gameCanvas = gameCanvas;
    }
}

export default new SocketApp();
