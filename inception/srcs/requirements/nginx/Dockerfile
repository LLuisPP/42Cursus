FROM debian:bullseye

RUN apt-get update && apt-get -y upgrade && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Carpeta para los certificados TLS
RUN mkdir -p /etc/nginx/ssl

# Configuración de nginx
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Script de entrada
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]
