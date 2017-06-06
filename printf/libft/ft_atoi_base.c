/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:20:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/04 10:20:49 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_check_atoi_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int index;
	int display;
	int size_base;

	index = 0;
	display = 0;
	sign = 1;
	while (base[index])
		index++;
	size_base = index;
	index = 0;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\v' ||
			str[index] == '\f' || str[index] == '\r' || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			sign = -1;
	while (str[index] && (ft_check_atoi_base(str[index], base) != -1
	|| (sign = 0)))
		display = display * size_base +
		(ft_check_atoi_base(str[index++], base)) * sign;
	return (sign ? display : 0);
}
