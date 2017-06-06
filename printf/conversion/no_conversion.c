/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:54:54 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		no_conversion(t_print *new, va_list arg)
{
	new->space = (new->space) ? 0 : 0;
	if (new->string == NULL)
		new->string = ft_strdup("");
	arg = NULL;
	modify_string(new, (new->checkprecision && !new->htag),
			ft_modify_precision);
	modify_string(new, (new->size), ft_modify_width);
	modify_string(new, (new->space), ft_modify_space);
	modify_string(new, (new->plus), ft_modify_sign);
	free(new->htag_prefixe);
}
