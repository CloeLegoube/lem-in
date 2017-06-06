/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:42:11 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 14:58:35 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_wstrcmp(wchar_t *s1, wchar_t *s2)
{
	int i;

	i = 0;
	while (*(wchar_t*)(s1 + i) &&
				*(wchar_t*)(s2 + i) &&
				*(wchar_t*)(s1 + i) == *(wchar_t*)(s2 + i))
		i++;
	return (*(wchar_t*)(s1 + i) - *(wchar_t*)(s2 + i));
}
