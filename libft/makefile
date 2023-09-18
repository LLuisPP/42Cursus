# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 07:53:57 by lprieto-          #+#    #+#              #
#    Updated: 2023/09/18 08:31:55 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--Nombre--#
NAME = libft.a

#--FLAGS--#
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs

#--SRCS--#
SRCS = ft_isalpha.c ft_isdigit.c
INC = ./libft.h

OBJS = *.o

#--REGLAS--#
all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "libft.a CREADA 🤩"

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -I$(INC) -c $(SRCS)

clean:
	@$(RM) $(OBJS)
	@echo "OBJETOS BORRADOS 👍"

fclean:
	@$(RM) $(OBJS) $(NAME)
	@echo "LIBRERIA Y OBJETOS BORRADOS 🤘"

re:
	@$(RM) $(OBJS) $(NAME)
	@echo "LIBRERIA Y OBJETOS BORRADOS 🤘"
	make

.PHONY: all clean fclean re
