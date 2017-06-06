/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:36:14 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/01 17:22:07 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

wchar_t		*ft_wstrdup(wchar_t *s1)
{
	wchar_t	*copy;
	int		i;

	i = -1;
	copy = (wchar_t *)malloc((ft_wstrlen(s1) + 1) * sizeof(*copy));
	if (copy == NULL)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
