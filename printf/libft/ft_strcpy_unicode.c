/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:21:28 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 10:20:50 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strcpy_unicode(int is_wstring, char *dest, const char *source)
{
	int		i;
	int		byte_count;

	i = -1;
	byte_count = 0;
	if (is_wstring)
	{
		while (((wchar_t *)source)[++i])
			byte_count += ft_wchar((wchar_t *)(dest + byte_count),
			((wchar_t *)source)[i]);
		*((wchar_t *)dest + byte_count) = 0;
	}
	else
	{
		while (source[++i])
			dest[i] = source[i];
		*(dest + i) = 0;
	}
	return (dest);
}
