# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2025/03/26 11:15:27 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
AR = ar -rcs
RM = rm -rf

SRCS = ft_abs_val.c ft_atoi.c ft_atof.c ft_atol.c ft_bzero.c ft_calloc.c \
	ft_fd_printf.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_strcat.c \
	ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	ft_range.c ft_split.c ft_strchr.c ft_strcmp.c ft_strcpsn.c ft_strcpy.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strndup.c ft_strncpy.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_free_ptr.c get_next_line.c


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
	make all

.PHONY: all, clean, fclean, re

.SILENT:

-include $(DEPS)

# **************************************************************************** #

BGR = \033[1;90m
BR = \033[1;91m
BG = \033[1;92m
BY = \033[1;33m
BB = \033[1;94m
BC = \033[1;96m
BW = \033[1;97m
GR = \033[0;90m
R = \033[0;91m
G = \033[0;92m
Y = \033[0;93m
B = \033[0;94m
C = \033[0;96m
W = \033[0;97m
PP = \033[0;95m
OR = \033[38;5;214m
REV = \e[34;47m
RIG = \e[30;47m
TXT = \e[30;42m
RES = \e[0m

# **************************************************************************** #

BAR_LEN := 50
PROG_DURAT := 1
TOTAL_ITEMS := $(words $(OBJS))

define show_progress
	@echo; \
	
	printf "\n $(G)░░░░░░░░░░███                                      ████████░░░░░\n \
    $(G)░░       ▓▓▓        ▓     ▓  ▓▓▓▓▓  ▓▓▓▓ ▓▓▓▓▓    ▓▓▓    ▓▓▓  ░░\n \
    $(G)▒▒      ▓▓▓  ▓▓▓    ▓     ▓  ▓   ▓  ▓      ▓           ▓▓▓    ▒▒\n \
    $(G)▒▒     ▒▒▒  ▒▒▒     ▒▒    ▒▒ ▒▒▒▒▒▒ ▒▒▒▒   ▒▒        ▒▒▒      ▒▒\n \
    $(G)▓▓    $(G)▒▒▒▒▒▒▒▒▒▒▒   ░░    ░░ ░░   ░ ░░     ░░      ▒▒▒        ▓▓\n \
	$(G)▓▓        $(G)░░░       ░░░░░ ░░ ░░░░░░ ░░     ░░    ░░░          ▓▓\n \
    $(G)█████████░░░                                   ░░░░░░░░░▒▓▓█████\n\n"; \
	
	
	total_ticks=$$((PROG_DURAT * 10));
	item_progress=0; \
	while [ $$item_progress -le $(TOTAL_ITEMS) ]; do \
		percentage=$$(( 100 * $$item_progress / $(TOTAL_ITEMS) )); \
		filled_len=$$(( $(BAR_LEN) * $$item_progress / $(TOTAL_ITEMS) )); \
		unfilled_len=$$(( $(BAR_LEN) - $$filled_len )); \
		bar=$$(printf "%0.s▓" $$(seq 1 $$filled_len)); \
		bar=$$bar$$(printf "%0.s─" $$(seq 1 $$unfilled_len)); \
		printf "\r$(W) [$(GR)─%s$(W)] 📖 $(W)[$(BW)%d%%$(W)]$(W)" "$$bar" "$$percentage"; \
		sleep $$(echo "scale=2; $(PROG_DURAT) / $(TOTAL_ITEMS)" | bc); \
		item_progress=$$(( $$item_progress + 1 )); \
	done; \
	echo; \

endef
