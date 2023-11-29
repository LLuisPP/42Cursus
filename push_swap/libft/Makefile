# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:34:33 by lprieto-          #+#    #+#              #
#    Updated: 2023/11/29 12:12:59 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------- NOMBRE
NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strchr.c \
	   ft_strdup.c ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c \
	   ft_atoi.c ft_calloc.c ft_strlcat.c ft_substr.c ft_strjoin.c \
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
	   get_next_line_utils_bonus.c

SRC_PATH = ./src/

DIRSRC = $(addprefix $(SRC_PATH), $(SRCS))

OBJ_PATH = ./tmp/

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

H_PATH = ../hincludes

HEADERS = -I$(H_PATH)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	ar -rcs $(NAME) $(OBJS)
	echo

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean :
	$(call progress_remove)
	$(RM) $(OBJ_PATH)

fclean :
	$(RM) $(NAME) $(OBJ_PATH)

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
BAR_LEN := 30

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
	done; \
	echo
endef