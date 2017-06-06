/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:18:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 10:18:57 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int				ft_check_nbr_base(char *base)
{
	int		i;
	int		j;
	int		count;

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

static void		ft_stock_result(uintmax_t nbr, char *base, int k, char *tab)
{
	int		display;
	int		i;
	char	*temp;
	int		base_len;

	display = 0;
	i = 0;
	base_len = ft_strlen(base);
	temp = (char*)malloc(256 * sizeof(char));
	while (nbr != 0)
	{
		temp[i++] = display * base_len + nbr % base_len;
		nbr = nbr / base_len;
	}
	while (i-- > 0)
		tab[k++] = base[0 + temp[i]];
	tab[k] = 0;
	free(temp);
}

char			*ft_itobase(uintmax_t nbr, char *base)
{
	int		k;
	char	*tab;
	int		base_len;

	tab = (char*)malloc(256 * sizeof(char));
	base_len = ft_strlen(base);
	while (base[base_len] || (k = 0))
		base_len++;
	if (*base && base_len != 1 && ft_check_nbr_base(base))
		ft_stock_result(nbr, base, k, tab);
	return (tab);
}
