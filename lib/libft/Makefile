# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:00:34 by lrenoud-          #+#    #+#              #
#    Updated: 2014/03/17 14:15:12 by lrenoud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_strlen.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memset.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memmove.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_putnbr.c\
	  ft_strcmp.c\
	  ft_strdel.c\
	  ft_putendl.c\
	  ft_strclr.c\
	  ft_memdel.c\
	  ft_putnbr_fd.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_strncpy.c\
	  ft_atoi.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_strstr.c\
	  ft_strncat.c\
	  ft_strcat.c\
	  ft_strlcat.c\
	  ft_strnstr.c\
	  ft_strncmp.c\
	  ft_strnequ.c\
	  ft_strequ.c\
	  ft_memalloc.c\
	  ft_strtrim.c\
	  ft_strnew.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strjoin.c\
	  ft_strsub.c\
	  ft_itoa.c\
	  ft_strsplit.c\
	  get_next_line.c\

OBJ = $(SRC:.c=.o)

SRC_DIR = ./srcs/

INCLUDE_DIR = ./includes/

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: $(SRC_DIR)/%.c
	gcc -c $(FLAG) -I $(INCLUDE_DIR) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
