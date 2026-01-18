#!/bin/sh
set -e

cd /var/www/html

until mariadb -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" -e "SELECT 1" >/dev/null 2>&1; do
    echo "MariaDB is not ready yet..."
    sleep 2
done

echo "MariaDB is up."

chown -R www-data:www-data /var/www/html

# Si no hay WordPress instalado, lo instalamos
if [ ! -f wp-config.php ] || [ ! -f wp-load.php ]; then
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

wp option update siteurl "https://$DOMAIN_NAME" --allow-root
wp option update home "https://$DOMAIN_NAME" --allow-root

echo "Starting php-fpm..."
mkdir -p /run/php
exec php-fpm7.4 -F
