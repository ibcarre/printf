# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 16:11:47 by ibaaziz           #+#    #+#              #
#    Updated: 2024/11/25 16:20:42 by ibaaziz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = ft_printf.h

SRC = ./ft_printf.c

OBJ = $(SRC:.c=.o)

FLAGS += -Werror -Wextra -Wall -I $(INC)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

all : $(NAME)
	cd libft && make $@
	
clean:
	rm -f $(OBJ)
	cd libft && make $@

fclean: clean
	rm -f $(NAME)
	cd libft && make $@

re : fclean all
	cd libft && make $@
