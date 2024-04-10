import {renderMainPage} from "./Login/loginUtils.js";
import Player from "./Login/player.js";
import {getCookie} from './Public/cookieUtils.js';
import ChatApp from "./Chat/chatApp.js";

export const player = Player;

const application = async () => {
    const token = getCookie("access_token");

    if (token) {
        const app = document.getElementById('app');

        await player.whoAmI(token);
        const chatApp = new ChatApp(app);
        player.setChatApp(chatApp);
    }
    await renderMainPage();
}

await application();