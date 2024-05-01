# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 08:08:17 by drabarza          #+#    #+#              #
#    Updated: 2024/04/28 20:51:35 by drabarza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[3;32m
GREENS = \033[7;32m
YELLOW = \033[3;33m
RED = \033[3;31m
NC = \033[0m

CLIENT = client
SERVER = server
CC = clang
FLAGS = -Wall -Werror -Wextra -g
SRC_CLIENT =	client.c \
				atoi.c
SRC_SERVER =	server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
CURRENT_DATE = $(shell date +"%d/%m/%Y %H:%M:%S")
MAKEFLAGS += -s

all: header $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJ_CLIENT)
	@${CC} ${FLAGS} $(OBJ_CLIENT) -o $@

$(SERVER) : $(OBJ_SERVER)
	@${CC} ${FLAGS} $(OBJ_SERVER) -o $@

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
	@rm -f ${OBJ_CLIENT} ${OBJ_SERVER}
	@echo "${RED}Cleaning completed.${NC}"

fclean: clean

re: fclean all

.PHONY: all clean fclean re header bonus
