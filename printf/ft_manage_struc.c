/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:59:20 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 11:49:00 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_initialize_struct(t_print *new)
{
	new->conversion = 42;
	new->htag = 0;
	new->htag_prefixe = ft_strdup("no");
	new->plus = 0;
	new->less = 0;
	new->percentage = 0;
	new->zero = 0;
	new->sign_less = 0;
	new->value_zero = 0;
	new->space = 0;
	new->precision = 0;
	new->checkprecision = 0;
	new->size = 0;
	new->flags = "no-flags";
	new->string = NULL;
	new->result = NULL;
	new->strlen = 0;
	new->wstring = NULL;
	new->wbyte = 0;
	new->len = 0;
	new->bold = 0;
	new->wildcard = 0;
	new->index = g_start + 1;
}

void		ft_manage_struc(va_list arg, t_print *new)
{
	g_f[s] = p_s_conversion;
	g_f[S] = g_s_conversion;
	g_f[p] = p_p_conversion;
	g_f[d] = p_d_conversion;
	g_f[D] = g_d_conversion;
	g_f[i] = p_i_conversion;
	g_f[o] = p_o_conversion;
	g_f[O] = g_o_conversion;
	g_f[u] = p_u_conversion;
	g_f[U] = g_u_conversion;
	g_f[x] = p_x_conversion;
	g_f[X] = g_x_conversion;
	g_f[c] = p_c_conversion;
	g_f[C] = g_c_conversion;
	g_f[b] = p_b_conversion;
	g_f[Q] = no_conversion;
	g_f[new->conversion](new, arg);
}

void		ft_manage_conversion(char *conversion, t_print *new, va_list arg)
{
	int len_conversion;

	len_conversion = ft_strlen(conversion);
	while (new->index < len_conversion && !ft_strchr("sSpdDioOuUxXcCbn%",
		conversion[new->index]))
	{
		if (!ft_strchr("#+-*0123456789 .hljz%", conversion[new->index]))
		{
			new->string = ft_strsub(conversion, new->index, 1);
			return ;
		}
		if (ft_strchr("#+-0 .", conversion[new->index]))
			ft_stock_attributes(new, conversion, arg);
		ft_stock_size(new, conversion, arg);
		if (!new->checkprecision)
			ft_stock_precision(new, conversion, arg);
		ft_stock_flags(new, conversion);
	}
	ft_stock_conversion(new, conversion, len_conversion);
}
