/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room_tube.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 23:29:23 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		init_struct_room(t_room	**room, char **tab, t_anthill *anthill)
{
	if (!(*room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*room)->num_room = ft_atoi(tab[0]);
	(*room)->coordo[0] = ft_atoi(tab[1]);
	(*room)->coordo[1] = ft_atoi(tab[2]);
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->next = NULL;
	if (anthill->line_start)
	{
		anthill->room_start = (*room)->num_room;
		anthill->line_start = 0;
		(*room)->start = 1;
	}
	if (anthill->line_end)
	{
		anthill->room_end = (*room)->num_room;
		anthill->line_end = 0;
		(*room)->end = 1;
	}
	return (0);
}

static int		init_struct_tube(t_tube	**tube)
{
	if (!(*tube = (t_tube*)malloc(sizeof(t_tube))))
		return (0);
	(*tube)->num_tube = 0;
	(*tube)->from = 0;
	(*tube)->to = 0;
	(*tube)->next = NULL;
	return (0);
}

int		ft_stock_room(char **tab, t_anthill *anthill, char **line)
{
	t_room	*new;

	if (ft_tablen(tab) != 3)
	{
		if (ft_strstr(*line, "##start") || ft_strstr(*line, "##end"))
		{
			if (ft_strstr(*line, "##start"))
				anthill->line_start = 1;
			if (ft_strstr(*line, "##end"))
				anthill->line_end = 1;
		}
		return (0);
	}
	else
	{
		new = NULL;
		init_struct_room(&new, tab, anthill);
		if (!anthill->begin_room)
			anthill->begin_room = new;
		else
			anthill->s_room->next = new;
		anthill->s_room = new;
		ft_free_tab(&tab);
	}
	return (1);
}

int		ft_stock_tube(char **tab, t_anthill *anthill)
{
	t_tube	*new;

	if (ft_tablen(tab) != 2)
		return (0);
	else
	{
		new = NULL;
		init_struct_tube(&new);
		new->num_tube = anthill->nb_tubes;
		new->from = ft_atoi(tab[0]);
		new->to = ft_atoi(tab[1]);
		if (!anthill->begin_tube)
			anthill->begin_tube = new;
		else
			anthill->s_tube->next = new;
		anthill->s_tube = new;
		// printf("Numero tube : %d - Coordo[%d][%d]\n", anthill->s_tube->num_tube, anthill->s_tube->from, anthill->s_tube->to);
		ft_free_tab(&tab);
	}
	return (1);
}
