#!/bin/sh
set -eu

cd /var/www/html

until mariadb -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" -e "SELECT 1" >/dev/null 2>&1; do
    echo "MariaDB is not ready yet..."
    sleep 2
done

echo "MariaDB is up."

chown -R www-data:www-data /var/www/html

# Install WordPress if not installed
if ! wp core is-installed --allow-root 2>/dev/null; then
    echo "Downloading WordPress..."
    wp core download --allow-root

    echo "Creating wp-config..."
    wp config create --allow-root \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$MYSQL_PASSWORD" \
        --dbhost="$MYSQL_HOST"

    echo "Installing WordPress..."
    wp core install --allow-root \
        --url="$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL"

    echo "Creating normal user..."
    wp user create "$WP_USER" "$WP_USER_EMAIL" --allow-root \
        --user_pass="$WP_USER_PASSWORD" \
        --role=author || true
fi
if [ "$NGINX_PORT" = "443" ]; then
    SITE_URL="https://$DOMAIN_NAME"
else
    SITE_URL="https://$DOMAIN_NAME:$NGINX_PORT"
fi

wp option update siteurl "$SITE_URL" --allow-root
wp option update home "$SITE_URL" --allow-root
#wp option update siteurl "https://$DOMAIN_NAME" --allow-root
#wp option update home "https://$DOMAIN_NAME" --allow-root

#if [ ! -f wp-config.php ]; then
#    echo "Downloading WordPress..."
#    wp core download --allow-root

#    echo "Creating wp-config..."
#    wp config create --allow-root \
#        --dbname="$MYSQL_DATABASE" \
#        --dbuser="$MYSQL_USER" \
#        --dbpass="$MYSQL_PASSWORD" \
#        --dbhost="$MYSQL_HOST"

#    echo "WordPress files ready. Installation will be done via browser."
#fi

echo "Starting php-fpm..."
mkdir -p /run/php
exec php-fpm7.4 -F
