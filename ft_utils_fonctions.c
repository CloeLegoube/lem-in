/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:46:33 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/16 22:23:29 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		available(int num_room, t_anthill *anthill, int yes)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (anthill->s_room->num_room != num_room)
			anthill->s_room = anthill->s_room->next;
		else
		{
			if (yes)
				anthill->s_room->free = 1;
			else
				anthill->s_room->free = 0;
			return (0);
		}
	}
	return (1);
}

int		if_room_free(int num_room, t_anthill *anthill)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (anthill->s_room->num_room != num_room)
			anthill->s_room = anthill->s_room->next;
		else if (anthill->s_room->free)
			return (1);
		else
			return (0);
	}
	return (0);
}

int		ft_find_room_by_name(t_anthill *anthill, char *name)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (!ft_strcmp(name, anthill->s_room->name))
			return (anthill->s_room->num_room);
		anthill->s_room = anthill->s_room->next;
	}
	// ft_exit(6, anthill, NULL);
	return (0);
}

char	*ft_name_by_room(t_anthill *anthill, int room)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (room == anthill->s_room->num_room)
			return (anthill->s_room->name);
		anthill->s_room = anthill->s_room->next;
	}
	return (NULL);
}
