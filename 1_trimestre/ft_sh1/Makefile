#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 19:58:56 by lrenoud-          #+#    #+#              #
#    Updated: 2014/01/14 20:15:42 by lrenoud-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1

INCLUDE_DIR = ./includes/

LIB_DIR = ./libft/includes/

SRC = ft_sh1.c \
		list.c \
		unsetenv.c\
		setenv.c\
		access.c\
		cd.c\
		do_command.c\
		ft_erreur.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/

FLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIB_DIR)

all: libft/libft.a $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIBFT) -lft

libft/libft.a:
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean: cleanlib
	rm -f $(OBJ)

fclean: clean cleanlib
	rm -f $(NAME)

cleanlib:
	make -C ./libft clean

fcleanlib:
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
