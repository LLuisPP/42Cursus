# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 20:38:28 by lprieto-          #+#    #+#              #
#    Updated: 2026/02/01 21:16:42 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g
SANFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g3 -fsanitize=address

RM = rm -rf

SERVERCPP = ServerCanonical.cpp ServerCore.cpp ServerCoreHandlers.cpp \
			ServerGetAndSet.cpp ServerParse.cpp ServerParseJoin.cpp \
			ServerParseMode.cpp ServerParsePrivmsg.cpp
SERVER = $(addprefix Server/, $(SERVERCPP))

CLIENTCPP = ClientCanonical.cpp ClientGetAndSet.cpp ClientExecuters.cpp
CLIENT = $(addprefix Client/, $(CLIENTCPP))

CHANNELCPP = ChannelCanonical.cpp ChannelGetAndSet.cpp ChannelExecuters.cpp
CHANNEL = $(addprefix Channel/, $(CHANNELCPP))

SRC = main.cpp $(SERVER) $(CLIENT) $(CHANNEL) Utils.cpp

SRCS = $(addprefix src/, $(SRC))

OBJ_PATH := ./tmp/
H_PATH := ./inc/
HEADERS = -I$(H_PATH)

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))
SAN_OBJS = $(OBJS:.o=.san.o)

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
	$(CXX) $(CXXFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_PATH)%.san.o: %.cpp Makefile # Objetos para AddressSanitizer
	mkdir -p $(dir $@)
	$(CXX) $(SANFLAGS) $(HEADERS) -c $< -o $@

sanitize: fclean $(SAN_OBJS)  # Generar binario con fsanitize=address
	$(call show_progress)
	$(CXX) $(SANFLAGS) $(SAN_OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ_PATH)

fclean:
	$(RM) $(NAME) $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re sanitize
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

	printf " $(B)█████ ██████     $(R)▄▄▄▄ ▄▄▄▄▄▄$(RES) \n \
$(B)█       █             $(R)██████ $(Y)▄████▄$(RES) \n \
$(B)██▀▀    ██       $(R)████ ████  $(Y)████▄███$(RES) \n \
$(B)██      ██       $(R)████ ████  $(Y)████▄$(RES) \n \
$(B)██      ██  $(W)▄▄▄▄ $(R)████ ████   $(Y)▀████▀$(RES) \n\n"; \

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
$(Y)████▄███   $(BW)lgracia-  $(BB)██${PHA}▄${RES}$(BB)█$(PHA)▄${RES}$(BB)██  ${R}█${EYE}▄ ${R}█$(EYE)▄ ${R}█  ${BC}█$(EYE) ▄${RES}${BC}█$(EYE) ▄${BC}█${RES}  ${OR}█$(EYE) ▀${OR}█$(EYE) ▀${OR}█${RES}  ${PP}█$(EYE)▀ ${PP}█$(EYE)▀ ${RES}${PP}█\n \
$(Y)████▄    $(W)  lprieto-  $(BB)█${PHA}▀▄▀▄▀${RES}${BB}█${RES}  ${R}███████  ${BC}███████  ${OR}███████  ${PP}███████\n \
$(Y) ▀████▀    $(G)$(BD)$(NAME)   $(BB)█▀█▀█▀█  ${R}█▀█▀█▀█  ${BC}█▀█▀█▀█  ${OR}█▀█▀█▀█  ${PP}█▀█▀█▀█$(RES)\n\n"; \

endef
