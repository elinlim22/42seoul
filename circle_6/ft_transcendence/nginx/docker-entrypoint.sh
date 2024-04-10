openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-key.pem \
    -out /etc/ssl/certs/nginx-certificate.pem \
    --subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=cadet" \
    && chown root:root /etc/ssl/private/nginx-key.pem \
    && chmod 600 /etc/ssl/private/nginx-key.pem

envsubst < ./global.js > /usr/share/nginx/html/src/Public/global.js

nginx -g 'daemon off;'
