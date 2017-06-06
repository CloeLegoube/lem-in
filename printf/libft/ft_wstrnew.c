/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:11:05 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/15 19:02:38 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t	*string;
	size_t	i;

	i = 0;
	string = (wchar_t *)malloc((size + 1) * sizeof(*string));
	if (string == NULL)
		return (NULL);
	string[size] = 0;
	while (i < size)
	{
		*(string + i) = 0;
		i++;
	}
	return (string);
}
