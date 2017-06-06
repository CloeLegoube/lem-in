/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:34:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/12 11:42:58 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_strchrstr(const char *s, char *c)
{
	int		i;
	int		j;
	int		start;

	j = 0;
	i = 0;
	while (s[i] != '%')
		i++;
	start = i;
	while (c[j])
	{
		if ((char)c[j] == '\0')
			return ((char *)&s[ft_strlen(s)]);
		while (s[i])
		{
			if (s[i] == c[j])
				return (ft_strsub(s, start + 1, i - start + 1));
			i++;
		}
		if (s[i] == c[j])
			return (ft_strsub(s, start + 1, i - start + 1));
		j++;
	}
	return (NULL);
}
