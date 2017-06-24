/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/24 18:42:40 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_room	*find_room2(int target, t_anthill *anthill, t_room **room)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (anthill->s_room->num_room != target)
			anthill->s_room = anthill->s_room->next;
		else
		{
			if (!(*room = (t_room*)malloc(sizeof(t_room))))
				return (0);
			(*room)->num_room = anthill->s_room->num_room;
			(*room)->name = anthill->s_room->name;
			(*room)->name = ft_strdup(anthill->s_room->name);
			(*room)->coordo[0] = anthill->s_room->coordo[0];
			(*room)->coordo[1] = anthill->s_room->coordo[1];
			(*room)->start = anthill->s_room->start;
			(*room)->end = anthill->s_room->end;
			(*room)->free = 1;
			(*room)->previous = anthill->s_room->previous;
			(*room)->next = NULL;
			(*room)->liste_tubes = NULL;
			return (*room);
		}
	}
	return (*room);
}

int		ft_add_new_room(t_anthill *anthill, int room, t_path **path)
{
	t_room	*path_to;

	path_to = NULL;
	path_to = find_room2(room, anthill, &path_to);
	if (path_to)
	{
		path_to->next = (*(path))->begin_path_room;
		(*(path))->begin_path_room = path_to;
		(*(path))->stop = 0;
	}
	return (1);
}

void	ft_stock_path(t_anthill *anthill, t_path *begin_path)
{
	int		room;
	t_room	*boucle_room;

	anthill->s_path = begin_path;
	while (anthill->s_path &&
			anthill->s_path->begin_path_room->num_room != anthill->room_start)
	{
		room = anthill->s_path->begin_path_room->previous;
		boucle_room = anthill->begin_room;
		while (boucle_room)
		{
			if (room == boucle_room->num_room)
			{
				ft_add_new_room(anthill, boucle_room->num_room,
					&(anthill->s_path));
				break ;
			}
			else
				boucle_room = boucle_room->next;
		}
		if (anthill->s_path->begin_path_room->num_room == anthill->room_start)
			anthill->s_path = anthill->s_path->next;
	}
}
