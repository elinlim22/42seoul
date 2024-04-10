class Home {
	template() {
		return `
		<div class="home__header">
            <div class="home__header--text">Welcome to Pong Beat Makers!</div>
        </div>
        <div class="home__body">
            <div class="home__body--half left">
                <div class="home__body--box">
                    <div class="home__body--box-title">Keys</div>
                    <div class="home__body--box-container">
                        <div class="home__body--box-contents">
                            <div class="home__body--box-pic wasd"></div>
                            <div class="home__body--box-text">left user</div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-pic arrow"></div>
                            <div class="home__body--box-text">right user(or yourself)</div>
                        </div>
                    </div>
                </div>
                <div class="home__body--box">
                    <div class="home__body--box-title">Rank</div>
                    <div class="home__body__rank-contents">Participate in Tournaments to get Rank points!</div>
                    <div class="home__body__rank-contents--detail">1st: +40 points</div>
                    <div class="home__body__rank-contents--detail">2nd: +20 points</div>
                    <div class="home__body__rank-contents--detail">3rd or lower: -20 points</div>
                </div>
                <div class="home__footer">
                    <div>Team Pong-Beat-Makers of 42 Seoul</div>
                    <div>Contributers: hyeslim, isunwoo, jeelee, naki, youngmch</div>
                </div>
            </div>
            <div class="home__body--half">
                <div class="home__body--box">
                    <div class="home__body--box-title">How to add friends</div>
                    <div class="home__body--box-container">
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">1. click</div>
                            <div class="home__body--box-pic-mini add-friend-one"></div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">2. search</div>
                            <div class="home__body--box-pic add-friend-two"></div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">3. add</div>
                            <div class="home__body--box-pic add-friend-three"></div>
                        </div>
                    </div>
                </div>
                <div class="home__body--box">
                    <div class="home__body--box-title">How to start a new chat</div>
                    <div class="home__body--box-container">
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">1. select</div>
                            <div class="home__body--box-pic new-chat-one"></div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">2. click</div>
                            <div class="home__body--box-pic add-friend-three"></div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">3. later you can find the chatting room in the chat tab!</div>
                            <div class="home__body--box-pic-mini new-chat-three"></div>
                        </div>
                    </div>
                </div>
                <div class="home__body--box">
                    <div class="home__body--box-title">How to set 2FA</div>
                    <div class="home__body--box-container">
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">1. click</div>
                            <div class="home__body--box-pic-mini set-2fa-one"></div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">2. choose & save</div>
                            <div class="home__body--box-pic set-2fa-two"></div>
                        </div>
                        <div class="home__body--box-contents">
                            <div class="home__body--box-text">3. later when you log in, a 6-digit code will be sent to your email!</div>
                            <div class="home__body--box-pic set-2fa-three"></div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
		`;
	}
}

export default new Home();