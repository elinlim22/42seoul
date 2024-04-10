const domain = '${DOMAIN}';
const https = 'https://';
const wss = 'wss://';

export const FRONTEND = https + domain;
export const BACKEND = https + domain;;

// Servers
export const USER_SERVER_DOMAIN = https + domain;
export const CHAT_SERVER_DOMAIN = https + domain;
export const GAME_SERVER_DOMAIN = https + domain;

// Domains
export const USER_MANAGEMENT_DOMAIN = 'api/user-management';
export const CHAT_API_DOMAIN = 'api/chatting';
export const GAME_API_DOMAIN = 'api/game';

// Chatting
export const CHAT_WEBSOCKET = wss + domain;
export const GAME_WEBSOCKET = wss + domain;
