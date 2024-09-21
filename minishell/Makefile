# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 07:16:06 by lprieto-          #+#    #+#              #
#    Updated: 2024/09/21 22:28:39 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -g
#LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lreadline #   LINUX    #
LDFLAGS = -L/usr/local/opt/readline/lib -lreadline #   MACOS   #
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

AR = ar -rcs
RM = rm -rf
 
# **************************************************************************** #

SRCS = minishell.c ms_init.c ms_tokenizer.c ms_parser.c ms_lexer.c ms_rline.c \
	ms_echo.c ms_env.c ms_free.c ms_tools.c \

SRC_PATH := ./src/
OBJ_PATH := ./tmp/

H_PATH := ./inc/
HEADERS = -I$(H_PATH)

DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

# **************************************************************************** #

all: makelib $(OBJ_PATH) $(NAME)

makelib: 
	$(MAKE) --silent -C libft  --no-print-directory

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft $(LDFLAGS) -o $(NAME)
	$(call show_progress)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile libft/libft.a
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -MMD -c $< -o $@

clean :
	$(RM) $(OBJ_PATH)
	$(MAKE) --silent -C libft clean

fclean :
	$(RM) $(NAME) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean

re :
	make fclean --silent
	make all --silent
	$(MAKE) all --silent -C libft

.PHONY: all, clean, fclean, re

.SILENT:

-include $(DEPS)

# **************************************************************************** #

BGY = \033[1;90m
BR = \033[1;91m
BGR = \033[1;92m
BY = \033[1;33m
BB = \033[1;94m
BC = \033[1;96m
BW = \033[1;97m
GY = \033[0;90m
R = \033[0;91m
G = \033[0;92m
Y = \033[0;93m
B = \033[0;94m
C = \033[0;96m
W = \033[0;97m
PP = \033[0;95m
BD = \033[1m
OR = \033[38;5;214m
PHA = \e[1;107;94m
MOU = \e[1;97;44m
EYE = \e[30;47m
RES = \e[0m

# **************************************************************************** #

BAR_LEN := 55
PROGRESS_DURATION := 1 # Duración de la barra de progreso en segundos
TOTAL_ITEMS := $(words $(OBJS))

define show_progress
	@echo; \
	printf " $(W)eeeeeee                                         ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄ \n \
8  8  8 e  eeeee e  eeee e   e eeee e    e      █               █ \n \
8e 8  8 8  8   8 8  8    8   8 8    8    8      █  ▄            █ \n \
88 8  8 8e 8e  8 8e 8ee8 8eee8 eee8 8e   8e     █   █           █ \n \
88 8  8 88 88  8 88    8 88  8 88   88   88     █  ▀   ▀▀▀      █ \n \
88 8  8 88 88  8 88 8888 88  8 88e8 88ee 88ee   ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀ \n\n"; \

	total_ticks=$$((PROGRESS_DURATION * 10)); # 20 ticks por segundo para una actualización fluida
	item_progress=0; \
	while [ $$item_progress -le $(TOTAL_ITEMS) ]; do \
		percentage=$$(( 100 * $$item_progress / $(TOTAL_ITEMS) )); \
		filled_len=$$(( $(BAR_LEN) * $$item_progress / $(TOTAL_ITEMS) )); \
		unfilled_len=$$(( $(BAR_LEN) - $$filled_len )); \
		bar=$$(printf "%0.s█" $$(seq 1 $$filled_len)); \
		bar=$$bar$$(printf "%0.s-" $$(seq 1 $$unfilled_len)); \
		printf "\r$(W)[$(GY)-%s$(W)] $(W)[$(BW)%d%%$(W)]$(W)" "$$bar" "$$percentage"; \
		sleep $$(echo "scale=2; $(PROGRESS_DURATION) / $(TOTAL_ITEMS)" | bc); \
		item_progress=$$(( $$item_progress + 1 )); \
	done; \
	
	printf "\n\n  $(Y)▄████▄   $(BW)lauriago   $(BB)▄█████▄  ${R}▄█████▄  ${BC}▄█████▄  ${OR}▄█████▄  $(PP)▄█████▄\n \
$(Y)████▄███   $(BW)lprieto-  $(BB)██${PHA}▄${RES}$(BB)█$(PHA)▄${RES}$(BB)██  ${R}█${EYE}▄ ${R}█$(EYE)▄ ${R}█  ${BC}█$(EYE) ▄${RES}${BC}█$(EYE) ▄${BC}█${RES}  ${OR}█$(EYE) ▀${OR}█$(EYE) ▀${OR}█${RES}  ${PP}█$(EYE)▀ ${PP}█$(EYE)▀ ${RES}${PP}█\n \
$(Y)████▄    $(W)  · · · ·   $(BB)█${PHA}▀▄▀▄▀${RES}${BB}█${RES}  ${R}███████  ${BC}███████  ${OR}███████  ${PP}███████\n \
$(Y) ▀████▀   $(G)$(BD)$(NAME)  $(BB)█▀█▀█▀█  ${R}█▀█▀█▀█  ${BC}█▀█▀█▀█  ${OR}█▀█▀█▀█  ${PP}█▀█▀█▀█$(RES)\n\n"; \

endef

