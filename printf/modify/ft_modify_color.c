/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:48:42 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 18:40:04 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_modify_color(va_list arg, t_print *new)
{
	char		*tmp;
	char		*code;
	char		*color;
	uintmax_t	d;

	d = va_arg(arg, uintmax_t);
	color = ft_itoa(d);
	if (new->bold)
		code = ft_strdup("\033[1;");
	else
		code = ft_strdup("\033[");
	if (new->wstring)
	{
		new->string = ft_strdup((char *)new->wstring);
		free(new->wstring);
		new->wstring = NULL;
	}
	tmp = ft_straddend(ft_straddend(ft_straddend(
			ft_straddend(code, color), "m"), new->string), "\033[0m");
	free(new->string);
	free(color);
	free(code);
	new->string = ft_strdup(tmp);
	free(tmp);
}
