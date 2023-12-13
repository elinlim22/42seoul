FROM alpine:3.17.5

RUN apk update && apk --no-cache add nginx openssl tini

RUN mkdir -p /etc/nginx/ssl
RUN openssl	req -new -newkey rsa:4096 -x509 -sha256 -days 365 \
			-nodes -out /etc/nginx/ssl/nginx-ssl.crt \
			-keyout /etc/nginx/ssl/nginx-ssl.key \
			-subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=42/OU=42Seoul/CN=hyeslim.42.fr"

COPY ./conf/nginx.conf /etc/nginx/http.d/default.conf

EXPOSE 443

ENTRYPOINT ["/sbin/tini", "--"]
CMD ["nginx", "-g", "daemon off;"]
