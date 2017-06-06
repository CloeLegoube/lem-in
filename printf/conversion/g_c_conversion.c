/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_c_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:44:14 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:53:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		initialize_wstring(wchar_t charac, t_print *new)
{
	if (MB_CUR_MAX > 1 || charac <= 255)
	{
		new->wstring = (wchar_t *)malloc(2 * sizeof(*new->wstring));
		new->wstring[0] = charac;
		new->wstring[1] = '\0';
	}
	else
	{
		new->len = -1;
		return ;
	}
}

static void		g_c_length(t_print *new, va_list arg)
{
	wchar_t charac;

	charac = va_arg(arg, int);
	if (charac == 0)
	{
		new->value_zero = 1;
		charac = charac + 48;
	}
	if (charac <= 127)
		new->wbyte = 0;
	else if (charac <= 2047)
		new->wbyte = 1;
	else if (charac <= 65535)
		new->wbyte = 2;
	else if (charac <= 2097151)
		new->wbyte = 3;
	initialize_wstring(charac, new);
}

void			g_c_conversion(t_print *new, va_list arg)
{
	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	new->precision = (new->precision) ? 0 : 0;
	g_c_length(new, arg);
	if (new->size && new->wstring)
	{
		modify_wstring(new, (new->size), ft_modify_width);
		new->string = ft_strdup((char *)new->wstring);
		new->wstring = NULL;
		free(new->wstring);
	}
	if (new->wstring)
		new->len = ft_strcut_unicode(1, (char *)new->wstring,
		ft_wstrlen(new->wstring));
	free(new->htag_prefixe);
}
