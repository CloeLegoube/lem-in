/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_u_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:47:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 12:12:40 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		p_u_conversion(t_print *new, va_list arg)
{
	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	if (new->zero && new->checkprecision && new->precision == 0)
		new->zero = 0;
	new->string = ft_itoa_positif(ft_modify_length_uoxx(arg, new));
	new->value_zero = (new->string[0] == '0') ? 1 : new->value_zero;
	if (new->value_zero && new->checkprecision && new->precision == 0)
		new->precision = -1;
	modify_string(new, (new->checkprecision), ft_modify_precision);
	modify_string(new, (new->size), ft_modify_width);
	free(new->htag_prefixe);
}
