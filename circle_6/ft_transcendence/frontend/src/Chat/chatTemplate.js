class Chat {
    chatBoxTemplate(message, time) {
        return `
            <div class="chatbox__message">${message}</div>
            <div class="chatbox__info">${time}</div>
        `;
    }

    systemChatBoxTemplate(message) {
        return `
            <div class="chatbox__system">
                ${ message }            
            </div>
        `;
    }

    systemRoomTemplate(msg, time) {
        return `
            <div class="system-room__profile system__avatar"></div>
            <div class="system-room__contents">
                <div class="system-room__name">System</div>
                <div class="system-room__msg">${msg}</div>
            </div>
            <div class="system-room__info">
                <div class="system-room__alert"></div>
                <div class="system-room__time">${time}</div>
            </div>
        `;
    }

    chatRoomTemplate(name, msg, time) {
        return `
            <div class="chat__empty"></div>
            <div class="chat__room--profile"></div>
            <div class="chat__room--contents">
                <div class="chat__room--name">${name}</div>
                <div class="chat__room--msg">${msg}</div>
            </div>
            <div class="chat__room--info">
                <div class="chat__room--alert"></div>
                <div class="chat__room--time">${time}</div>
            </div>
        `;
    }

    template() {
        return `
		<form class="chat__search">
			<input id="chat__search--input" type="text" placeholder="type nickname here..."/>
			<button class="chat__search--btn">
			    <i class="bi bi-search"></i>
			    search
            </button>
		</form>
		    <div class="chat__room--list"></div>
        </div>
		`;
    }

	modalTemplate() {
		return `
            <div class="modal__background"></div>
            <div class="chat__container modal__fade-in-modal">
                <div class="chat__header">
                    <div class="chat__header--profile">
                        <div class="chat__header--avatar"></div>
                        <div class="chat__header--name">friend</div>
                    </div>
                    <div class="chat__header--controlls">
                        <button class="chat__header--btn">
                            <i class="bi bi-controller"></i>
                            invite
                        </button>
                        <button class="chat__header--btn block">
                            <i class="bi bi-person-slash"></i>
                            Block
                        </button>
                    </div>
                </div>
                <div class="chat__body">
                    <div class="chat__body--frame">
                    </div>
                    <div class="chat__body--controller">
                        <div class="chat__controller--text">
                            <textarea class="chat__body--text" placeholder="type something.."></textarea>
                        </div>
                        <div class="chat__controller--btn">
                            <button class="chat__send--btn">
                                <i class="bi bi-send"></i>
                                send
                            </button>
                        </div>
                    </div>
                </div>
            </div>
		`;
	}

    chatAlertTemplate(name, msg, time) {
        return `
            <div class="chat__alert--icon"></div>
            <div class="chat__alert--contents">
                <div class="chat__alert--title">${name}</div>
                <div class="chat__alert--text">${msg}</div>
            </div>
            <div class="chat__alert--time">${time}</div>
            <button class="chat__alert--close-btn">X</button>
        `;
    }
}

export default new Chat();