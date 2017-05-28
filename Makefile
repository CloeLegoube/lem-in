# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 20:07:47 by clegoube          #+#    #+#              #
#    Updated: 2017/05/25 19:38:57 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Wextra -Werror

NAME = lem-in

HEAD = lemin.h

SRC = main.c get_next_line.c lemin.c ft_stock_room_tube.c ft_stock_fourmi.c \
ft_init_path.c ft_stock_path.c ft_manage_path.c ft_kind_path.c ft_display.c \
ft_utils_fonctions.c ft_check.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(GCCF) $(SRC) libftprintf.a $(LIB) -I $(HEAD) -o $(NAME)

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
	./$(NAME) < tests/sujet3.map

.PHONY: all clean
