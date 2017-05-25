/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 23:23:25 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_find_who(t_anthill *anthill, int len, int nb, int if_short)
{
	int i;
	char *tab;

	tab = NULL;
	i = 0;

	if (!(tab = (char *)malloc(sizeof(char) * (nb + 1))))
		return;
	anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
		if (anthill->s_path->len == len)
			tab[i++] = anthill->s_path->num_path + 48;
		anthill->s_path = anthill->s_path->next;
	}
	tab[i] = '\0';
	if (if_short)
	{
		anthill->s_kind_path->len_short = len;
		anthill->s_kind_path->nb_short = nb;
		anthill->s_kind_path->tab_short = tab;
	}
	else
	{
		anthill->s_kind_path->len_long = len;
		anthill->s_kind_path->nb_long = nb;
		anthill->s_kind_path->tab_long = tab;
	}
}

void		ft_find_kind_path(t_anthill	*anthill, int if_short)
{
	int len;
	int nb;

	nb = 0;
	anthill->s_path = anthill->begin_path;
	len = anthill->s_path->len;
	while (anthill->s_path)
	{
		if ((if_short && anthill->s_path->len <= len) ||
		 	(!if_short && anthill->s_path->len >= len))
			len = anthill->s_path->len;
		anthill->s_path = anthill->s_path->next;
	}
	anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
		if (anthill->s_path->len == len)
		{
			nb++;
			if (if_short)
				anthill->s_path->shorter = 1;
			else
				anthill->s_path->longer = 1;
		}
		anthill->s_path = anthill->s_path->next;
	}
	ft_find_who(anthill, len, nb, if_short);
}

void	init_struct_kind_path(t_anthill	*anthill)
{
	if (!(anthill->s_kind_path = (t_kind_path*)malloc(sizeof(t_kind_path))))
		return;
	anthill->s_kind_path->len_short = 0;
	anthill->s_kind_path->nb_short = 0;
	anthill->s_kind_path->tab_short = NULL;
	anthill->s_kind_path->len_long = 0;
	anthill->s_kind_path->nb_long = 0;
	anthill->s_kind_path->tab_long = NULL;
	anthill->s_kind_path->wrong_path = NULL;
	ft_find_kind_path(anthill, 1);
	ft_find_kind_path(anthill, 0);
	return;
}
