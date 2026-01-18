# Developer Documentation – Inception

## Purpose

This document is intended for developers who want to understand, modify, or extend the Inception project.
It describes the internal architecture, design choices, and technical implementation details.

This document complements USER_DOC.md and focuses on how the project is built rather than how it is used.

---

## Project Overview

The project implements a containerized WordPress infrastructure using Docker and Docker Compose.
All services are built from custom Dockerfiles and run inside a Linux Virtual Machine, as required by the subject.

The infrastructure is composed of:
- NGINX (reverse proxy with TLS)
- WordPress (PHP-FPM)
- MariaDB (database)
- Docker network for internal communication
- Docker volumes for persistent data

## Repository Structure

```
.
├── Makefile
├── USER_DOC.md
├── DEV_DOC.md
├── srcs/
│   ├── docker-compose.yml
│   └── requirements/
│       ├── mariadb/
│       │   ├── Dockerfile
│       │   └── tools/entrypoint.sh
│       ├── nginx/
│       │   ├── Dockerfile
│       │   ├── conf/nginx.conf
│       │   └── tools/entrypoint.sh
│       └── wordpress/
│           ├── Dockerfile
│           └── tools/entrypoint.sh
```

---

## Makefile

The Makefile is the main entry point for managing the project lifecycle.
It wraps Docker Compose commands to provide a simple and reproducible workflow.

Typical targets:
- `make` : build images and start the infrastructure
- `make down` : stop containers without removing volumes
- `make re` : rebuild images and restart the infrastructure
- `make clean` : stop containers and remove volumes (if implemented)

Using a Makefile ensures consistent commands during development and evaluation.


## Docker Compose

The `docker-compose.yml` file defines:
- Services
- Networks
- Volumes
- Restart policies
- Environment variables

### Services

Each service:
- Uses a custom Dockerfile
- Runs in its own container
- Is connected to a private Docker network
- Uses restart policies to ensure resilience

No service uses the `latest` tag or pre-built images.

---

## Networking

A dedicated Docker network is used to connect containers.

- Containers communicate using service names
- No usage of `network: host`, `--link`, or `links`
- Only NGINX exposes port 443 to the host
- Internal service ports are not exposed

This design ensures isolation and security.


## Volumes and Data Persistence

Two Docker volumes are defined:
- One for WordPress files
- One for MariaDB database data

Volumes are mounted under:

```
/home/<login>/data
```

This guarantees data persistence across container restarts and rebuilds.


## Service Implementation Details

### NGINX

- Acts as the only public entry point
- Configured with a custom `nginx.conf`
- Uses TLSv1.2 or TLSv1.3 only
- Proxies requests to WordPress via PHP-FPM
- Runs in the foreground as PID 1

### WordPress

- Runs using PHP-FPM only
- No embedded web server
- WordPress is configured dynamically at startup
- Initialization is handled via `entrypoint.sh`

### MariaDB

- Runs only the database service
- No additional services or web servers
- Database initialization is handled via `entrypoint.sh`
- Users and databases are created at runtime



## Entrypoint Scripts

Each service includes an `entrypoint.sh` script.

Responsibilities:
- Perform initialization tasks
- Configure services dynamically
- Ensure correct permissions
- Launch the main process as PID 1

Entrypoints do not use:
- Infinite loops
- `tail -f`
- `sleep infinity`
- Background daemons

This follows Docker best practices and subject requirements.



## Environment Variables

Environment variables are used to configure services dynamically.

- Defined in `.env` (not versioned)
- `.env.example` is provided as a template
- Sensitive values are not stored in the repository

This allows environment-specific configuration without modifying code.



## Docker Secrets (Optional)

Docker secrets are not required for the mandatory part.

The project structure allows secrets to be added if needed:
- Stored outside the repository
- Mounted securely at runtime

This keeps the mandatory setup simple while remaining extensible.



## Extending the Project

The project can be extended by:
- Adding bonus services
- Defining additional Dockerfiles
- Updating Docker Compose configuration

Each new service must:
- Use a dedicated Dockerfile
- Run in its own container
- Respect the existing networking and security rules



## Notes

- All images are built locally
- No credentials are committed to the repository
- The project is designed to be reproducible and secure
- All choices are compliant with the Inception subject v5.0
