# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 07:16:06 by lprieto-          #+#    #+#              #
#    Updated: 2025/07/21 19:15:48 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -MMD -g -O1 #-fsanitize='address,undefined'
CPPFLAGS =  -I minilibx 
MLX_FLAGS := -lmlx -lXext -lX11 -lm -lbsd -lz

AR = ar -rcs
RM = rm -rf

# **************************************************************************** #

MAIN = cub3d \

DRAW = draw_map draw_raycast draw_shapes draw_utils raycasting_utils \

PLAYER = player_init player_move player_directions \

MAP = map load_textures\

PARSER = checkers config_parser config_parser_utils map_builder \
			map_validation \

BONUS = draw_map_bonus draw_raycast_bonus draw_shapes_bonus draw_utils_bonus \
		raycasting_utils_bonus \

FREE =	free \

SRCS = 	$(addsuffix .c, $(addprefix src/draw/, $(DRAW))) \
		$(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
		$(addsuffix .c, $(addprefix src/map/, $(MAP))) \
		$(addsuffix .c, $(addprefix src/player/, $(PLAYER))) \
		$(addsuffix .c, $(addprefix src/parser/, $(PARSER))) \
		$(addsuffix .c, $(addprefix src/free/, $(FREE))) \

BONUS_SRCS = 	$(addsuffix .c, $(addprefix src/bonus/, $(BONUS))) \
				$(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
				$(addsuffix .c, $(addprefix src/map/, $(MAP))) \
				$(addsuffix .c, $(addprefix src/player/, $(PLAYER))) \
				$(addsuffix .c, $(addprefix src/parser/, $(PARSER))) \
				$(addsuffix .c, $(addprefix src/free/, $(FREE))) \

OBJ_PATH := ./tmp/
H_PATH := ./inc/
HEADERS = -I$(H_PATH)

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

BONUS_OBJS = $(addprefix $(OBJ_PATH), $(BONUS_SRCS:.c=.o))
BONUS_DEPS = $(BONUS_OBJS:.o=.d)

# **************************************************************************** #

all: mlx makelib $(OBJ_PATH) $(NAME)

makelib:
	$(MAKE) --silent -C libft  --no-print-directory

mlx:
	$(MAKE) --silent -C minilibx --no-print-directory

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(CC) $(CFLAGS) ${CPPFLAGS} $(OBJS) -Llibft -lft -Lminilibx $(MLX_FLAGS) -o $(NAME)

$(OBJ_PATH)%.o: %.c Makefile libft/libft.a
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -MMD -c $< -o $@

bonus : mlx makelib $(OBJ_PATH) $(NAME)_bonus

$(NAME)_bonus: $(BONUS_OBJS)
	$(call show_progress)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(BONUS_OBJS) -Llibft -lft -Lminilibx $(MLX_FLAGS) -o $(NAME)
	
clean :
	$(RM) $(OBJ_PATH)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean

fclean :
	$(RM) $(NAME) $(OBJ_PATH)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean

re :
	make fclean
	make all
	$(MAKE) all -C libft
	$(MAKE) all -C minilibx

.PHONY: all clean fclean re bonus

.SILENT:

-include $(DEPS)

# **************************************************************************** #

BGY = \033[1;90m
BR = \033[1;91m
BGR = \033[1;92m
BY = \033[1;33m
BB = \033[1;94m
BC = \033[1;96m
BW = \033[1;97m
GY = \033[0;90m
R = \033[0;91m
G = \033[0;92m
Y = \033[0;93m
B = \033[0;94m
C = \033[0;96m
W = \033[0;97m
PP = \033[0;95m
BD = \033[1m
OR = \033[38;5;214m
PHA = \e[1;107;94m
MOU = \e[1;97;44m
EYE = \e[30;47m
RES = \e[0m

# **************************************************************************** #

BAR_LEN := 55
PROG_DURAT := 1
TOTAL_ITEMS := $(words $(OBJS))

define show_progress
	@echo; \

	printf " $(W)888888                eeeee 88888            ▀▄            ▄▀\n \
8    8 e   e eeeee       e8 8    8             █   ▄▄▄▄   █ \n \
8e     8   8 8   8      ee  8e   8             █   █  █   █  \n \
88     8e  8 8eee8e    eee8 88   8             █▄▄▄█▄▄█▄▄▄█ \n \
88   e 88  8 88   8      88 88   8           ▄▀            ▀▄ \n \
88eee8 88ee8 88eee8   eee88 88eee          ▄▀       ▀▀       ▀▄ \n\n"; \

	total_ticks=$$((PROG_DURAT * 10));
	item_progress=0; \
	while [ $$item_progress -le $(TOTAL_ITEMS) ]; do \
		percentage=$$(( 100 * $$item_progress / $(TOTAL_ITEMS) )); \
		filled_len=$$(( $(BAR_LEN) * $$item_progress / $(TOTAL_ITEMS) )); \
		unfilled_len=$$(( $(BAR_LEN) - $$filled_len )); \
		bar=$$(printf "%0.s▓" $$(seq 1 $$filled_len)); \
		bar=$$bar$$(printf "%0.s─" $$(seq 1 $$unfilled_len)); \
		printf "\r$(W)[$(GY)─%s$(W)] $(W)[$(BW)%d%%$(W)]$(W)" "$$bar" "$$percentage"; \
		sleep $$(echo "scale=2; $(PROG_DURAT) / $(TOTAL_ITEMS)" | bc); \
		item_progress=$$(( $$item_progress + 1 )); \
	done; \
	
	printf "\n\n  $(Y)▄████▄    $(BW)flperez-  $(BB)▄█████▄  ${R}▄█████▄  ${BC}▄█████▄  ${OR}▄█████▄  $(PP)▄█████▄\n \
$(Y)████▄███   $(BW)lprieto-  $(BB)██${PHA}▄${RES}$(BB)█$(PHA)▄${RES}$(BB)██  ${R}█${EYE}▄ ${R}█$(EYE)▄ ${R}█  ${BC}█$(EYE) ▄${RES}${BC}█$(EYE) ▄${BC}█${RES}  ${OR}█$(EYE) ▀${OR}█$(EYE) ▀${OR}█${RES}  ${PP}█$(EYE)▀ ${PP}█$(EYE)▀ ${RES}${PP}█\n \
$(Y)████▄    $(W)  · · · ·   $(BB)█${PHA}▀▄▀▄▀${RES}${BB}█${RES}  ${R}███████  ${BC}███████  ${OR}███████  ${PP}███████\n \
$(Y) ▀████▀     $(G)$(BD)$(NAME)    $(BB)█▀█▀█▀█  ${R}█▀█▀█▀█  ${BC}█▀█▀█▀█  ${OR}█▀█▀█▀█  ${PP}█▀█▀█▀█$(RES)\n\n"; \

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
