#!/bin/sh
set -e

# Generar certificado TLS si no existe
if [ ! -f /etc/nginx/ssl/server.key ] || [ ! -f /etc/nginx/ssl/server.crt ]; then
    echo "Generating self-signed certificate for ${DOMAIN_NAME}..."
    openssl req -x509 -nodes -days 365 \
        -subj "/C=ES/ST=Barcelona/L=Barcelona/O=42/OU=Inception/CN=${DOMAIN_NAME}" \
        -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/server.key \
        -out /etc/nginx/ssl/server.crt
fi

echo "Starting nginx..."
exec nginx -g "daemon off;"
