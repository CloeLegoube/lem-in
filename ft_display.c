/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 23:23:25 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_display(t_anthill	*anthill)
{
	int len;
	int fourmis;

	len = 0;
	fourmis = anthill->nb_fourmis;
	anthill->s_path = anthill->begin_path;
	if (anthill->s_kind_path->nb_short == 1)
		len = ft_atoi(anthill->s_kind_path->tab_short);
	while (anthill->s_path->num_path != len)
		anthill->s_path = anthill->s_path->next;
	while (fourmis)
	{
		printf("**** DISPLAY ****\n");
		anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		while (anthill->s_path->s_path_room)
		{
			printf("num_room = %d\n", anthill->s_path->s_path_room->num_room);
			printf("coordo[%d][%d]\n\n", anthill->s_path->s_path_room->coordo[0], anthill->s_path->s_path_room->coordo[1]);
			anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;

		}
		fourmis--;
	}
	return (0);
}

int		ft_delete_wrong_path(t_anthill	*anthill)
{
	t_path	*delete_path;
	int 	i;

	delete_path = NULL;
	i = 1;
	anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
		if (anthill->s_path->end_path_room->num_room != anthill->room_end)
		{
			anthill->s_path->previous->next = anthill->s_path->next;
			anthill->s_path->next->previous = anthill->s_path->previous;
			delete_path = anthill->s_path;
			free(delete_path->tab);
			free(delete_path->s_path_room);
			free(delete_path->begin_path_room);
			free(delete_path->end_path_room);
			free(delete_path);
		}
		else
			anthill->s_path->num_path = i++;
		anthill->s_path = anthill->s_path->next;
	}
	return (0);
}
