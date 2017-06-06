/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_d_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:44:38 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:54:35 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	g_d_conversion(t_print *new, va_list arg)
{
	new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'd');
	new->flags = "l";
	p_d_conversion(new, arg);
}
