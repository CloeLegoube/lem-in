/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:44:38 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/15 21:26:16 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		*ft_wmemset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		*(wchar_t *)(b + i) = (wchar_t)c;
		i++;
	}
	return (b);
}
