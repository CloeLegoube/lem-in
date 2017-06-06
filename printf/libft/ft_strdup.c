/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:36:14 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/06 12:23:27 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = -1;
	copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*copy));
	if (copy == NULL)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
