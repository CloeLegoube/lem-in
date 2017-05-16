# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 20:07:47 by clegoube          #+#    #+#              #
#    Updated: 2017/05/12 21:07:12 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror

NAME = lem-in

HEAD = lemin.h

SRC = main.c get_next_line.c lemin.c ft_stock_room_tube.c ft_stock_fourmi.c \
ft_stock_path.c ft_stock_path2.c

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
	./$(NAME) < sujet3.map

.PHONY: all clean
