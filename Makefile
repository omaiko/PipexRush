# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaiko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 13:15:35 by omaiko            #+#    #+#              #
#    Updated: 2018/10/13 17:37:46 by omaiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c
HEADER = pipex.h
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = # -Wall -Wextra -Werror
DEL = /bin/rm -f

.PHONY = all clean fclean re

all: $(NAME)

$(NAME):
		@echo "\033[36mBuilding: $(NAME)\033[0m"
		$(CC) $(FLAGS) -Llibft -lft -Ilibft $(SRC) -o $(NAME)
		@echo "\033[32mCompiled successfully :)\033[0m"

clean:
		@$(DEL) $(OBJ)
		@echo "\033[31mObjects for $(NAME) deleted\033[0m"

fclean: clean
		@$(DEL) $(NAME)
		@echo "\033[31mFile $(NAME) deleted\033[0m"

norm:
		@norminette *.?

re: fclean all
