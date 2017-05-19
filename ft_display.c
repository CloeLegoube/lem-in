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

	anthill->s_fourmi = anthill->begin_fourmi;
	printf("***** Structure FOURMIS ***** \n");
	printf("end_fourmi->num_room %d\n", anthill->end_fourmi->num_room);
	while (anthill->end_fourmi->num_room != anthill->room_end)
	{
		anthill->s_fourmi = anthill->begin_fourmi;
		// printf("end_fourmi->num_room %d\n", anthill->end_fourmi->num_room);
		while (anthill->s_fourmi && anthill->end_fourmi->num_room != anthill->room_end)
		{
			// printf("***** New fourmi ***** \n");
			// printf("num_fourmi = %d\n", anthill->s_fourmi->num_fourmi);
			// printf("num_room of fourmi = %d\n\n", anthill->s_fourmi->num_room);
			if (anthill->s_fourmi->position_path)
				anthill->s_path->s_path_room = anthill->s_fourmi->position_path;
			else
				anthill->s_path->s_path_room = anthill->s_path->begin_path_room->next;
			if (anthill->s_path->s_path_room)
			{
				// printf("check_room = %d\n", anthill->s_path->s_path_room->num_room);
				// printf("free ? %d\n\n", anthill->s_path->s_path_room->free);
				if (anthill->s_path->s_path_room->free)
				{
					anthill->s_fourmi->num_room = anthill->s_path->s_path_room->num_room;
					if (anthill->s_path->s_path_room->num_room != anthill->room_end)
						anthill->s_path->s_path_room->free = 0;
					printf("L%d-%d ", anthill->s_fourmi->num_fourmi, anthill->s_path->s_path_room->num_room);
					anthill->s_fourmi->position_path = anthill->s_path->s_path_room;

				}
				else if (anthill->s_fourmi->num_room == anthill->s_path->s_path_room->num_room)
				{
					if (anthill->s_fourmi->num_room == anthill->room_end)
					{
						printf("L%d-%d ", anthill->s_fourmi->num_fourmi, anthill->s_fourmi->num_room);
						// anthill->s_fourmi->position_path = NULL;

					}

					if (anthill->s_path->s_path_room->next)
					{
						printf("L%d-%d ", anthill->s_fourmi->num_fourmi, anthill->s_path->s_path_room->next->num_room);
						anthill->s_fourmi->num_room = anthill->s_path->s_path_room->next->num_room;
					}
					// printf("On libére la salle %d\n", anthill->s_path->s_path_room->num_room);

					anthill->s_path->s_path_room->free = 1;
					anthill->s_fourmi->position_path = anthill->s_path->s_path_room->next;
				}
			}
			anthill->s_fourmi = anthill->s_fourmi->next;
		}
		printf("\n");
		// anthill->s_fourmi = anthill->s_fourmi->next;

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
