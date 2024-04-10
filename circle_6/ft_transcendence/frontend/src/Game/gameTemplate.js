export const GAME_TYPE = {
	LOCAL_GAME: 0,
	RANDOM: 1,
	TOURNAMENT: 2,
	LOCAL_TWO: 3,
	LOCAL_TOURNAMENT: 4
}

class Game {
	template() {
		return `
		<div class="game__header">Select Match type</div>
		<div class="game__body">
				<div class="game__playbtn">
						<div class="game__playbtn--picture">
								<i class="bi bi-people"></i>
						</div>
						<div class="game__playbtn--text">Local game</div>
				</div>
				<div class="game__playbtn">
						<div class="game__playbtn--picture">
								<i class="bi bi-lightning"></i>
						</div>
						<div class="game__playbtn--text">Random</div>
				</div>
				<div class="game__playbtn">
						<div class="game__playbtn--picture">
								<i class="bi bi-trophy"></i>
						</div>
						<div class="game__playbtn--text">Tournament</div>
				</div>
		</div>
		<div class="game__header">How to play 1:1 game with friend</div>
		<div class="game__body">
				<div class="game__manual">
						<div class="game__manual--text">1. Select a friend from the friends list</div>
						<div class="game__manual--picture new-chat-one"></div>
				</div>
				<div class="game__manual">
						<div class="game__manual--text">2. Click “chat” button</div>
						<div class="game__manual--picture add-friend-three"></div>
				</div>
				<div class="game__manual">
						<div class="game__manual--text">3. Click “invite” button</div>
						<div class="game__manual--picture howto-game-three"></div>
				</div>
		</div>
		`;
	}

	playGameTemplate() {
		return `
			<div class="modal__background"></div>
			<div class="modal__playgame--background"></div>
			<div class="playgame__wrapper">
				<div class="playgame__header">
					<div class="playgame__header--profile">
					<div class="playgame__header--avatar insert-playerAvatar"></div>
					<div class="playgame__header--name insert-playerName">Player1</div>
					</div><div class="playgame__header--profile">
					<div class="playgame__header--avatar insert-playerAvatar"></div>
					<div class="playgame__header--name insert-playerName">Player2</div>
					</div>
				</div>
				<div class="playgame__body">
					<div id="game_playground" tabindex="0"></div>
					<button class="modal__btn exitgame__btn">
						<i class="bi bi-flag"></i>
						give up
					</button>
				</div>
			</div>
		`
	}

	matchModalTemplate(type) {
		let comment = "Searching for a match .";
		let peoples = "";

		if (type === GAME_TYPE.TOURNAMENT) {
			comment = "Searching for a tournament .";
			peoples = `<div class="matching-game__status">
						(<span>1</span> / 4)
						</div>`;
		}
		return `
            <div class="modal__background"></div>
            <div class="matching-game__wrapper modal__fade-in-modal">
            	<span class="ingAnimation">${ comment }</span>
            	${ peoples }
                <button class="modal__btn matching-game__btn">
                    <i class="bi bi-x-square"></i>
                    cancel & exit
                </button>
            </div>
        `;
	}

	versusModalTemplate() {
		return `
			<div class="modal__background"></div>
			<div class="modal__playgame--background modal__fade-in-modal"></div>
			<div class="versus-modal__wrapper">
				<div class="versus-modal__header">Get ready for the match!</div>
				<div class="versus-modal__body">
					<div class="versus-modal__profile">
						<div class="versus-modal__avatar insert-playerAvatar"></div>
						<div class="versus-modal__name insert-playerName">Player 1</div>
					</div>
					<div class="versus-modal__versus">vs</div>
					<div class="versus-modal__profile">
						<div class="versus-modal__avatar insert-playerAvatar"></div>
						<div class="versus-modal__name insert-playerName">Player 2</div>
					</div>
					<div class="board-modal__info"></div>
					<button class="modal__btn versus-modal__btn modal__ready-btn" disabled>
						<i class="bi bi-check-square"></i>
						ready
					</button>
				</div>
			</div>
		`;
	}

	tournamentModalTemplate() {
		return `
			<div class="modal__background"></div>
			<div class="modal__playgame--background"></div>
			<div class="tournament__wrapper">
				<div class="tournament__header">Knockout Rounds Bracket</div>
				<div class="tournament__body">
					<div class="tournament__layer">
						<div class="tournament__avatar tournament__champion anonymous-avatar insert-finalAvatar"></div>
					</div>
					<div class="tournament__layer">
						<div class="tournament__versus">
							<div class="tournament__avatar anonymous-avatar insert-winnerAvatar"></div>
							<div class="tournament__avatar anonymous-avatar insert-winnerAvatar"></div>
						</div>
					</div>
					<div class="tournament__layer">
						<div class="tournament__versus">
							<div class="tournament__avatar insert-playerAvatar"></div>
							<div class="tournament__avatar insert-playerAvatar"></div>
						</div>
						<div class="tournament__versus">
							<div class="tournament__avatar insert-playerAvatar"></div>
							<div class="tournament__avatar insert-playerAvatar"></div>
						</div>
					</div>
					<div class="tournament__controller">
						<div class="board-modal__info"></div>
						<button class="modal__btn tournament__btn modal__ready-btn" disabled>
							<i class="bi bi-check-square"></i>
							ready
						</button>
					</div>
				</div>
			</div>
		`;
	}

	gameEndModalTemplate(status, score) {
		return `
			<div class="game-modal__background"></div>
			<div class="game-modal__wrapper">
				<div class="game-modal__status">${ status }</div>
				<div class="game-modal__score">${score[0]}:${score[1]}</div>
			</div>
		`;
	}

	gameInfoModalTemplate(message) {
		return `
			<div class="game-modal__background light"></div>
			<div class="game-modal__message">Out of focus.</div>
		`;
	}

	infoModalTemplate(comment) {
		return `
            <div class="modal__background"></div>
            <div class="matching-game__wrapper modal__fade-in-modal">
            	<span>${ comment }</span>
                <button class="modal__btn matching-game__btn">
                    <i class="bi bi-x-square"></i>
                    cancel & exit
                </button>
            </div>
        `;
	}

	localGameModalTemplate() {
		return `
            <div class="modal__background"></div>
            <div class="local-game__wrapper">
				<div class="local-game__title">Select local game type</div>
				<div class="game__playbtn__wrapper">
					<div class="game__playbtn">
						<div class="game__playbtn--picture">
								<i class="bi bi-people"></i>
						</div>
						<div class="game__playbtn--text">2 Players</div>
					</div>
					<div class="game__playbtn">
						<div class="game__playbtn--picture">
								<i class="bi bi-trophy"></i>
						</div>
						<div class="game__playbtn--text">Local Tournament</div>
					</div>
				</div>
                <button class="modal__btn matching-game__btn">
                    <i class="bi bi-x-square"></i>
                    cancel & exit
                </button>
            </div>
        `;
	}

	localTournamentAliasTemplate() {
		return `
            <div class="modal__background"></div>
            <div class="local-game__wrapper">
				<div class="local-game__title">Set alias names for tournament!</div>
				<div class="local-game__input__wrapper">
					<input class="local-game__alias--input" type="text" placeholder="guest1"/>
					<input class="local-game__alias--input" type="text" placeholder="guest2"/>
				</div>
				<div class="local-game__input__wrapper">
					<input class="local-game__alias--input" type="text" placeholder="guest3"/>
					<input class="local-game__alias--input" type="text" placeholder="guest4"/>
				</div>
				<button class="modal__btn matching-game__btn local-game__alias__btn">
					<i class="bi bi-check-square"></i>
					ready
				</button>
				<button class="modal__btn matching-game__btn">
					<i class="bi bi-x-square"></i>
					cancel & exit
				</button>
            </div>
        `;	
	}
}

export default new Game();