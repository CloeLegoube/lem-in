# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:55:10 by jjaouen           #+#    #+#              #
#    Updated: 2017/05/09 16:37:32 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror

NAME = lem-in

HEAD = lemin.h

SRC = main.c get_next_line.c lemin.c ft_stock.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(GCCF) $(SRC) $(LIB) -I $(HEAD) -o $(NAME)

%.o: %.c
	@$(GCCF) -c $<

clean:
	@Make clean -C ./libft/
	@rm -Rf $(OBJ)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(NAME)

re: fclean all

run: re
	./$(NAME) < sujet1.map

.PHONY: all clean
