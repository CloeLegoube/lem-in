/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:48:42 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 11:48:50 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	modify_string(t_print *new, int yes,
		char *(*f)(char *, t_print *))
{
	char	*string;
	char	*tmp;

	if (yes)
	{
		tmp = f(new->string, new);
		string = ft_strdup(tmp);
		free(tmp);
		free(new->string);
		new->string = ft_strdup(string);
		free(string);
	}
}

void	modify_wstring(t_print *new, int yes,
		char *(*f)(char *, t_print *))
{
	wchar_t	*string;

	if (yes)
	{
		string = ft_wstrdup((wchar_t *)(f((char *)new->wstring, new)));
		free(new->wstring);
		new->wstring = ft_wstrdup(string);
		free(string);
	}
}
