# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 10:31:02 by lprieto-          #+#    #+#              #
#    Updated: 2023/10/24 10:39:55 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_pholder.c ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsignedint.c ft_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME) $(OBJS)

re :
	$(RM) $(NAME) $(OBJS)
	make all

.PHONY: all, clean, fclean, re
