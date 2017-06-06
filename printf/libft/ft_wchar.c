/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:37:41 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 19:23:00 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_wchar(wchar_t *dest, wchar_t c)
{
	int count;

	count = 0;
	*dest = 0;
	if (c <= 127 && (count = 1))
		*dest = c;
	else if (c <= 2047 && (count = 2))
	{
		*dest = (c >> 6) + 0xc0;
		*dest += ((c & 0x3F) + 0x80) << 8;
	}
	else if (c <= 65535 && (count = 3))
	{
		*dest = (c >> 12) + 0xE0;
		*dest += (((c >> 6) & 0x3F) + 0x80) << 8;
		*dest += ((c & 0x3F) + 0x80) << 16;
	}
	else if (c <= 2097151 && (count = 4))
	{
		*dest = (c >> 18) + 0xF0;
		*dest += (((c >> 12) & 0x3F) + 0x80) << 8;
		*dest += (((c >> 6) & 0x3F) + 0x80) << 16;
		*dest += ((c & 0x3F) + 0x80) << 24;
	}
	return (count);
}
