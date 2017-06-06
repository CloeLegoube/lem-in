/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_o_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:44:54 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:54:39 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	g_o_conversion(t_print *new, va_list arg)
{
	new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'o');
	new->flags = "l";
	p_o_conversion(new, arg);
}
