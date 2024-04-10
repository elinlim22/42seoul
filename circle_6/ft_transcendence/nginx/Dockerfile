FROM nginx:stable-alpine

RUN apk add openssl gettext

WORKDIR /app

COPY ./docker-entrypoint.sh ./docker-entrypoint.sh
COPY ./global.js ./global.js

CMD ["/bin/sh", "docker-entrypoint.sh"]
