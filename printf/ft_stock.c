/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 19:14:40 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_stock_attributes(t_print *new, char *conversion, va_list arg)
{
	if (conversion[new->index] == '#' && new->index++)
		new->htag = 1;
	if (conversion[new->index] == '+' && new->index++)
		new->plus = 1;
	if (conversion[new->index] == '-' && new->index++)
		new->less = 1;
	if (conversion[new->index] == '0' && new->index++)
		new->zero = 1;
	if (conversion[new->index] == ' ' && new->index++)
		new->space = 1;
	if (conversion[new->index] == '.')
		ft_stock_precision(new, conversion, arg);
}

void		ft_stock_size(t_print *new, char *conversion, va_list arg)
{
	int		tmp;

	if (conversion[new->index] == '*' && new->index++)
	{
		new->size = va_arg(arg, uintmax_t);
		if (new->size < 0)
		{
			new->size = new->size * -1;
			new->less = 1;
		}
	}
	else if (conversion[new->index] > '0' && conversion[new->index] <= '9')
	{
		tmp = new->index;
		while (conversion[new->index] >= '0' && conversion[new->index] <= '9')
			new->index++;
		new->size = ft_atoi(conversion + tmp);
	}
}

void		ft_stock_precision(t_print *new, char *conversion, va_list arg)
{
	int tmp;

	if (conversion[new->index] == '.' && new->index++)
	{
		new->checkprecision = 1;
		tmp = new->index;
		if (conversion[new->index] == '*' && new->index++)
		{
			new->precision = va_arg(arg, uintmax_t);
			if (new->precision < 0)
			{
				new->precision = 0;
				new->checkprecision = 0;
			}
		}
		else if (conversion[new->index] < '0' || conversion[new->index] > '9')
			new->precision = -1;
		else
		{
			while (conversion[new->index] >= '0' &&
			conversion[new->index] <= '9')
				new->index++;
			new->precision = ft_atoi(conversion + tmp);
		}
	}
}

void		ft_stock_flags(t_print *new, char *conversion)
{
	if (ft_strchr("hljz", conversion[new->index]))
	{
		if (!ft_strcmp(new->flags, "no-flags") || !ft_strcmp(new->flags, "h")
			|| !ft_strcmp(new->flags, "hh"))
		{
			if (conversion[new->index] == 'l' && new->index++)
				new->flags = (conversion[new->index] == 'l' && new->index++) ?
				"ll" : "l";
			else if (conversion[new->index] == 'h' && new->index++)
				new->flags = (conversion[new->index] == 'h' && new->index++) ?
				"hh" : "h";
			else if (conversion[new->index] == 'j' && new->index++)
				new->flags = "j";
			else if (conversion[new->index] == 'z' && new->index++)
				new->flags = "z";
		}
		else
			new->index++;
	}
}

void		ft_stock_conversion(t_print *new, char *conversion,
			int len_conversion)
{
	if (new->index < len_conversion && ft_strchr("%", conversion[new->index])
		&& new->index++)
	{
		new->conversion = ft_indexchr("sSpdDioOuUxXcCb", 'c');
		new->percentage = 1;
	}
	else if (new->index < len_conversion && ft_strchr("sSpdDioOuUxXcCb",
		conversion[new->index]))
		new->conversion = ft_indexchr("sSpdDioOuUxXcCb",
		conversion[new->index++]);
}
