# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2024/09/21 19:59:08 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strchr.c \
	   ft_strdup.c ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c \
	   ft_atoi.c ft_atol.c ft_calloc.c ft_strlcat.c ft_substr.c ft_strcpy.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_atof.c ft_putchar_fd.c ft_putstr_fd.c ft_strndup.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd_back_bonus.c ft_range.c \
	   ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c \
	   ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_strcmp.c ft_lstlast_bonus.c \
	   ft_lstmap_bonus.c ft_lstnew_bonus.c ft_strcpsn.c ft_abs_val.c \
	   ft_printf.c \
	   ft_pholder.c ft_putchar.c ft_putstr.c \
	   ft_putnbr.c ft_unsignedint.c ft_hex.c \
	   get_next_line.c \
	   get_next_line_utils.c get_next_line_bonus.c \
	   get_next_line_utils_bonus.c \
	   push_swap.c \
	   ps_checkers.c ps_stacks.c ps_print_tools.c ps_range.c \
	   ps_mv_swap.c ps_mv_push.c ps_mv_rot.c ps_mv_rev_rot.c \
	   ps_alg_select.c ps_validate.c ps_index.c ps_optimizer.c \
	   ps_alg3.c ps_alg4.c ps_alg5.c ps_alg10.c ps_alg50.c \
	   ps_alg100.c ps_alg500.c \
	   ft_fd_printf.c \

SRC_PATH = ./src/
OBJ_PATH = ./tmp/

H_PATH = ../inc/
HEADERS = -I$(H_PATH)

DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(AR) $(NAME) $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile $(H_PATH)
	$(CC) $(CFLAGS) $(HEADERS) -MMD -c $< -o $@

clean :
	$(RM) $(OBJ_PATH)

fclean :
	$(RM) $(NAME) $(OBJ_PATH)

re :
	$(RM) $(NAME) $(OBJS)
	make all --silent

.PHONY: all, clean, fclean, re

.SILENT:

-include $(DEPS)

# **************************************************************************** #

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

BAR_LEN := 45
PROGRESS_DURATION := 1 # Duración de la barra de progreso en segundos
TOTAL_ITEMS := $(words $(OBJS))

define show_progress
	@echo; \
	printf "\n $(BBLUE) ▄$(WHITE)█▀▀▀▀▀▀▀▄ ▄▀▀▀▀▀▀▀█$(BBLUE)▄$(WHITE)    e     e  eeeee  eeee eeeee \n \
$(BBLUE) █$(WHITE)█ ░▄░▄░▄░█░<░░/>░ █$(BBLUE)█$(WHITE)    8     8  8   8  8      8\n \
$(BBLUE) █$(WHITE)█ $(NAME)█░▄░░▄▄░ █$(BBLUE)█$(WHITE)    8e    8e 8eee8e 8eee   8e\n \
$(BBLUE) █$(WHITE)█ ░▄▄░▄░░█░░░▄▄░░ █$(BBLUE)█$(WHITE)    88    88 88   8 88     88\n \
$(BBLUE) █$(WHITE)█▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄█$(BBLUE)█$(WHITE)    88eee 88 88eee8 88     88\n \
$(BBLUE) ▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀\n\n"; \
	
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

endef

