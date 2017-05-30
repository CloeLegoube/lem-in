/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/30 21:03:46 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		init_struct_room(t_room	**room, char **tab, t_anthill *anthill)
{
	if (!(*room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*room)->num_room = 0;
	(*room)->name = ft_strnew(ft_strlen(tab[0]));
	(*room)->name = ft_strdup(tab[0]);
	(*room)->coordo[0] = ft_atoi(tab[1]);
	(*room)->coordo[1] = ft_atoi(tab[2]);
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->free = 1;
	(*room)->next = NULL;
	if (anthill->line_start)
		(*room)->start = 1;
	if (anthill->line_end)
		(*room)->end = 1;
	return (0);
}

int		ft_stock_room(char **tab, t_anthill *anthill, char **line)
{
	t_room	*new;

	if ((anthill->line_start || anthill->line_end) && ft_strstart(tab[0], "#"))
		ft_exit(3);
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
		if (ft_strstart(tab[0], "#"))
			return (0);
		ft_printf("atoi %d %d", ft_strdigit(tab[1]), ft_strdigit(tab[2]));
		if (!ft_strdigit(tab[1])|| !ft_strdigit(tab[2]))
			ft_exit(4);
		init_struct_room(&new, tab, anthill);
		if (!anthill->begin_room)
		{
			if (anthill->line_start)
			{
				anthill->room_start = new->num_room;
				anthill->line_start = 0;
			}
			if (anthill->line_end)
			{
				anthill->room_end = new->num_room;
				anthill->line_end = 0;
			}
			anthill->begin_room = new;
		}
		else
		{
			new->num_room = anthill->s_room->num_room + 1;
			if (anthill->line_start)
			{
				anthill->room_start = new->num_room;
				anthill->line_start = 0;
			}
			if (anthill->line_end)
			{
				anthill->room_end = new->num_room;
				anthill->line_end = 0;
			}
			anthill->s_room->next = new;
		}
		anthill->s_room = new;
		// ft_free_tab(&tab);
	}
	// anthill->room_end = 2;
	return (1);
}
