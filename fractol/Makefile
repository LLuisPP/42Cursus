# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2024/02/19 09:10:00 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc #-g
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
CPPFLAGS =  -I minilibx #flags de preprocesador
OPENGLFLAG = -framework OpenGL -framework AppKit
AR = ar -rcs
RM = rm -rf

SRCS = fractol.c frol_error.c frol_fractal.c frol_fractal_set.c \
	frol_render.c frol_display.c

SRC_PATH := ./src/
OBJ_PATH := ./tmp/

H_PATH := ./hincludes
HEADERS = -I$(H_PATH)

DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

all: makelib makelibx $(OBJ_PATH) $(NAME)

makelib: 
	$(MAKE) --silent -C libft  --no-print-directory

makelibx:
	$(call show_mlx)
	$(MAKE) --silent -C minilibx --no-print-directory &> /dev/null

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(CC) $(CFLAGS) $(OBJS) $(OPENGLFLAG) -L libft -lft -L minilibx -lmlx -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile libft/libft.a
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(HEADERS) -MMD -c $< -o $@

clean :
	$(RM) $(OBJ_PATH)
	$(MAKE) --silent -C libft clean
	$(MAKE) --silent -C minilibx clean

fclean :
	$(RM) $(NAME) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean
	$(MAKE) --silent -C minilibx clean

re :
	make fclean --silent
	make all --silent
	$(MAKE) all --silent -C libft
	$(MAKE) all --silent -C minilibx
	
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


define show_progress
	echo; \
	printf " eeeee eeee  eeeee eeee eeee eeee e         __/\__\n \
8e    8  8  8   8 8  8  8   8 88 8         \_\/_/\n \
88ee  8ee8e 8eee8 8e    8e  8  8 8e   __/\_/_/\_\_/\__\n \
88    88  8 88  8 88    88  8  8 88   \_\/_/    \_\/_/\n \
88    88  8 88  8 88e8  88  8ee8 88ee /_/\_\    /_/\_\ \n\n"; \
	((i = 0)); \
	while [[ $$i -le $(COUNT_SRCS) ]] ; do \
		printf "$(BBLUE)["; \
		progress=$$((i * $(BAR_LEN) / $(COUNT_SRCS))); \
		((j = 1));\
		while [[ $$j -le $(BAR_LEN) ]]; do \
			if [[ $$j -le $$progress ]]; then \
				printf "$(GREEN)▣"; \
			else \
				printf "$(GRAY)▢"; \
			fi; \
			((j = j + 1)); \
		done; \
		printf "$(BBLUE)] [$(BBLUE)$$i$(BBLUE)/$(COUNT_SRCS)$(BBLUE)] \
		[$(BWHITE)$$((i * 100 / $(COUNT_SRCS)))%%$(BBLUE)]$(WHITE)\r"; \
		((i = i + 1)); \
		sleep 0.02; \
	done; \
	echo; \
	printf "\n  $(YELLOW)▄████▄   $(BBLUE)▄█████▄  ${RED}▄█████▄             ${PURPLE}▄█████▄  $(BCIAN)▄█████▄\n \
$(YELLOW)████▄███  $(BBLUE)██${PHA}▄$(BBLUE)█$(PHA)▄█$(BBLUE)█${RES}  ${RED}█$(WHITE)▄ ${RED}█$(WHITE)▄ ${RED}█ $(GREEN) ${BOLD}$(NAME)    ${PURPLE}█$(WHITE) ▀${PURPLE}█$(WHITE) ▀${PURPLE}█  ${BCIAN}█$(WHITE)▀ ${BCIAN}█$(WHITE)▀ ${BCIAN}█\n \
$(YELLOW)████▄     $(BBLUE)█${PHA}▀▄▀▄▀${BBLUE}█${RES}  ${RED}███████  $(WHITE)$$(whoami)   ${PURPLE}███████  ${BCIAN}███████ \n \
$(YELLOW) ▀████▀   $(BBLUE)█▀█▀█▀█  ${RED}█ █ █ █             ${PURPLE}█ █ █ █  ${BCIAN}█ █ █ █\n\n";
endef

define show_mlx
	echo; \
	printf "              ░░\n \
░░░░░  ░░░   ░░ ░░      ░░\n \
░░   ░░   ░░ ░░   ░░  ░░\n \
░░   ░░   ░░ ░░     ░░\n \
░░   ░░   ░░ ░░   ░░  ░░\n \
░░   ░░   ░░ ░░ ░░      ░░\n\n";
endef

