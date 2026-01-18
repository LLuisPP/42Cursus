NAME = inception

COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

up:
	@if [ -z "$$($(COMPOSE) ps -q --status=running)" ]; then \
		echo "Inception services are not running. Starting..."; \
		$(call banner); \
		$(COMPOSE) up -d --build; \
	else \
		echo "Inception services are already running."; \
	fi

down:
	$(COMPOSE) down

clean:
	$(COMPOSE) down

fclean:
	$(COMPOSE) down -v

re: fclean all

.PHONY: all up down clean fclean re


# **************************************************************************** #

define banner
printf "\n e  eeeee eeee eeee eeeee eeeee e  eeeee eeeee  ███  mariadb  ███\n 8  8   8 8  8 8    8   8   8   8  8  88 8   8\n 8e 8e  8 8e   8eee 8eee8   8e  8e 8   8 8e  8  ███ wordpress ███\n 88 88  8 88   88   88      88  88 8   8 88  8\n 88 88  8 88e8 88ee 88      88  88 8eee8 88  8  ███   nginx   ███\n\n  $(Y)▄████▄    $(BW)          $(BB)▄█████▄  ${R}▄█████▄  ${BC}▄█████▄  ${OR}▄█████▄  $(PP)▄█████▄\n $(Y)████▄███   $(BW)lprieto-  $(BB)██${PHA}▄${RES}$(BB)█$(PHA)▄${RES}$(BB)██  ${R}█${EYE}▄ ${R}█$(EYE)▄ ${R}█  ${BC}█$(EYE) ▄${RES}${BC}█$(EYE) ▄${BC}█${RES}  ${OR}█$(EYE) ▀${OR}█$(EYE) ▀${OR}█${RES}  ${PP}█$(EYE)▀ ${PP}█$(EYE)▀ ${RES}${PP}█\n $(Y)████▄    $(W)  · · · ·   $(BB)█${PHA}▀▄▀▄▀${RES}${BB}█${RES}  ${R}███████  ${BC}███████  ${OR}███████  ${PP}███████\n $(Y) ▀████▀   $(G)$(BD)$(NAME)  $(BB)█▀█▀█▀█  ${R}█▀█▀█▀█  ${BC}█▀█▀█▀█  ${OR}█▀█▀█▀█  ${PP}█▀█▀█▀█$(RES)\n\n"
endef

# **************************************************************************** #

BB = \033[1;94m
BC = \033[1;96m
BW = \033[1;97m
R = \033[0;91m
G = \033[0;92m
Y = \033[0;93m
W = \033[0;97m
PP = \033[0;95m
BD = \033[1m
OR = \033[38;5;214m
PHA = \e[1;107;94m
EYE = \e[30;47m
RES = \e[0m

# **************************************************************************** #
