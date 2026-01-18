FROM debian:bullseye

RUN apt-get update && apt-get -y upgrade \
    && apt-get install -y \
        php-fpm php-mysql php-cli \
        mariadb-client \
        curl wget \
        ca-certificates \
        bash \
    && sed -i 's|^listen = .*|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html \
    && chown -R www-data:www-data /var/www/html

RUN curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x /usr/local/bin/wp

COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
