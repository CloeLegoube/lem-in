/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/19 21:47:12 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		init_struct_room(t_room **room, char **tab, t_anthill *anthill)
{
	int		i;

	i = 0;
	while (tab[0][i])
		if (tab[0][i++] == '-')
			ft_exit(15, anthill, NULL);
	if (!(*room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*room)->num_room = 1;
	(*room)->name = ft_strdup(tab[0]);
	(*room)->coordo[0] = ft_atoi(tab[1]);
	(*room)->coordo[1] = ft_atoi(tab[2]);
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->free = 1;
	(*room)->previous = 0;
	(*room)->round = -42;
	(*room)->next = NULL;
	(*room)->liste_tubes = NULL;
	(*room)->len_tube = 0;
	if (anthill->line_start)
		(*room)->start = 1;
	if (anthill->line_end)
		(*room)->end = 1;
	return (0);
}

int		ft_stock_room2(char **tab, t_anthill *anthill, char **line)
{
	t_room	*new;

	new = NULL;
	if (ft_strstart(tab[0], "#"))
	{
		ft_tabdel(tab);
		return (1);
	}
	if (ft_strstart(*line, "L") ||
		(!ftdigit(tab[1]) || !ftdigit(tab[2])))
	{
		ft_tabdel(tab);
		return (0);
	}
	init_struct_room(&new, tab, anthill);
	if (!anthill->begin_room)
		if_not_begin_room(anthill, new);
	else
		if_begin_room(anthill, new);
	anthill->s_room = new;
	anthill->nb_rooms++;
	ft_tabdel(tab);
	return (1);
}

int		ft_stock_room(char **tab, t_anthill *anthill, char **line)
{
	if (!ft_tablen(tab))
		return (0);
	if (ft_tablen(tab) != 3)
		return (not_a_room(tab, anthill, line));
	if (ft_strchr(tab[1], '-'))
		return (0);
	else
		return (ft_stock_room2(tab, anthill, line));
	ft_tabdel(tab);
	return (0);
}
