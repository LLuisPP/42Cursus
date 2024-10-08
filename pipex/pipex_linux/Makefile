# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 07:16:06 by lprieto-          #+#    #+#              #
#    Updated: 2024/09/02 11:54:50 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

AR = ar -rcs
RM = rm -rf

SRCS = pipex.c pip_utils.c

SRC_PATH := ./src/
OBJ_PATH := ./tmp/

H_PATH := ./hincludes
HEADERS = -I$(H_PATH)

DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

all: makelib $(OBJ_PATH) $(NAME)

makelib: 
	$(MAKE) --silent -C libft  --no-print-directory

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

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

files :
	touch A
	touch B
	echo "$(GREEN)\n >>> A, B files created -> to delete them use: make delfiles \n"

delfiles :
	rm A
	rm B
	echo "$(RED)\n >>> A, B files deleted -> X \n"
	
.PHONY: all, clean, fclean, re

.SILENT:

-include $(DEPS)

#========================================================================#

BGRAY =	\033[1;90m
BRED = \033[1;91m
BGREEN = \033[1;92m
BYELLOW = \033[1;33m
BBLUE = \033[1;94m
BCIAN = \033[1;96m
BWHITE = \033[1;97m
GRAY =	\033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CIAN = \033[0;96m
WHITE = \033[0;97m
PURPLE = \033[0;95m
BOLD = \033[1m
PHA = \e[1;107;94m
MOU = \e[1;97;44m
RES = \e[0m

# **************************************************************************** #

COUNT_SRCS := $(words $(SRCS))
COUNT_OBJS := $(words $(OBJS))
BAR_LEN := 40

# **************************************************************************** #

BAR_LEN := 45
PROGRESS_DURATION := 1 # Duración de la barra de progreso en segundos
TOTAL_ITEMS := $(words $(OBJS))


define show_progress
	echo; \
	printf "\n eeeee e  eeeee eeee e    e   ${RED}▄███${WHITE}M${RED}▄▄${WHITE}\n \
8   8 8  8   8 8     8  8   ▄▀█▀${WHITE}▐└─┐ m     ${WHITE}▄▄▄▄▄▄▄▄▄\n \
8eee8 8e 8eee8 8eee   ee    █▄ ▀▄█▄┘$(BLUE) █     ${WHITE}█${GREEN}█░█████${WHITE}█░\n \
88    88 88    88    88 8  $(WHITE) └▄▄▄▄▄┘$(BLUE)▄██     ${WHITE}█████████░\n \
88    88 88    88ee 88   8  $(BLUE) █$(RED)█$(BLUE)█$(RED)█$(BLUE)███▀       $(WHITE)█${GREEN}█▒███${WHITE}█░\n\n"; \

total_ticks=$$((PROGRESS_DURATION * 10)); # 20 ticks por segundo para una actualización fluida
	item_progress=0; \
	while [ $$item_progress -le $(TOTAL_ITEMS) ]; do \
		percentage=$$(( 100 * $$item_progress / $(TOTAL_ITEMS) )); \
		filled_len=$$(( $(BAR_LEN) * $$item_progress / $(TOTAL_ITEMS) )); \
		unfilled_len=$$(( $(BAR_LEN) - $$filled_len )); \
		bar=$$(printf "%0.s█" $$(seq 1 $$filled_len)); \
		bar=$$bar$$(printf "%0.s-" $$(seq 1 $$unfilled_len)); \
		printf "\r$(WHITE)[$(GRAY)-%s$(WHITE)] $(WHITE)[$(BWHITE)%d%%$(WHITE)]$(WHITE)" "$$bar" "$$percentage"; \
		sleep $$(echo "scale=2; $(PROGRESS_DURATION) / $(TOTAL_ITEMS)" | bc); \
		item_progress=$$(( $$item_progress + 1 )); \
	done; \

	echo; \
	printf "\n  $(YELLOW)▄████▄   $(BBLUE)▄█████▄  ${RED}▄█████▄             ${PURPLE}▄█████▄  $(BCIAN)▄█████▄\n \
$(YELLOW)████▄███  $(BBLUE)██${PHA}▄$(BBLUE)█$(PHA)▄█$(BBLUE)█${RES}  ${RED}█$(WHITE)▄ ${RED}█$(WHITE)▄ ${RED}█ $(GREEN)   ${BOLD}$(NAME)    ${PURPLE}█$(WHITE) ▀${PURPLE}█$(WHITE) ▀${PURPLE}█  ${BCIAN}█$(WHITE)▀ ${BCIAN}█$(WHITE)▀ ${BCIAN}█\n \
$(YELLOW)████▄     $(BBLUE)█${PHA}▀▄▀▄▀${BBLUE}█${RES}  ${RED}███████  $(WHITE) lprieto-  ${PURPLE}███████  ${BCIAN}███████ \n \
$(YELLOW) ▀████▀   $(BBLUE)█▀█▀█▀█  ${RED}█ █ █ █             ${PURPLE}█ █ █ █  ${BCIAN}█ █ █ █\n\n";

endef
