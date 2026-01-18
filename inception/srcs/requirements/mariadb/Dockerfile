FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# IMPORTANTÍSIMO: eliminar la BD creada en build-time
RUN rm -rf /var/lib/mysql/*

# MariaDB listen on all interfaces
RUN sed -i 's/^bind-address.*/bind-address=0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

ENTRYPOINT ["/entrypoint.sh"]

