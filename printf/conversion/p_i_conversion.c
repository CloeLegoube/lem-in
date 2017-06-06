/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_i_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:46:54 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 12:24:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		p_i_conversion(t_print *new, va_list arg)
{
	p_d_conversion(new, arg);
}
