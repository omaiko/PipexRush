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
SRC = main.c run_tool.c utils.c
HEADER = pipex.h
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
		@make -C libft
		$(CC) $(FLAGS) -Ilibft/includes $(SRC) libft/libft.a -o $(NAME)

clean:
		@make -C libft clean
		rm -f $(OBJ)

fclean: clean
		@make -C libft fclean
		rm -f $(NAME)

re: fclean all