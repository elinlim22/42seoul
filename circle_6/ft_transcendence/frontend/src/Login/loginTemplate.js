class Login {
	template() {
		return `
        <div class="modal__container">
            <div class="login__background"></div>
            <div class="login__container">
                <div class="login__container--header">Pong</div>
                <div class="login__container--body">
                    <div class="login__wrapper--header">Login</div>
                    <div class="login__wrapper--list">
                        <div class="login-btn google">
                            <i class="bi bi-google"></i>
                            <div>google</div>
                        </div>
                        <div class="login-btn intra">
                            <img src="src/assets/42_logo.svg" alt="42logo" />
                            <div>intra</div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
		`;
	}

  twoFATemplate() {
    return `
    <div class="login__body--message">Please enter the 6-digit</div>
    <div class="login__body--message"> code sent to your email.</div>
    <div class="login__body--info"></div>
    <input type="text" class="login__body--input" maxlength="6" />
    <button class="login__2fa-btn" disabled>
      <i class="bi bi-person-check"></i>
      verify
    </button>
    `
  }
}

export default new Login();