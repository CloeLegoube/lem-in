# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 20:07:47 by clegoube          #+#    #+#              #
#    Updated: 2017/10/19 22:21:57 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror -g

NAME = lem-in

HEAD = lemin.h

SRC = main.c get_next_line.c  ft_display.c ft_utils_fonctions.c ft_check.c \
		ft_add_previous.c ft_free.c ft_free2.c ft_lib.c \
		ft_stock_room.c ft_stock_fourmi.c ft_init_path.c \
		ft_stock_path.c ft_manage_path.c ft_stock_tube.c \
		ft_stock_tube_room.c ft_init_anthill.c \
		ft_stock_if_room.c

LIB = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@make -C ./printf/
	$(GCCF) $(OBJ) $(LIB) $(PRINTF) -I $(HEAD) -o $(NAME)

%.o: $(addprefix stock/, %.c) Makefile $(HEAD)
	$(GCCF) -c $<

%.o:%.c Makefile $(HEAD)
	$(GCCF) -c $<

clean:
	@Make clean -C ./libft/
	@Make clean -C ./printf/
	@rm -Rf $(OBJ)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(PRINTF)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re
