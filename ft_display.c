/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/06 18:48:49 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_display_l(t_anthill *anthill, int room, int next)
{
	anthill->s_fourmi->num_room = room;
	if (next)
	{
		anthill->s_path->s_path_room->next->free = 0;
	}
	else
	{
		anthill->s_path->s_path_room->free = 0;
		anthill->s_fourmi->position_path = anthill->s_path->s_path_room;
	}
	available(room, anthill, 0);
	ft_printf("%sL%d%s-%s%s%s    ", "\033[1;35m", anthill->s_fourmi->num_fourmi,
	"\033[0m", "\033[1;32m", ft_name_by_room(anthill, room), "\033[0m");
}

void	ft_for_each_path(t_anthill *anthill)
{
	if (anthill->s_path->s_path_room)
	{
		if (if_room_free(anthill->s_path->s_path_room->num_room, anthill))
			ft_display_l(anthill, anthill->s_path->s_path_room->num_room, 0);
		else if (anthill->s_fourmi->num_room ==
			anthill->s_path->s_path_room->num_room)
		{
			if (anthill->s_path->s_path_room->next)
				ft_display_l(anthill,
					anthill->s_path->s_path_room->next->num_room, 1);
			available(anthill->s_path->s_path_room->num_room, anthill, 1);
			anthill->s_path->s_path_room->free = 1;
			anthill->s_fourmi->position_path =
			anthill->s_path->s_path_room->next;
		}
	}
}

t_path	*ft_find_shorter_path(t_anthill *anthill)
{
	anthill->s_path = anthill->end_path;
	while (anthill->s_path)
	{
		if (anthill->s_path->end_path_room->num_room == anthill->room_end)
			return (anthill->s_path);
		anthill->s_path = anthill->s_path->previous;
	}
	return (anthill->s_path);
}

void	ft_display(t_anthill *anthill)
{
	int len;
	int fourmis;

	len = 0;
	fourmis = anthill->nb_fourmis;
	anthill->s_path = ft_find_shorter_path(anthill);
	anthill->s_fourmi = anthill->begin_fourmi;
	while (anthill->end_fourmi->num_room != anthill->room_end)
	{
		anthill->s_fourmi = anthill->begin_fourmi;
		while (anthill->s_fourmi &&
				anthill->end_fourmi->num_room != anthill->room_end)
		{
			if (anthill->s_fourmi->position_path)
				anthill->s_path->s_path_room = anthill->s_fourmi->position_path;
			else if (anthill->s_fourmi->num_room == anthill->room_end)
				anthill->s_path->s_path_room = NULL;
			else
				anthill->s_path->s_path_room =
					anthill->s_path->begin_path_room->next;
			ft_for_each_path(anthill);
			anthill->s_fourmi = anthill->s_fourmi->next;
		}
		ft_putchar('\n');
	}
}
