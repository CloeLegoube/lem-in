/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_sign_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:26:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 11:48:39 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_modify_sign(char *string, t_print *new)
{
	char *tmp;

	if (new->plus)
	{
		tmp = ft_strjoin("+", string);
		return (tmp);
	}
	return (ft_strdup(string));
}
