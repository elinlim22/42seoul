import Home from "./Home/homeTemplate.js";
import Chat from "./Chat/chatTemplate.js";
import Game from "./Game/gameTemplate.js";
import Rank from "./Rank/rankTemplate.js";
import { setChatPage } from "./Chat/chatPageUtils.js";
import { handleGameModal } from "./Game/gameUtils.js";
import { setRankPage } from "./Rank/rankUtils.js";
import { player } from "./app.js";

export const routes = {
    "/home": Home,
	"/chat": Chat,
    "/game": Game,
    "/rank": Rank,
}

const changeUrl = (requestedUrl, doPush = true) => {
    const app = document.getElementById('app');
    const headerElements = app.querySelectorAll(".main-section__list--item");
    headerElements.forEach(nav => {
        if (nav.classList.contains("active"))
            nav.classList.remove("active");
    });

    try {
        headerElements[Object.keys(routes).indexOf(requestedUrl)].classList.add("active");
    } catch (e) {
        // 이상한 주소로 접근
        console.log(`requested url doesn't exist, you are redirected to main page`);
        headerElements[0].classList.add("active");
        requestedUrl = "/home";
        history.replaceState(requestedUrl, null, requestedUrl);
    }
    const main = app.querySelector(".main-section__main");
    main.innerHTML = routes[requestedUrl].template();

    if (doPush)
        history.pushState(requestedUrl, null, requestedUrl);
}
export default changeUrl;

export async function setPages(chatApp) {
    const requestedUrl = window.location.pathname;
    changeUrl(requestedUrl, false);

    if (requestedUrl === "/chat")
        await setChatPage(chatApp);
    else if (requestedUrl === "/game")
        handleGameModal();
    else if (requestedUrl === "/rank")
        await setRankPage(chatApp);
}

window.addEventListener("popstate", async () => await setPages(player.getChatApp()));