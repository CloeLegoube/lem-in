/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:20:06 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/04 10:20:11 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_check_putnbr_base(char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		count = 0;
		while (base[j] != '\0')
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_itoa_base(int nbr, char *base, int base_len, char *tab)
{
	int		display;
	int		k;
	int		i;
	char	*temp;

	while (base[base_len] || (k = 0))
		base_len++;
	if (*base && base_len != 1 && ft_check_putnbr_base(base))
	{
		if (nbr < 0)
			if ((nbr = -nbr))
				tab[k++] = '-';
		display = 0;
		i = 0;
		temp = (char*)malloc(256 * sizeof(char));
		while (nbr != 0)
		{
			temp[i++] = display * base_len + nbr % base_len;
			nbr = nbr / base_len;
		}
		while (i-- > 0)
			tab[k++] = base[0 + temp[i]];
		tab[k] = 0;
	}
	return (tab);
}
