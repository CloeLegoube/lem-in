/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_previous.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/23 18:51:26 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		if_room_previous(int room, t_anthill *anthill)
{
	t_room	*path_room;

	path_room = anthill->begin_room;
	while (path_room)
	{
		if (room == path_room->num_room)
		{
			if (path_room->previous != 0)
				return (1);
		}
		path_room = path_room->next;
	}
	return (0);
}

void	add_previous(int room, int prev, int num_round, t_anthill *anthill)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (room == anthill->s_room->num_room)
		{
			anthill->s_room->previous = prev;
			anthill->s_room->round = num_round;
		}
		anthill->s_room = anthill->s_room->next;
	}
}

void	ft_construct_the_path(t_anthill *anthill, t_room **room, int start,
		int num_round)
{
	int		i;
	t_room	*tmp;

	if ((*room)->num_room == start)
		start = 0;
	i = 0;
	while (i < (*room)->len_tube)
	{
		tmp = *room;
		if (!if_room_previous((*room)->liste_tubes[i], anthill))
		{
			add_previous((*room)->liste_tubes[i], (*room)->num_room,
						num_round, anthill);
			*room = tmp;
		}
		i++;
	}
}

int		ft_add_the_previous(t_anthill *anthill, int start)
{
	int		num_round;
	t_room	*room;
	int		stop;

	num_round = 0;
	stop = 0;
	room = NULL;
	while (!stop)
	{
		room = anthill->begin_room;
		num_round++;
		while (room)
		{
			if (room->num_room == start || room->round == num_round - 1)
			{
				if (room->num_room == anthill->room_end)
					stop = 1;
				ft_construct_the_path(anthill, &room, start, num_round);
			}
			room = room ? room = room->next : NULL;
		}
		if (!stop && num_round == anthill->nb_rooms)
			ft_exit(20, anthill, NULL);
	}
	return (1);
}
