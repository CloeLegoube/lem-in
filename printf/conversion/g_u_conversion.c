/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_u_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:24 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:54:27 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		g_u_conversion(t_print *new, va_list arg)
{
	new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'u');
	new->flags = "l";
	p_u_conversion(new, arg);
}
