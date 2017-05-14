/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/09 17:21:30 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		init_struct_path(t_room	**room)
{
	if (!(*room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*room)->num_room = 0;
	(*room)->coordo[0] = 0;
	(*room)->coordo[1] = 0;
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->next = NULL;
	return (0);
}

static t_room	*find_room(int from, t_anthill *anthill)
{
    anthill->s_room = anthill->begin_room;
    while (anthill->s_room)
    {
        if (anthill->s_room->num_room != from)
            anthill->s_room = anthill->s_room->next;
        else
            return (anthill->s_room);
    }
    return (anthill->s_room);
}

int		ft_stock_path(t_anthill *anthill)
{
    t_room	*path_from;
    t_room	*path_to;

    path_from = NULL;
    path_to = NULL;
    anthill->s_tube = anthill->begin_tube;
	// printf("***** Structure PATH *****\n");
	while (anthill->s_tube)
	{
        if (anthill->s_tube->from != anthill->room_start)
            anthill->s_tube = anthill->s_tube->next;
        else
        {
            init_struct_path(&path_from);
            path_from = find_room(anthill->s_tube->from, anthill);
            init_struct_path(&path_to);
            path_to = find_room(anthill->s_tube->to, anthill);
            if (!anthill->begin_path)
                anthill->begin_path = path_from;
            else
                anthill->s_path->next = path_from;
            anthill->s_path = path_from;
            anthill->s_path->next = path_to;
            return (0);
        }

		// printf("num_tube = %d\n", anthill->s_tube->num_tube);
		// printf("from %d - to %d\n\n", anthill->s_tube->from, anthill->s_tube->to);
	}


	return (1);
}
