/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/03 19:47:57 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	available(int num_room, t_anthill *anthill, int yes)
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

static int		if_room_free(int num_room, t_anthill *anthill)
{
    anthill->s_room = anthill->begin_room;
    while (anthill->s_room)
    {
        if (anthill->s_room->num_room != num_room)
            anthill->s_room = anthill->s_room->next;
		else if (anthill->s_room->free)
			return(1);
		else
			return (0);
    }
    return (0);
}

void	ft_for_each_path(t_anthill	*anthill)
{
	if (anthill->s_path->s_path_room)
	{
		// Est-ce que la room est libre ?
		if (if_room_free(anthill->s_path->s_path_room->num_room, anthill))
		{
			anthill->s_fourmi->num_room = anthill->s_path->s_path_room->num_room;
			if (anthill->s_path->s_path_room->num_room != anthill->room_end)
			{
				anthill->s_path->s_path_room->free = 0;
				available(anthill->s_path->s_path_room->num_room, anthill, 0);
				ft_printf("L%d-%s    ", anthill->s_fourmi->num_fourmi, ft_name_by_room(anthill, anthill->s_path->s_path_room->num_room));
			}
			anthill->s_fourmi->position_path = anthill->s_path->s_path_room;
		}
		// La room est prise mais c'est moi qui l'occupe
		else if (anthill->s_fourmi->num_room == anthill->s_path->s_path_room->num_room)
		{
			// Donc je peux occuper la suivante
			if (anthill->s_path->s_path_room->next)
			{

				ft_printf("LLL%d-%s%s%s    ", anthill->s_fourmi->num_fourmi, "\033[1;36m", ft_name_by_room(anthill, anthill->s_path->s_path_room->next->num_room), "\033[0m");
				anthill->s_fourmi->num_room = anthill->s_path->s_path_room->next->num_room;
				anthill->s_path->s_path_room->next->free = 0;
				available(anthill->s_path->s_path_room->next->num_room, anthill, 0);
			}
			// Je libere la room que j'occupais
			available(anthill->s_path->s_path_room->num_room, anthill, 1);
			anthill->s_path->s_path_room->free = 1;
			anthill->s_fourmi->position_path = anthill->s_path->s_path_room->next;
		}

	}
}

t_path	*ft_find_shorter_path(t_anthill	*anthill)
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

void	ft_display(t_anthill	*anthill)
{
	int len;
	int fourmis;

	len = 0;
	fourmis = anthill->nb_fourmis;
	anthill->s_path = ft_find_shorter_path(anthill);
	anthill->s_fourmi = anthill->begin_fourmi;
	while (anthill->end_fourmi->num_room != anthill->room_end)
	{
		// printf("anthill->end_fourmi->num_room %d\n", anthill->end_fourmi->num_room);
		// printf("anthill->room_end %d\n", anthill->room_end);

		anthill->s_fourmi = anthill->begin_fourmi;
		while (anthill->s_fourmi && anthill->end_fourmi->num_room != anthill->room_end)
		{
			// ft_printf("\n> fourmi\n");

			if (anthill->s_fourmi->position_path)
				anthill->s_path->s_path_room = anthill->s_fourmi->position_path;
			else if (anthill->s_fourmi->num_room == anthill->room_end)
				anthill->s_path->s_path_room = NULL;
			else
				anthill->s_path->s_path_room = anthill->s_path->begin_path_room->next;
			ft_for_each_path(anthill);

			anthill->s_fourmi = anthill->s_fourmi->next;
		}
		ft_putchar('\n');
		// ft_printf("\n\n-----\n\n");

	}
}
