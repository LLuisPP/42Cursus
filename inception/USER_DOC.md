# User Documentation – Inception

## Overview

This document is intended for end users or administrators who want to run, use, or verify the Inception infrastructure without modifying its internal implementation.

The project deploys a containerized WordPress stack composed of:
- NGINX (HTTPS reverse proxy)
- WordPress with PHP-FPM
- MariaDB database

All services run inside Docker containers and communicate through a private Docker network.

---

## Provided Services

### Website
- A WordPress website served over HTTPS
- Accessible only through NGINX on port 443
- Domain name:
  <login>.42.fr

### Administration Panel
- WordPress admin panel available at:
  https://<login>.42.fr/wp-admin

---

## Starting the Project

### Requirements
- Linux Virtual Machine
- Docker
- Docker Compose
- Make

---

### Environment Configuration

Before starting the project, the environment file must be created.

cp srcs/.env.example srcs/.env

Edit srcs/.env and fill in the required values:
- Database credentials
- WordPress admin and user credentials
- Domain name

The .env file is intentionally not included in the repository for security reasons.

---

### Start the Infrastructure

make

This command:
- Builds all Docker images
- Creates Docker networks and volumes
- Starts all containers

---

## Stopping the Project

To stop all containers:

make down

Volumes are preserved and data remains persistent.

---

## Accessing the Services

### Website Access
Open a browser and navigate to:

https://<login>.42.fr

### WordPress Admin Access
Navigate to:

https://<login>.42.fr/wp-admin

Use the credentials defined in the .env file.

---

## Credentials Management

- Credentials are not stored in the repository
- Sensitive values are provided through:
  - The local .env file
  - Or Docker secrets (if configured)
- The user is responsible for keeping credentials secure

---

## Data Persistence

Data is persisted using Docker volumes:
- WordPress files
- MariaDB database files

Volumes are stored on the host at:

/home/<login>/data

Stopping or rebuilding containers does not erase data.

---

## Verifying the Infrastructure Status

### Check Running Containers

docker ps

All services should be in the Up state.

---

### Check Logs

docker logs nginx
docker logs wordpress
docker logs mariadb

---

### Verify HTTPS

openssl s_client -connect <login>.42.fr:443

The connection must use TLSv1.2 or TLSv1.3.

---

## Restart Policy Verification

To test automatic restart:

docker stop wordpress
docker ps

The container should restart automatically.

---

## Troubleshooting

- Ensure Docker is running
- Verify .env values are correct
- Check container logs for errors
- Make sure port 443 is not already in use

---

## Notes

- Only NGINX is exposed to the host
- Internal services are isolated
- No pre-built Docker images are used
- No insecure or infinite-loop entrypoints are used
