/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:41:27 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 12:14:20 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int			ft_strcut_wunicode(char *string, int size)
{
	int		count;
	int		bytes;

	count = 0;
	bytes = 0;
	while (bytes <= size && ((wchar_t *)string)[count])
	{
		if (((wchar_t *)string)[count] <= 127)
			bytes += 1;
		else if (((wchar_t *)string)[count] <= 2047)
			bytes += 2;
		else if (((wchar_t *)string)[count] <= 65535)
			bytes += 3;
		else if (((wchar_t *)string)[count] <= 2097151)
			bytes += 4;
		if (bytes <= size)
			count++;
	}
	((wchar_t *)string)[count] = 0;
	return (bytes);
}

static int			no_htag_no_given_precision(char *string, t_print *new)
{
	int		is_wstring;
	int		is_string;
	int		(*cmp)(void *, void *);

	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S'));
	is_string = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 's'));
	cmp = is_wstring ? (int (*)(void *, void *))ft_wstrcmp :
		(int (*)(void *, void *))ft_strcmp;
	if (!new->htag && new->checkprecision &&
		(-1 == new->precision || 0 == new->precision))
	{
		if (!cmp(string, "0") || !cmp(string, ""))
			return (1);
		new->precision = (!is_wstring && !is_string);
	}
	return (0);
}

char				*ft_modify_precision(char *string, t_print *new)
{
	void	*result;
	int		bytes;
	int		is_wstring;
	int		is_string;

	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S'));
	is_string = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 's'));
	if (no_htag_no_given_precision(string, new))
		return ((char *)ft_wstrnew(0));
	if (is_wstring)
		ft_strcut_wunicode(string, new->precision);
	bytes = (!is_wstring && !is_string) ? (int)ft_strlen(string) :
			ft_strcut_unicode(is_wstring, string, new->precision);
	if (!is_wstring && !is_string && (new->precision - bytes) > 0)
	{
		result = ft_strnew(new->precision);
		ft_memset(result, '0', new->precision - bytes);
		ft_memcpy(result + new->precision - bytes, string, bytes);
		return ((char *)result);
	}
	if (is_wstring)
		return ((char *)(ft_wstrdup((wchar_t *)string)));
	return (ft_strdup((char *)string));
}
