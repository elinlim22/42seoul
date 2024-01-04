FROM alpine:3.17.5

RUN apk update && apk --no-cache add mariadb mariadb-client tini

RUN mkdir -p /run/mysqld/var/lib/mysql /var/run/mysqld

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

EXPOSE 3306

ENTRYPOINT ["/sbin/tini", "--", "/setup.sh"]
