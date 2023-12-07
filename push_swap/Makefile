# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2023/12/07 09:15:59 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = push_swap.c ps_checkers.c ps_utils.c ps_stacks.c 

SRC_PATH := ./src/
OBJ_PATH := ./tmp/
H_PATH := ./hincludes
HEADERS = -I$(H_PATH)
DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all: makelib $(OBJ_PATH) $(NAME)

makelib: 
	$(MAKE) --silent -C libft  --no-print-directory

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(CC) $(OBJS) libft/libft.a -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean :
	$(call progress_remove)
	$(RM) $(OBJ_PATH)
	$(MAKE) --silent -C libft clean

fclean :
	$(RM) $(NAME) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean

re :
	$(RM) $(NAME) $(OBJS)
	make all

.PHONY: all, clean, fclean, re

.SILENT:

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

# **************************************************************************** #

COUNT_SRCS := $(words $(SRCS))
COUNT_OBJS := $(words $(OBJS))
BAR_LEN := 40

# **************************************************************************** #


define show_progress
	echo; \
	printf " eeeee e   e eeeee e   e       eeeee e   e  e eeeee eeeee \n \
8   8 8   8 8   8 8   8       8   8 8   8  8 8   8 8   8 \n \
8eee8 8e  8 8eeee 8eee8       8eeee 8e  8  8 8eee8 8eee8 \n \
88    88  8    88 88  8          88 88  8  8 88  8 88    \n \
88    88ee8 8ee88 88  8       8ee88 88ee8ee8 88  8 88    \n \
.                       eeeee\n\n"; \
	((i = 0)); \
	while [[ $$i -le $(COUNT_SRCS) ]] ; do \
		printf "$(BB)["; \
		progress=$$((i * $(BAR_LEN) / $(COUNT_SRCS))); \
		((j = 1));\
		while [[ $$j -le $(BAR_LEN) ]]; do \
			if [[ $$j -le $$progress ]]; then \
				printf "$(BGREEN)▒"; \
			else \
				printf "$(GRAY)░"; \
			fi; \
			((j = j + 1)); \
		done; \
		printf "$(BBLUE)] [$(C)$$i/$(COUNT_SRCS)$(BBLUE)] \
		[$(BWHITE)$$((i * 100 / $(COUNT_SRCS)))%%$(BBLUE)]$(WHITE)\r"; \
		((i = i + 1)); \
		sleep 0.10; \
	done; \
	echo; \
	printf "\n\n $(BBLUE)╔═════════════╦═════════  ════════╦══════════════╗ \n \
║$(WHITE) • • • • • ● $(BBLUE)║$(WHITE) • P $(PURPLE)ᗣ $(BYELLOW)ᗧ$(WHITE) - M $(GREEN)ᗣ$(WHITE) N • $(BBLUE)║$(W) • • • 🍊 • • $(BBLUE)║ \n \
║$(WHITE) • $(BBLUE)╔═════╗$(WHITE) • $(BBLUE)║$(WHITE)  $(WHITE)▒▒▒▒▒▒▒▒▒$(BBLUE)╗$(WHITE) • ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • $(BBLUE)║$(WHITE)🍒42 $(BBLUE)║$(WHITE) •  ▒▒▒▒▒▒▒▒▒• $(BBLUE)║$(WHITE) • ▒▒▒▒▒▒▒ $(BBLUE)╔$(WHITE)▒▒▒▒▒▒▒ • $(BBLUE)║\n \
$(WHITE)  • $(BBLUE)║$(WHITE) BCN $(BBLUE)║$(WHITE)  ▒▒▒▒▒▒▒▒▒$(BBLUE)════╝$(WHITE) • ▒▒▒▒    $(BBLUE)╚$(WHITE)▒▒▒▒▒▒▒ • \n \
$(BBLUE)║$(WHITE) • $(BBLUE)╚═════╝$(WHITE)▒▒▒▒▒▒▒▒▒  • • • • ▒▒• • • ▒▒▒▒▒▒▒  • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • • •  ▒▒▒▒▒▒▒▒▒ $(BBLUE)╔════  ════╗$(WHITE) • $(BBLUE)╔═$(WHITE)▒▒▒▒▒▒▒▒$(BBLUE)═╗$(W) • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) 🍊 $(BBLUE)╔═$(WHITE)▒▒▒▒▒▒▒▒▒ • $(BBLUE)║$(WHITE) $(W)$$(whoami) $(BBLUE)║$(WHITE) • ▒▒▒▒▒▒▒▒ $(CIAN)ᗣ$(WHITE) $(BBLUE)║$(WHITE) • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) •  ▒▒▒▒▒▒▒▒▒$(BBLUE)═╝$(WHITE) • $(BBLUE)╚══════════╝$(WHITE) ▒▒▒▒▒▒▒▒$(BBLUE)═════╝$(WHITE) • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • ▒▒▒▒▒▒▒▒ • • • • ● • • •   ▒▒▒▒▒▒▒ • • •▒▒ • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ • ▒▒▒▒▒▒▒• $(BBLUE)╔══$(WHITE)▒▒▒▒ • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • ▒▒▒▒▒▒ Barcelona ▒▒▒▒▒▒ • ▒▒▒▒▒▒▒• $(BBLUE)║$(WHITE)▒▒▒▒▒▒ • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ • ▒▒▒▒▒▒▒• ▒▒▒▒▒▒▒ ● $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • • • • • • • •  ▒▒▒▒▒▒▒▒ ● ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ • $(BBLUE)║\n \
$(BBLUE)║$(CIAN) ᗣ$(WHITE) $(BBLUE)╔═ $(RED)█████$(WHITE)• $(BBLUE)╔══╗$(WHITE) $(WHITE)▒▒▒▒▒▒▒▒ • • • |  • • • • • • $(BBLUE)║\n \
$(WHITE)  • $(BBLUE)║$(WHITE) $(RED)█$(WHITE)▄ $(RED)█$(WHITE)▄ $(RED)█ $(BBLUE)╚══╝$(WHITE) $(WHITE)▒▒▒▒▒▒▒▒ • $(BBLUE)╔══$(WHITE) ╰➤$(GREEN) $(NAME)$(WHITE) •\n \
$(BBLUE)║$(WHITE) • $(BBLUE)║$(WHITE) $(RED)███████$(WHITE) • •  $(WHITE)▒▒▒▒▒▒▒▒ • $(BBLUE)║$(WHITE) • • • $(BBLUE)╔══════╗$(WHITE) • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • $(BBLUE)╚$(RED) █ █ █ █ $(BBLUE)║$(WHITE) 🍏 $(WHITE)▒▒▒▒▒▒▒▒ $(BBLUE)══╝$(WHITE) • $(BBLUE)║$(WHITE) • $(BBLUE)╚══════╝$(WHITE) • $(BBLUE)║\n \
$(BBLUE)║$(WHITE) • • ● • • • $(BBLUE)║$(WHITE) • • • • $(RED)ᗣ$(WHITE) • • • • $(BBLUE)║$(WHITE) ● • • • • 🍓 $(BBLUE)║ \n \
╚═════════════╩═════════  ════════╩══════════════╝ \n";
endef