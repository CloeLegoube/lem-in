/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_d_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:46:41 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:55:45 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static	void		clean_struct(t_print *new)
{
	if (new->checkprecision && new->precision == 0)
		new->precision = -1;
	if (new->zero && new->space && new->sign_less)
		new->space = 0;
	if (new->zero && new->checkprecision)
		new->zero = 0;
	if (new->plus || new->sign_less || (new->size && !new->zero))
		new->space = 0;
	if (new->precision >= new->size)
		new->size = 0;
	if (new->checkprecision && new->htag)
		new->htag = 0;
}

void				p_d_conversion(t_print *new, va_list arg)
{
	char *string;

	new->string = ft_itoa(ft_modify_length_di(arg, new));
	if (new->string[0] == '-')
	{
		string = ft_strsub(new->string, 1, ft_strlen(new->string));
		free(new->string);
		new->string = ft_strdup(string);
		free(string);
		new->sign_less = 1;
		new->plus = 0;
	}
	clean_struct(new);
	modify_string(new, (new->checkprecision), ft_modify_precision);
	modify_string(new, (new->size), ft_modify_width);
	modify_string(new, (new->space), ft_modify_space);
	modify_string(new, (new->plus), ft_modify_sign);
	string = (new->sign_less && !new->space) ? ft_strjoin("-", new->string)
			: ft_strdup(new->string);
	free(new->string);
	new->string = ft_strdup(string);
	free(string);
	free(new->htag_prefixe);
}
