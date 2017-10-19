/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tube_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/19 21:38:06 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	ft_count_tube_room(t_anthill *anthill, int room)
{
	int count;

	count = 0;
	anthill->s_tube = anthill->begin_tube;
	while (anthill->s_tube)
	{
		if (anthill->s_tube->from == room ||
			anthill->s_tube->to == room)
			count++;
		anthill->s_tube = anthill->s_tube->next;
	}
	anthill->s_room->len_tube = count;
	if (room == anthill->room_end && count == 0)
		ft_exit(11, anthill, NULL);
}

void	ft_stock_tube_room(t_anthill *anthill)
{
	int i;

	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		ft_count_tube_room(anthill, anthill->s_room->num_room);
		anthill->s_room->liste_tubes = (int *)malloc(sizeof(int) *
			(anthill->s_room->len_tube + 1));
		anthill->s_tube = anthill->begin_tube;
		i = -1;
		while (anthill->s_tube)
		{
			if (anthill->s_tube->from == anthill->s_room->num_room)
				anthill->s_room->liste_tubes[++i] = anthill->s_tube->to;
			if (anthill->s_tube->to == anthill->s_room->num_room)
				anthill->s_room->liste_tubes[++i] = anthill->s_tube->from;
			anthill->s_tube = anthill->s_tube->next;
		}
		anthill->s_room = anthill->s_room->next;
	}
}
