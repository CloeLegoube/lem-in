/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:21:28 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 09:58:47 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_count_bits(wchar_t *s, int size)
{
	int i;
	int wbit;

	i = 0;
	wbit = 0;
	while (i < size)
	{
		if (s[i] <= 127)
			wbit += 1;
		else if (s[i] <= 2047)
			wbit += 2;
		else if (s[i] <= 65535)
			wbit += 3;
		else if (s[i] <= 2097151)
			wbit += 4;
		i++;
	}
	return (wbit);
}
