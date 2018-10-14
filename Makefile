# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaiko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 13:15:35 by omaiko            #+#    #+#              #
#    Updated: 2018/10/14 15:57:17 by omaiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c run_tool.c
HEADER = pipex.h
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
DEL = /bin/rm -f

.PHONY = all clean fclean re

all: $(NAME)

$(NAME):
		@echo "\033[36mBuilding: $(NAME)\033[0m"
		@make -C libft
		@$(CC) $(FLAGS) -Ilibft/includes $(SRC) libft/libft.a -o $(NAME)

clean:
		@make -C libft clean
		@$(DEL) $(OBJ)
		@echo "\033[31mObjects for $(NAME) deleted\033[0m"

fclean: clean
		@make -C libft fclean
		@$(DEL) $(NAME)
		@echo "\033[31mFile $(NAME) deleted\033[0m"

norm:
		#@norminette *.?

re: fclean all
