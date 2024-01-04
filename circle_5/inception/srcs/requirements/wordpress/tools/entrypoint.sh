#!/bin/sh

if [ ! -e "/var/www/html/wp-config.php" ]; then
	mkdir -p /var/www/html
	cd /var/www/html
	wp core download --allow-root
	wp core config --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_ADMIN_USER --dbpass=$MYSQL_ADMIN_PASSWORD --dbhost=$MYSQL_HOST --skip-check
	wp core install --url="${WP_URL}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN_USER}" --admin_password="${WP_ADMIN_PASSWORD}" --admin_email="${WP_ADMIN_USER}@42.fr" --skip-email
	wp user create "${WP_USER_NAME}" "${WP_USER_NAME}@42.fr" --user_pass="${WP_USER_PASSWORD}"
fi

/usr/sbin/php-fpm81 -F
