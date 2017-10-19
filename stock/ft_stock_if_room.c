/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_if_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:45:22 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/19 21:47:40 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	if_not_begin_room(t_anthill *anthill, t_room *new)
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

void	if_begin_room(t_anthill *anthill, t_room *new)
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

int		not_a_room(char **tab, t_anthill *anthill, char **line)
{
	if (ft_strstart(tab[0], "#"))
	{
		if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
		{
			if (ft_strstr(*line, "##start"))
				anthill->line_start = 1;
			if (ft_strstr(*line, "##end"))
				anthill->line_end = 1;
		}
		ft_tabdel(tab);
		return (1);
	}
	ft_tabdel(tab);
	return (0);
}
