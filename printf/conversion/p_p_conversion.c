/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_p_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 11:44:05 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	p_p_conversion(t_print *new, va_list arg)
{
	char		*string;
	uintmax_t	nb;

	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	nb = va_arg(arg, uintmax_t);
	string = NULL;
	if (nb == 0 && !new->checkprecision)
		new->value_zero = 1;
	free(new->htag_prefixe);
	if (nb == 0 && !new->checkprecision)
		new->htag_prefixe = ft_strdup("0x0");
	else
		new->htag_prefixe = ft_strdup("0x");
	new->string = ft_itobase(nb, "0123456789abcdef");
	modify_string(new, (new->checkprecision), ft_modify_precision);
	if (new->size)
		string = ft_modify_width(new->string, new);
	else
		string = ft_strjoin(new->htag_prefixe, new->string);
	free(new->string);
	new->string = ft_strdup(string);
	free(string);
	free(new->htag_prefixe);
}
