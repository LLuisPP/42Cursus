# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2023/11/28 18:14:28 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------- NOMBRE
NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = main.c

SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH = ./hincludes
HEADERS = -I$(H_PATH)
DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all: makelib $(OBJ_PATH) $(NAME)

makelib: 
	$(MAKE) --silent -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(CC) $(OBJS) libft/libft.a -o $(NAME)
	echo

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean :
	$(call progress_remove)
	$(RM) $(OBJ_PATH)
	@$(MAKE) --silent -C libft clean

fclean :
	$(RM) $(NAME) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean
# --silent a la linea de $MAKE #

re :
	$(RM) $(NAME) $(OBJS)
	make all

.PHONY: all, clean, fclean, re

.SILENT:

#========================================================================#

BGRAY =	\033[1;90m
BRED = \033[1;91m
BGREEN = \033[1;92m
BYELLOW = \033[1;93m
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

# **************************************************************************** #

COUNT_SRCS := $(words $(SRCS))
COUNT_OBJS := $(words $(OBJS))
BAR_LEN := 20

# **************************************************************************** #


define show_progress
	echo; \
	((i = 0)); \
	while [[ $$i -le $(COUNT_SRCS) ]] ; do \
		printf "$(BCIAN)➜ Compiling $(basename $(NAME)) $(BBLUE)["; \
		progress=$$((i * $(BAR_LEN) / $(COUNT_SRCS))); \
		((j = 1));\
		while [[ $$j -le $(BAR_LEN) ]]; do \
			if [[ $$j -le $$progress ]]; then \
				printf "$(BGREEN)░"; \
			else \
				printf " "; \
			fi; \
			((j = j + 1)); \
		done; \
		printf "$(BBLUE)] [$(CIAN)$$i/$(COUNT_SRCS)$(BBLUE)] \
		[$(BWHITE)$$((i * 100 / $(COUNT_SRCS)))%%$(BBLUE)]$(WHITE)\r"; \
		((i = i + 1)); \
		sleep 0.05; \
	done
	echo
endef
