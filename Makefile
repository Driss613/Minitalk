# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 08:08:17 by drabarza          #+#    #+#              #
#    Updated: 2024/05/06 18:46:05 by drabarza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[3;32m
GREENS = \033[7;32m
YELLOW = \033[3;33m
RED = \033[3;31m
NC = \033[0m

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = clang
FLAGS = -Wall -Werror -Wextra -g
SRC_CLIENT =	Mandatory/client.c \
				Mandatory/minitalk_utils.c
SRC_SERVER =	Mandatory/server.c \
				Mandatory/minitalk_utils.c
SRC_CLIENT_BONUS =	Bonus/client_bonus.c \
				Bonus/minitalk_utils_bonus.c
SRC_SERVER_BONUS =	Bonus/server_bonus.c \
				Bonus/minitalk_utils_bonus.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
CURRENT_DATE = $(shell date +"%d/%m/%Y %H:%M:%S")
MAKEFLAGS += -s

all: header $(CLIENT) $(SERVER)

bonus: header $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : $(OBJ_CLIENT)
	@${CC} ${FLAGS} $(OBJ_CLIENT) -o $@

$(SERVER) : $(OBJ_SERVER)
	@${CC} ${FLAGS} $(OBJ_SERVER) -o $@

$(CLIENT_BONUS) : $(OBJ_CLIENT_BONUS)
	@${CC} ${FLAGS} $(OBJ_CLIENT_BONUS) -o $@

$(SERVER_BONUS) : $(OBJ_SERVER_BONUS)
	@${CC} ${FLAGS} $(OBJ_SERVER_BONUS) -o $@

header:
	@clear
	@echo "${YELLOW}███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo "Compilation in progress...${NC}"

%.o : %.c
	@${CC} ${FLAGS} -c $< -o $@
	@echo "${CURRENT_DATE} ${GREENS}[CMD]${NC}${GREEN} - $(basename $<)${NC}"

clean:
	@echo "${RED}Cleaning object files...${NC}"
	@rm -f ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_BONUS}
	@echo "${RED}Cleaning completed.${NC}"

fclean: clean
	@rm -f ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}

re: fclean all

.PHONY: all clean fclean re header bonus
