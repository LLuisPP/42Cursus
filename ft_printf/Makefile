# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 10:31:02 by lprieto-          #+#    #+#              #
#    Updated: 2023/10/12 10:33:35 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = libftprintf.h
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
s
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME) $(OBJS)

re :
	$(RM) $(NAME) $(OBJS)
	make all

.PHONY: all, clean, fclean, re
