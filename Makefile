# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 20:07:47 by clegoube          #+#    #+#              #
#    Updated: 2017/10/14 16:19:47 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror -g

NAME = lem-in

HEAD = lemin.h

SRC = main.c get_next_line.c  ft_display.c ft_utils_fonctions.c ft_check.c \
		ft_add_previous.c ft_free.c ft_free2.c ft_lib.c

STOCK = stock/ft_stock_room.c stock/ft_stock_fourmi.c stock/ft_init_path.c \
		stock/ft_stock_path.c stock/ft_manage_path.c stock/ft_stock_tube.c \
		stock/ft_stock_tube_room.c stock/ft_init_anthill.c

LIB = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

OBJ = $(SRC:.c=.o)
OBJSTOCK = $(STOCK:stock/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@make -C ./printf/
	@$(GCCF) $(SRC) $(STOCK) $(LIB) $(PRINTF) -I $(HEAD) -o $(NAME)

%.o: %.c
	@$(GCCF) -c $<

clean:
	@Make clean -C ./libft/
	@Make clean -C ./printf/
	@rm -Rf $(OBJ) $(OBJSTOCK)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(PRINTF)
	@rm -rf $(NAME)

re: fclean all

run: re
	./$(NAME) < tests/sujet7.map
	@Make clean

.PHONY: all clean
