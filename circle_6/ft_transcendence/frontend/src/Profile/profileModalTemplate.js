class ProfileModal {
    profileSearchTemplate() {
        return `
        <div class="modal__background"></div>
        <div class="search-friend__container">
            <div class="search-friend__header">Add friend</div>
            <div class="search-friend__body">
                <input class="search-friend__body--input" type="text" placeholder="type nickname here..."/>
                <div class="search-friend__body--list"></div>
            </div>
        </div>
        `;
    }

    template() {
        return `
        <div class="modal__background"></div>
        <div class="profile-modal__container">
            <div class="profile-modal__header">Edit Profile</div>
            <div class="profile-modal__body">
                <div class="profile-modal__body--header">profile</div>
                <div class="profile-modal__body--content">
                    <div class="profile-modal__profile">
                        <div data-image="cat" class="profile-modal__avatar profile-modal__selected-avatar"></div>
                        <div class="profile-modal__profile-name">default</div>
                    </div>
                    <div class="profile-modal__profile">
                        <div data-image="upload" class="profile-modal__avatar"></div>
                        <div class="profile-modal__profile-name">upload</div>
                    </div>
                </div>
                <div class="profile-modal__body--header">nickname</div>
                <div class="profile-modal__body--content">
                    <div class="profile-modal__body--warn"></div>
                    <textarea class="profile-modal__nickname" name="profile-modal__nickname" maxlength="15"></textarea>
                    <div class="profile-modal__text--length"><span>0</span>/15</div>
                </div>
                <div class="profile-modal__body--header">status message</div>
                <div class="profile-modal__body--content">
                    <textarea class="profile-modal__status-message" name="profile-modal__status-message" maxlength="50"></textarea>
                    <div class="profile-modal__text--length"><span>0</span>/50</div>
                </div>
                <div class="profile-modal__body--header"></div>
                <div class="profile-modal__body--content">
                    <div class="profile-modal__big-text">set 2FA by email</div>
                    <div class="profile-modal__toggle-btn">
                        <div class="profile-modal__toggle-item profile-modal__toggle-selected">
                            <i class="bi bi-check-circle"></i>
                        </div>
                        <div class="profile-modal__toggle-item">
                            <i class="bi bi-x-circle"></i>
                        </div>
                    </div>
                </div>
                <button class="profile-modal__save-btn">
                    <i class="bi bi-floppy"></i>
                    save
                </button>
            </div>
        </div>
        `;
    }

    friendModalTemplate() {
        return `
        <div class="modal__background"></div>
        <div class="friend-modal__container">
            <div class="friend-modal__wrapper">
                <div class="friend-modal__box">
                    <div class="friend-modal__avatar"></div>
                    <div class="friend-modal__info">
                        <div class="friend-modal__info--nickname">friend name</div>
                        <div class="friend-modal__info--status">status_message here</div>
                    </div>
                </div>
                <div class="friend-modal__box">
                    <div class="friend-modal__game-info">
                        <div class="friend-modal__game-info--rate">Win rate<span>30%</span></div>
                        <div class="friend-modal__game-info--rank">Rank point<span>3rd</span></div>
                    </div>
                    <div class="friend-modal__controll">
                        <button class="friend-modal__btn">
                            <i class="bi bi-chat-dots"></i>
                            chat
                        </button>
                        <button class="friend-modal__btn">
                            <i class="bi bi-person-plus"></i>
                            add
                        </button>
                    </div>
                </div>
            </div>
            <div class="friend-modal__wrapper">
                <div class="friend-modal__header">Match history</div>
                <div class="friend-modal__history-list">
                </div>
            </div>
        </div>
        `;
    }

    matchHistoryTemplate() {
        return `
        <div class="history-item__day">24/01/26</div>
        <div class="history-item__profiles">
            <div class="history-item__profiles--avatar match-my-avatar"></div>
            <div>vs</div>
            <div class="history-item__profiles--avatar match-your-avatar"></div>
        </div>
        <div class="history-item__score">Score 7 : 3</div>
        <div class="history-item__status">Win</div>
        `;
    }
}


export default new ProfileModal();
