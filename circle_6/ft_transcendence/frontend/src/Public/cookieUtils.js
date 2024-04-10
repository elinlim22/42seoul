export function getCookie(cname) {
    let name = cname + "=";
    let decodedCookie = decodeURIComponent(document.cookie);
    let ca = decodedCookie.split(';');
    for(let i = 0; i <ca.length; i++) {
        let c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

export function deleteCookie(name) {
    document.cookie = name + "=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
}

export function deleteCookieAll () {
    const cookies = document.cookie.split('; ');
    const expiration = 'Sat, 01 Jan 1972 00:00:00 GMT';

    for (let i = 0; i < cookies.length; i++) {
        document.cookie = cookies[i].split('=')[0] + '=; expires=' + expiration;
    }
}
/*
function moveRefresh() {
    if (getCookie("refresh_token")) {
        const cookies = Object.fromEntries(
            document.cookie.split(';').map((cookie) => cookie.trim().split('=')),
        );
        localStorage.setItem("refresh_token", cookies["refresh_token"]);
        deleteCookie("refresh_token");
    }
}
*/