/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:21:28 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 10:23:38 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_strcut_unicode(int is_wstring, char *string, int size)
{
	int		count;
	int		bytes;

	count = -1;
	bytes = 0;
	if (is_wstring)
	{
		while (++count <= size - 1 && ((wchar_t *)string)[count])
			if (((wchar_t *)string)[count] <= 127)
				bytes += 1;
			else if (((wchar_t *)string)[count] <= 2047)
				bytes += 2;
			else if (((wchar_t *)string)[count] <= 65535)
				bytes += 3;
			else if (((wchar_t *)string)[count] <= 2097151)
				bytes += 4;
		((wchar_t *)string)[count] = 0;
	}
	else
	{
		while (++count <= size - 1 && string[count])
			bytes++;
		string[count] = 0;
	}
	return (bytes);
}
