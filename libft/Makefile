# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaiko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 15:22:38 by omaiko            #+#    #+#              #
#    Updated: 2017/11/20 17:04:50 by omaiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c \
	  ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	  ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	  ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	  ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_whitespace.c \
	  ft_tests_for_is.c ft_swap.c ft_create_elem.c ft_elements.c \
	  ft_putstr_array.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
#IFLAGS = -c
HEADERS = libft.h
DEL = /bin/rm -f
AR = ar rcs

.PHONY = all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
		@$(AR) $@ $^
		@echo "\033[32mCompiled successfully :)\033[0m"

%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@echo "\033[36mBuilding: $@\033[0m"

clean:
		@$(DEL) $(OBJ)
		@echo "\033[31mObjects for libft deleted\033[0m"

fclean: clean
		@$(DEL) $(NAME)
		@echo "\033[31mFile 'libft.a' deleted\033[0m"

42:
		@echo "\033[34;40m        :::      ::::::::\033[0m"
		@echo "\033[34;40m      :+:      :+:    :+:\033[0m"
		@echo "\033[34;40m    +:+ +:+         +:+  \033[0m"
		@echo "\033[34;40m  +#+  +:+\033[0m       \033[33;40m+#+     \033[0m"
		@echo "\033[33;40m+#+#+#+#+#+   +#+        \033[0m"
		@echo "\033[33;40m     #+#    #+#          \033[0m"
		@echo "\033[33;40m    ###   ###########    \033[0m"

norm:
		@norminette *.?

re: fclean all
