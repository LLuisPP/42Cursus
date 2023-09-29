# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 12:01:56 by lprieto-          #+#    #+#              #
#    Updated: 2023/09/29 08:03:14 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCL = libft.h
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strlen.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_strncmp.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memcmp.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strlcat.c \
	   ft_substr.c \
	   ft_strjoin.c

#SRCSBONUS = ft_test_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo $(LIGHT_VERDE) /+/+/+/+/ $(NAME) COMPILADO /+/+/+/+/

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCL) -c $(SRCS)
	@echo $(LIGHT_VERDE) /+/+/+/+/ OBJ CREADOS /+/+/+/+/
	@echo $(LIGHT_MORADO) /i/i/i/i/ ARCHIVOS USADOS : $(BLANCO) $(SRCS)

#bonus:

clean:
	@echo $(LIGHT_MORADO) /-/-/-/-/ ELIMINADO/S ===> $(OBJS) /-/-/-/-/
	@$(RM) $(OBJS)

fclean:
	@echo $(LIGHT_ROJO) /-/-/-/-/ SE HA ELIMINADO $(NAME) /-/-/-/-/
	@$(RM) $(NAME) $(OBJS)

wipe:
	@echo $(ROJO) /X/X/X/X/ WIPE DE ARCHIVOS /X/X/X/X/
	@$(RM) $(NAME) $(OBJS)

re:
	@$(RM) $(NAME) $(OBJS)
	@echo $(AMARILLO) /-/-/-/-/ WIPE DE ARCHIVOS Y PROGRAMA /-/-/-/-/
	@make
	@echo $(LIGHT_VERDE) /+/+/+/+/ RE PARA $(NAME) /+/+/+/+/

content:
	@ar t $(NAME)

info:
	@echo $(LIGHT_MORADO) /i/i/i/i/ INFO LOCAL DEL COMPILADOR:
	@$(CC) -v

.PHONY: all clean fclean re info




# TABLAS DE COLORES:
AMARILLO="\033[1;33m"
AZUL="\033[0;34m"
BLANCO="\033[1;37m"
CYAN="\033[0;36m"
GRIS="\033[1;30m"
MARRON="\033[0;33m"
MORADO="\033[0;35m"
ROJO="\033[0;31m"
VERDE="\033[0;32m"
SIN_COLOR="\033[0m"
LIGHT_AZUL="\033[1;34m"
LIGHT_CYAN="\033[1;36m"
LIGHT_GRIS="\033[0;37m"
LIGHT_MORADO="\033[1;35m"
LIGHT_ROJO="\033[1;31m"
LIGHT_VERDE="\033[1;32m"
