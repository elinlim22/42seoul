FROM alpine:3.17.5

RUN apk update && apk --no-cache add php81 php81-fpm php81-mysqli php81-iconv php81-phar curl tini

# RUN adduser -S nginx && addgroup -S nginx
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/bin/wp
RUN sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" \
		/etc/php81/php-fpm.d/www.conf && \
	sed -i "s|;cgi.fix_pathinfo=1|cgi.fix_pathinfo=0|g" \
		/etc/php81/php.ini

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/sbin/tini", "--", "./entrypoint.sh"]
