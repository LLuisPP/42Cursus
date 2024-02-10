# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2024/02/09 12:32:05 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------- NOMBRE
NAME = libft.a

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strchr.c \
	   ft_strdup.c ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c \
	   ft_atoi.c ft_calloc.c ft_strlcat.c ft_substr.c ft_strjoin.c ft_atol.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_printf.c \
	   ft_pholder.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_unsignedint.c \
	   ft_hex.c \
	   get_next_line.c get_next_line_utils.c get_next_line_bonus.c \
	   get_next_line_utils_bonus.c \
	   ft_abs_val.c ft_range.c

SRC_PATH = ./src/
OBJ_PATH = ./tmp/

H_PATH = ../hincludes
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
	printf "\n $(BBLUE)▄$(WHITE)█▀▀▀▀▀▀▀▄ ▄▀▀▀▀▀▀▀█$(BBLUE)▄$(WHITE)\n \
$(BBLUE)█$(WHITE)█ ░▄░▄▄░▄ ░<░░/>░ █$(BBLUE)█$(WHITE)    e     e  eeeee  eeee eeeee \n \
$(BBLUE)█$(WHITE)█ ░▄▄░▄░░ ░▄░░░▄░ █$(BBLUE)█$(WHITE)    8     8  8   8  8      8\n \
$(BBLUE)█$(WHITE)█ $(NAME) ░▄░░▄▄░ █$(BBLUE)█$(WHITE)    8e    8e 8eee8e 8eee   8e\n \
$(BBLUE)█$(WHITE)█ ░░░░░░░ ░░░░░░░ █$(BBLUE)█$(WHITE)    88    88 88   8 88     88\n \
$(BBLUE)█$(WHITE)█▄▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄▄█$(BBLUE)█$(WHITE)    88eee 88 88eee8 88     88\n \
$(BBLUE)▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀\n\n"; \
	((i = 0)); \
	while [[ $$i -le $(COUNT_SRCS) ]] ; do \
		printf "$(BBLUE)["; \
		progress=$$((i * $(BAR_LEN) / $(COUNT_SRCS))); \
		((j = 1));\
		while [[ $$j -le $(BAR_LEN) ]]; do \
			if [[ $$j -le $$progress ]]; then \
				printf "$(BGREEN)▣"; \
			else \
				printf "$(GRAY)▢"; \
			fi; \
			((j = j + 1)); \
		done; \
		printf "$(BBLUE)] [$(CIAN)$$i/$(COUNT_SRCS)$(BBLUE)] \
		[$(BWHITE)$$((i * 100 / $(COUNT_SRCS)))%%$(BBLUE)]$(WHITE)\r"; \
		((i = i + 1)); \
		sleep 0.02; \
	done; \
	echo;
endef

