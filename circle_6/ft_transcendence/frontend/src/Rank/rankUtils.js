import {friendModalClick, setAvatar} from "../Profile/modalUtils.js";
import {player} from "../app.js";
import {setFriendItem} from "../Login/loginUtils.js";
import {openInfoModal} from "../Game/gameUtils.js";

function getStageProfile(tier, data, chatApp) {
    const tableNode = document.createElement('div');
    const profileNode = document.createElement('div');

    tableNode.classList.add('rank__stage--table');
    profileNode.classList.add('rank__stage--avatar', `rank__profile--${tier}`);

    setAvatar(data.profile, profileNode);

    profileNode.addEventListener('click', async () => {
        await friendModalClick(data.id, chatApp);
    });

    tableNode.appendChild(profileNode);
    return tableNode;
}

function getRankerItem(rank, data, chatApp) {
    const item = document.createElement('div');
    const rankNode = document.createElement('div');

    item.classList.add('rank__list--item');
    rankNode.classList.add('rank__list--number');

    rankNode.innerHTML = rank;

    item.appendChild(rankNode);
    setFriendItem(chatApp, item, data, false);
    return item;
}

export async function setRankPage(chatApp) {
    try {
        const app = chatApp.getApp();
        const data = await player.getRankerList();
        /*
        * rankerList: [{
        *   id: <int>,
        *   nickname: <string>,
        *   profile: <string>
        * }]
        * */
        const rankerNumber = data.length;
        const rankerStage = app.querySelector(".rank__stage");
        const rankerList = app.querySelector(".rank__list--friends");

        if (rankerNumber >= 2)
            rankerStage.appendChild(getStageProfile('silver', data[1], chatApp));
        if (rankerNumber >= 1)
            rankerStage.appendChild(getStageProfile('gold', data[0], chatApp));
        if (rankerNumber >= 3) {
            rankerStage.appendChild(getStageProfile('bronze', data[2], chatApp));

            for (let i = 3; i < rankerNumber; ++i) {
                rankerList.appendChild(getRankerItem(i + 1, data[i], chatApp));
            }
        }

        if (rankerStage.innerHTML === "")
            rankerStage.innerHTML = `<div class="chat__search--error">
        No ranker presents yet. Be the first ranker!
        </div>`
    } catch (e) {
        openInfoModal(`Something was wrong .. Error code: ${e.error}`);
    }
}
