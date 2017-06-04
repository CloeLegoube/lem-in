# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 20:07:47 by clegoube          #+#    #+#              #
#    Updated: 2017/06/03 18:20:34 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror -g -fsanitize=address

NAME = lem-in

HEAD = lemin.h

SRC = main.c get_next_line.c  ft_display.c ft_utils_fonctions.c ft_check.c ft_free.c

STOCK = stock/ft_stock_room.c stock/ft_stock_fourmi.c stock/ft_init_path.c \
		stock/ft_stock_path2.c stock/ft_manage_path.c stock/ft_stock_tube.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)
OBJSTOCK = $(STOCK:stock/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(GCCF) $(SRC) $(STOCK) libftprintf.a $(LIB) -I $(HEAD) -o $(NAME)

%.o: %.c
	@$(GCCF) -c $<

clean:
	@Make clean -C ./libft/
	@rm -Rf $(OBJ) $(OBJSTOCK)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(NAME)

re: fclean all

run: re
	./$(NAME) < tests/big
	@Make clean

.PHONY: all clean
