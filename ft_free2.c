/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/23 19:22:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_path(t_anthill *anthill)
{
	t_room	*room;

	free(anthill->s_path->tab);
	if (anthill->s_path->begin_path_room)
	{
		anthill->s_path->s_path_room =
		anthill->s_path->begin_path_room;
		while (anthill->s_path->s_path_room)
		{
			room = anthill->s_path->s_path_room->next;
			if (anthill->s_path->s_path_room)
			{
				free(anthill->s_path->s_path_room->name);
				free(anthill->s_path->s_path_room);
			}
			anthill->s_path->s_path_room = room;
		}
	}
	free(anthill->s_path);
}

void	ft_free(t_anthill *anthill)
{
	ft_free_lines(anthill);
	ft_free_path(anthill);
	ft_free_fourmis(anthill);
	ft_free_tubes(anthill);
	ft_free_rooms(anthill, anthill->begin_room);
	free(anthill);
}
