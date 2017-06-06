/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:11:45 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 10:03:08 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		ft_putwchar2(wchar_t c)
{
	char	bit;

	bit = (c >> 18) + 0xF0;
	write(1, &bit, 1);
	bit = ((c >> 12) & 0x3F) + 0x80;
	write(1, &bit, 1);
	bit = ((c >> 6) & 0x3F) + 0x80;
	write(1, &bit, 1);
	bit = (c & 0x3F) + 0x80;
	write(1, &bit, 1);
}

void			ft_putwchar(wchar_t c)
{
	char	bit;

	if (c <= 127)
		ft_putchar(c);
	else if (c <= 2047)
	{
		bit = (c >> 6) + 0xC0;
		write(1, &bit, 1);
		bit = (c & 0x3F) + 0x80;
		write(1, &bit, 1);
	}
	else if (c <= 65535)
	{
		bit = (c >> 12) + 0xE0;
		write(1, &bit, 1);
		bit = ((c >> 6) & 0x3F) + 0x80;
		write(1, &bit, 1);
		bit = (c & 0x3F) + 0x80;
		write(1, &bit, 1);
	}
	else if (c <= 2097151)
	{
		ft_putwchar2(c);
	}
}
