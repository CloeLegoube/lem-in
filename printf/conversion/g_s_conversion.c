/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_s_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 12:12:23 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		if_size(t_print *new)
{
	if (new->size)
	{
		modify_wstring(new, (new->size), ft_modify_width);
		new->string = ft_strdup((char *)new->wstring);
		new->wstring = NULL;
		free(new->wstring);
	}
}

void			g_s_conversion(t_print *new, va_list arg)
{
	wchar_t *argument;

	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	if (!ft_strcmp(new->flags, "h"))
	{
		new->conversion = ft_indexchr("sSpdDioOuUxXcC", 's');
		p_s_conversion(new, arg);
	}
	else
	{
		argument = va_arg(arg, wchar_t*);
		new->wstring = (argument) ?
			ft_wstrdup(argument) : ft_wstrdup(L"(null)");
		modify_wstring(new, (new->checkprecision),
			ft_modify_precision);
		if_size(new);
		if (new->wstring)
			new->len = ft_strcut_unicode(1, (char *)new->wstring,
			ft_wstrlen(new->wstring));
		free(new->htag_prefixe);
	}
}
