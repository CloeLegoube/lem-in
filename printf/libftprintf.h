/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:21:44 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 11:49:09 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <wctype.h>
# include <strings.h>
# include <limits.h>
# include <locale.h>
# include <stdint.h>
# include "libft/libft.h"

enum				e_conversion
{
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C,
	b,
	Q = 42,
};

enum				e_couleur
{
	eoc,
	noir = 30,
	rouge,
	vert,
	jaune,
	bleu,
	magenta,
	cyan,
	blanc,
};

typedef struct		s_print
{
	int				conversion;
	int				htag;
	int				wildcard;
	char			*htag_prefixe;
	int				plus;
	int				less;
	int				percentage;
	int				zero;
	int				sign_less;
	int				value_zero;
	int				space;
	int				precision;
	int				checkprecision;
	int				size;
	char			*flags;
	char			*string;
	char			*result;
	int				strlen;
	wchar_t			*wstring;
	int				wbyte;
	int				len;
	int				bold;
	int				index;
}					t_print;

int					g_strlen;
int					g_start;
int					g_end;
int					ft_printf(char *format, ...);
void				ft_initialize_struct(t_print *new);
void				ft_manage_conversion(char *conversion, t_print *new,
					va_list arg);
void				ft_manage_struc(va_list arg, t_print *new);
void				ft_stock_attributes(t_print *new, char *conversion,
					va_list arg);
void				ft_stock_size(t_print *new, char *conversion, va_list arg);
void				ft_stock_precision(t_print *new, char *conversion,
					va_list arg);
void				ft_stock_flags(t_print *new, char *conversion);
void				ft_stock_conversion(t_print *new, char *conversion,
					int len_conversion);
char				*ft_modify_htag(va_list arg, t_print *new, char *base);
intmax_t			ft_modify_length_di(va_list arg, t_print *new);
uintmax_t			ft_modify_length_uoxx(va_list arg, t_print *new);
char				ft_modify_length_c(va_list arg, t_print *new);
char				*ft_modify_precision(char *string, t_print *new);
char				*ft_modify_sign(char *string, t_print *new);
char				*ft_modify_space(char *string, t_print *new);
char				*ft_modify_width(char *string, t_print *new);
void				ft_modify_color(va_list arg, t_print *new);
void				modify_string(t_print *new, int yes,
					char *(*f)(char *, t_print *));
void				modify_wstring(t_print *new, int yes,
					char *(*f)(char *, t_print *));
int					ft_display_last_string(char *conversion);
void				ft_display_wstring(t_print *new);
void				ft_display_string(t_print *new);
void				(*g_f[101])(t_print*, va_list);
void				p_c_conversion(t_print *new, va_list arg);
void				g_c_conversion(t_print *new, va_list arg);
void				p_d_conversion(t_print *new, va_list arg);
void				g_d_conversion(t_print *new, va_list arg);
void				p_i_conversion(t_print *new, va_list arg);
void				p_o_conversion(t_print *new, va_list arg);
void				g_o_conversion(t_print *new, va_list arg);
void				p_p_conversion(t_print *new, va_list arg);
void				p_s_conversion(t_print *new, va_list arg);
void				g_s_conversion(t_print *new, va_list arg);
void				p_u_conversion(t_print *new, va_list arg);
void				g_u_conversion(t_print *new, va_list arg);
void				p_x_conversion(t_print *new, va_list arg);
void				g_x_conversion(t_print *new, va_list arg);
void				p_b_conversion(t_print *new, va_list arg);
void				no_conversion(t_print *new, va_list arg);

#endif
