/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:01:41 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/12 15:37:34 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*new));
	if (new == NULL)
		return (NULL);
	while (*(char *)(s1 + ++i))
		new[i] = *(char *)(s1 + i);
	j = 0;
	while (*(char *)(s2 + j))
		new[i++] = *(char *)(s2 + j++);
	new[i] = '\0';
	return (new);
}
