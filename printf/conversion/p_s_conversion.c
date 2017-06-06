/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:47:14 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 12:11:25 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		p_s_conversion(t_print *new, va_list arg)
{
	char *argument;

	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	if (!ft_strcmp(new->flags, "l"))
	{
		new->conversion = ft_indexchr("sSpdDioOuUxXcCb", 'S');
		g_s_conversion(new, arg);
	}
	else
	{
		argument = va_arg(arg, char*);
		new->string = (!argument) ? ft_strdup("(null)") : ft_strdup(argument);
		modify_string(new, (new->checkprecision), ft_modify_precision);
		modify_string(new, (new->size), ft_modify_width);
		free(new->htag_prefixe);
	}
}
