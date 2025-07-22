# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 11:37:46 by lprieto-          #+#    #+#              #
#    Updated: 2025/07/22 21:02:53 by lprieto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

RM = rm -rf
 
# **************************************************************************** #

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	$(call show_progress)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean :
	$(RM) $(OBJS) $(DEPS)

fclean :
	$(RM) $(NAME) $(OBJS) $(DEPS)

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
	printf " eeeeeee eeee eeeee eeeee eeeee e   e eeeee eeeee eeee \n \
8  8  8 8    8   8 8   8 8   8 8   8 8  88 8   8 8 \n \
8e 8  8 8eee 8e    8eee8 8eee8 8eee8 8   8 8e  8 8eee \n \
88 8  8 88   88 e8 88  8 88    88  8 8   8 88  8 88 \n \
88 8  8 88ee 88ee8 88  8 88    88  8 8eee8 88  8 88ee \n\n"; \
	printf " $(W)▄▄▄▄▄▄▄               eeeeee eeeeee \n \
$(W)█                     e    e e    e   $(Y)▄████▄              $(BB)▄█████▄ $(RES)\n \
█          █     █    8    8 8    8  $(Y)████▄███   $(BW)lprieto-  $(BB)██${PHA}▄${RES}$(BB)█$(PHA)▄${RES}$(BB)██ ${RES}\n \
█▄       ▀▀█▀▀ ▀▀█▀▀  e    8 8    8  $(Y)████▄     $(G)$(BD)$(NAME)  $(BB)█${PHA}▀▄▀▄▀${RES}${BB}█ $(RES)\n \
██         ▀     ▀    88   8 8e   8  $(Y) ▀████▀              $(BB)█▀█▀█▀█ $(RES)\n \
███████               888888 888888  \n\n"; \

	total_ticks=$$((PROG_DURAT * 10)); # 20 ticks por segundo para una actualización fluida
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
