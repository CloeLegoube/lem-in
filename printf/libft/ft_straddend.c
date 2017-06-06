/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:17:34 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 10:04:16 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_straddend(char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = ft_strnew(len1 + len2);
	i = 0;
	j = 0;
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	return (result);
}
