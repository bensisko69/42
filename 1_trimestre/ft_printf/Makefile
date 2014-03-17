# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/12/16 16:59:11 by lrenoud-          #+#    #+#              #
#    Updated: 2013/12/16 17:01:48 by lrenoud-         ###   ########.fr        #
#                                                                              #
# ***************************************************************************  #

NAME = ft_printf

LIB_DIR = ./libft
LIB_NAME = libft.a

SRC = m

OBJ = $(SRC:.c=.o)

FLAG_COMP = -Wall -Wextra -Werror -g

all: $(LIB_DIR)/$(LIB_NAME) $(NAME)

$(LIB_DIR)/$(LIB_NAME):
	@(cd $(LIB_DIR) && $(MAKE))

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ)

%.o: %.c
	@gcc -c $(FLAG_COMP) $^

clean:
	@rm -f $(OBJ)

fclean: fcleanlib
	@rm -f $(NAME)

fcleanlib:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

re: fcleanlib fclean all
