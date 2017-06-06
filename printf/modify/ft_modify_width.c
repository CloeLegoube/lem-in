/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 12:15:14 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		if_p_conversion(t_print *new, char **string, int *i,
				char **result)
{
	int		is_wstring;

	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S')) ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'C'));
	if (ft_strcmp(new->htag_prefixe, "no") &&
		new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p') &&
		(!new->value_zero || (new->value_zero && new->zero)))
	{
		ft_strcpy_unicode(is_wstring, *result + *i, new->htag_prefixe);
		new->size -= ft_strlen(new->htag_prefixe);
		*i = ft_strlen(new->htag_prefixe);
		free(new->htag_prefixe);
		new->htag_prefixe = ft_strdup("no");
		if (new->value_zero && new->zero)
		{
			free(*string);
			*string = ft_strdup("");
		}
	}
}

static void		add_suffixe(t_print *new, char **result, int byte_len,
				int is_wstring)
{
	if (new->sign_less && new->size != byte_len && new->sign_less--)
		(*result)[new->size - byte_len - 1] = '-';
	else if (new->plus && new->size != byte_len && new->plus--)
		(*result)[new->size - byte_len - 1] = '+';
	if (ft_strcmp(new->htag_prefixe, "no") &&
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p') ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'o') && new->htag)))
	{
		if (new->size - byte_len <= (int)(ft_strlen(new->htag_prefixe)))
		{
			ft_strcpy_unicode(is_wstring, (*result) + new->size - byte_len,
				new->htag_prefixe);
			if (!new->value_zero)
				(*result) = (*result) + ft_strlen(new->htag_prefixe);
		}
		else
			ft_strcpy_unicode(is_wstring, (*result) + (new->size - byte_len -
					ft_strlen(new->htag_prefixe)), new->htag_prefixe);
		free(new->htag_prefixe);
		new->htag_prefixe = ft_strdup("no");
	}
}

static int		add_prefixe(t_print *new, int i, char **result)
{
	int		is_wstring;

	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S')) ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'C'));
	if (new->sign_less && new->sign_less-- && new->size--)
		*result[i++] = '-';
	else if (new->plus && new->plus-- && new->size--)
		*result[i++] = '+';
	else if (new->space && new->space-- && new->size--)
		*result[i++] = ' ';
	if (ft_strcmp(new->htag_prefixe, "no") && new->htag)
	{
		ft_strcpy_unicode(is_wstring, *result + i, new->htag_prefixe);
		new->size -= ft_strlen(new->htag_prefixe);
		i = ft_strlen(new->htag_prefixe);
	}
	return (i);
}

static void		ft_conditionless(char *string, char *result,
	int len_string, t_print *new)
{
	int		byte_len;
	int		is_wstring;

	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S')) ||
				(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'C'));
	byte_len = ft_strcut_unicode(is_wstring, (char *)string, len_string);
	if ((new->size - byte_len) < 0)
		byte_len = new->size;
	if (new->less)
	{
		ft_strcpy_unicode(is_wstring, result, string);
		ft_memset(result + byte_len, ' ', new->size - byte_len);
	}
	else
	{
		if (new->zero)
			ft_memset(result, '0', new->size - byte_len);
		else
			ft_memset(result, ' ', new->size - byte_len);
		add_suffixe(new, &result, byte_len, is_wstring);
		ft_strcpy_unicode(is_wstring, result + new->size - byte_len, string);
	}
}

char			*ft_modify_width(char *string, t_print *new)
{
	int		len_string;
	char	*result;
	int		i;
	int		is_wstring;

	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S')) ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'C'));
	if (ft_strcmp(new->htag_prefixe, "no") &&
	new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p') && new->value_zero)
	{
		string = ft_strdup(new->htag_prefixe);
		if (!new->zero)
		{
			free(new->htag_prefixe);
			new->htag_prefixe = ft_strdup("no");
		}
	}
	len_string = is_wstring ? ft_wstrlen((wchar_t *)string) : ft_strlen(string);
	result = is_wstring ? (char *)ft_wstrnew(new->size) : ft_strnew(new->size);
	i = (new->less || new->zero) ? add_prefixe(new, 0, &result) : 0;
	if (new->less || new->zero)
		if_p_conversion(new, &string, &i, &result);
	ft_conditionless((char *)string, result + i, len_string, new);
	return (result);
}
