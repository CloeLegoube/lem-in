/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_c_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:46:30 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 18:02:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		p_c_length(t_print *new, va_list arg)
{
	char charac;

	if (ft_strcmp(new->flags, "no-flags"))
		charac = ft_modify_length_c(arg, new);
	else if (new->percentage)
		charac = '%';
	else
		charac = va_arg(arg, int);
	if (charac == 0)
	{
		new->value_zero = 1;
		charac = charac + 48;
	}
	new->string = (char *)malloc(2 * sizeof(*new->string));
	new->string[0] = charac;
	new->string[1] = '\0';
}

void			p_c_conversion(t_print *new, va_list arg)
{
	char *string;

	if (!ft_strcmp(new->flags, "l"))
	{
		new->conversion = ft_indexchr("sSpdDioOuUxXcCb", 'C');
		g_c_conversion(new, arg);
	}
	else
	{
		new->plus = (new->plus) ? 0 : 0;
		new->space = (new->space) ? 0 : 0;
		new->precision = (new->precision) ? 0 : new->precision;
		p_c_length(new, arg);
		if (new->size)
			string = ft_strdup(ft_modify_width(new->string, new));
		else
			string = ft_strdup(new->string);
		free(new->string);
		new->string = ft_strdup(string);
		free(string);
		free(new->htag_prefixe);
	}
}
