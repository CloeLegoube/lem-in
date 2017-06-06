/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 19:03:53 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_string(t_print *new)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(new->string))
	{
		if ((new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'c')) &&
			new->value_zero && new->string[i] == '0')
		{
			if ((new->zero && i == ft_strlen(new->string) - 1) ||
				!new->zero)
				ft_putchar('\0');
			else
				ft_putchar(new->string[i]);
		}
		else
			ft_putchar(new->string[i]);
		i++;
	}
	g_strlen += ft_strlen(new->string);
	free(new->string);
}

void		ft_display_wstring(t_print *new)
{
	size_t i;

	i = 0;
	while (i < ft_wstrlen(new->wstring))
	{
		if (new->value_zero && new->wstring[i] == '0')
			ft_putwchar('\0');
		else
			ft_putwchar(new->wstring[i]);
		i++;
	}
	g_strlen += new->len;
	free(new->wstring);
}

int			ft_display_last_string(char *conversion)
{
	char *string;

	if (g_end < (int)ft_strlen(conversion))
	{
		string = ft_strsub(conversion, g_end, ft_strlen(conversion));
		ft_putstr(string);
		g_strlen += ft_strlen(string);
		free(string);
	}
	return (g_strlen);
}
