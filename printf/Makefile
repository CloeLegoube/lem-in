# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:22:13 by clegoube          #+#    #+#              #
#    Updated: 2017/04/03 12:18:20 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc
FLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a
SRCLIB = ft_printf.c ft_display.c\
				ft_stock.c ft_manage_struc.c

LIBFT = libft/ft_atoi.c libft/ft_itobase.c libft/ft_putwstr.c \
		libft/ft_convert_base.c libft/ft_putwchar.c libft/ft_strdup.c \
		libft/ft_putnbr_positif.c libft/ft_strchrstr.c libft/ft_strsub.c \
		libft/ft_strchr.c libft/ft_strjoin.c libft/ft_strcmp.c libft/ft_itoa.c\
 		libft/ft_itoa_positif.c libft/ft_putstr.c libft/ft_putchar.c \
 		libft/ft_strnew.c libft/ft_strlen.c libft/ft_wstrdup.c \
		libft/ft_strrchr.c libft/ft_indexchr.c libft/ft_wstrlen.c \
		libft/ft_wstrnew.c libft/ft_wstrcmp.c libft/ft_wstrsub.c \
		libft/ft_strcut_unicode.c libft/ft_memset.c libft/ft_memcpy.c \
		libft/ft_wmemset.c libft/ft_straddend.c libft/ft_bzero.c \
		libft/ft_wchar.c libft/ft_strcpy_unicode.c

CONVERSION 	= 	conversion/p_s_conversion.c conversion/g_s_conversion.c \
				conversion/p_p_conversion.c conversion/p_d_conversion.c \
				conversion/g_d_conversion.c conversion/p_i_conversion.c \
				conversion/p_o_conversion.c conversion/g_o_conversion.c \
				conversion/p_u_conversion.c conversion/g_u_conversion.c \
				conversion/p_x_conversion.c conversion/g_x_conversion.c \
				conversion/p_c_conversion.c conversion/g_c_conversion.c \
				conversion/p_b_conversion.c conversion/no_conversion.c

MODIFICATION =	modify/ft_modify_length.c modify/ft_modify_htag.c \
				modify/ft_modify_precision.c modify/ft_modify_sign_plus.c \
				modify/ft_modify_width.c modify/ft_modify_space.c \
				modify/ft_modify_string.c modify/ft_modify_color.c

OBJ =	$(SRCLIB:.c=.o)
OBJLIBFT= $(LIBFT:libft/%.c=%.o)
OBJCONV= $(CONVERSION:conversion/%.c=%.o)
OBJMODIF= $(MODIFICATION:modify/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) $(OBJLIBFT) $(OBJCONV) $(OBJMODIF) && ranlib $(NAME)

%.o: %.c
	@$(GCCF) $(FLAGS) -c $(SRCLIB) $(LIBFT) $(CONVERSION) $(MODIFICATION)

%.o: libft/%.c
	@$(GCCF) $(FLAGS) -c $(LIBFT)

%.o: conversion/%.c
	@$(GCCF) $(FLAGS) -c $(CONVERSION)

%.o: modify/%.c
	@$(GCCF) $(FLAGS) -c $(CONVERSION)

clean:
	@rm -f $(OBJ) $(OBJLIBFT) $(OBJCONV) $(OBJMODIF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
