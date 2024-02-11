# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 12:01:56 by lprieto-          #+#    #+#              #
#    Updated: 2024/02/11 10:29:57 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strchr.c \
	   ft_strdup.c ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c \
	   ft_atoi.c ft_calloc.c ft_strlcat.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c	ft_lstdelone_bonus.c ft_lstiter_bonus.c \
				ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
				ft_lstsize_bonus.c

HEADER = libft.h

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

DEPS = $(OBJS:.o=.d)
B_DEPS = $(B_OBJS:.o=.d)

all: $(NAME) 

$(NAME): $(OBJS) libft.h
	$(call show_progress)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I$(HEADER) -MMD -c $< -o $@
	
clean :
	$(RM) $(OBJS) $(B_OBJS) $(DEPS) $(B_DEPS)

fclean :
	$(RM) $(NAME) $(OBJS) $(B_OBJS) $(DEPS) $(B_DEPS) 

re :
	$(RM) $(NAME) $(OBJS)
	make all

bonus :	$(OBJS) $(B_OBJS) libft.h
	$(AR) $(NAME) $(OBJS) $(B_OBJS)

.PHONY: all, clean, fclean, re, bonus

-include $(DEPS)
-include $(B_DEPS)

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