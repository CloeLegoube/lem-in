/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:56:05 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 09:56:09 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		ft_binary2(void)
{
	char ctest;

	ctest = 0xe2;
	write(1, &ctest, 1);
	ctest = 0x98;
	write(1, &ctest, 1);
	ctest = 0x82;
	write(1, &ctest, 1);
	ctest = 0x82;
	write(1, &ctest, 1);
}

void			ft_binary(wchar_t c)
{
	char ctest;

	if (c <= 127)
		ft_putchar(c);
	else if (c <= 2047)
	{
		ctest = (c >> 6) + 0x80;
		write(1, &ctest, 1);
		ctest = 0x82;
		write(1, &ctest, 1);
	}
	else if (c <= 65535)
	{
		ctest = (c >> 6) + 0x80;
		write(1, &ctest, 1);
		ctest = 0x98;
		write(1, &ctest, 1);
		ctest = 0x82;
		write(1, &ctest, 1);
	}
	else if (c <= 2097151)
	{
		ft_binary2();
	}
}
