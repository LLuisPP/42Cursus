# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 20:38:28 by lprieto-          #+#    #+#              #
#    Updated: 2025/10/18 11:03:51 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sedIs4Los

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g # -fsanitize=address

RM = rm -rf

# **************************************************************************** #

SRC = main.cpp

SRCS = $(addprefix src/, $(SRC))

OBJ_PATH := ./tmp/
H_PATH := ./inc/
HEADERS = -I$(H_PATH)

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

# **************************************************************************** #

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(call show_progress)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: %.cpp Makefile
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(HEADERS) -MMD -c $< -o $@
	
clean :
	$(RM) $(OBJ_PATH)

fclean :
	$(RM) $(NAME) $(OBJ_PATH)

re :
	make fclean --silent
	make all --silent

.PHONY: all clean fclean re

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
	printf " eeeee eeee eeeee 8  eeeee 88     e     eeeee eeeee eeee eeeee  eeeee \n \
8     8    8   8 8e 8     88  88 8     8  88 8     8    8   8  8    \n \
8eeee 8eee 8e  8 88 8eeee 88ee88 8e    8   8 8eeee 8eee 8eee8e 8eeee \n \
   88 88   88  8 88    88     88 88    8   8    88 88   88   8    88 \n \
8ee88 88ee 88ee8 88 8ee88     88 88eee 8eee8 8ee88 88ee 88   8 8ee88 \n\n"; \

	printf " $(W)▄▄▄▄▄▄▄               eeeeee 88 \n \
$(W)█                     e    8  8       $(Y)▄████▄              $(BB)▄█████▄ $(RES)\n \
█          █     █    8    8  8      $(Y)████▄███  $(BW)lprieto-   $(BB)██${PHA}▄${RES}$(BB)█$(PHA)▄${RES}$(BB)██ ${RES}\n \
█▄       ▀▀█▀▀ ▀▀█▀▀  e    8  8      $(Y)████▄     $(G)$(BD)$(NAME)  $(BB)█${PHA}▀▄▀▄▀${RES}${BB}█ $(RES)\n \
██         ▀     ▀    88   8 8888    $(Y) ▀████▀     ex04     $(BB)█▀█▀█▀█ $(RES)\n \
███████               888888 8888 \n\n"; \

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

	printf "\n $(RES)\n"; \

endef
