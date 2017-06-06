/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:47:06 by clegoube          #+#    #+#             */
/*   Updated: 2016/11/06 19:07:58 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[--i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
