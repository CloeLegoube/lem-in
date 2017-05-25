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
		if (if_room_free(anthill->s_path->s_path_room->num_room, anthill))
		{
			anthill->s_fourmi->num_room = anthill->s_path->s_path_room->num_room;
			if (anthill->s_path->s_path_room->num_room != anthill->room_end)
			{
				anthill->s_path->s_path_room->free = 0;
				available(anthill->s_path->s_path_room->num_room, anthill, 0);
			}
			ft_printf("L%d-%d    ", anthill->s_fourmi->num_fourmi, anthill->s_path->s_path_room->num_room);
			anthill->s_fourmi->position_path = anthill->s_path->s_path_room;
		}
		else if (anthill->s_fourmi->num_room == anthill->s_path->s_path_room->num_room)
		{
			if (anthill->s_fourmi->num_room == anthill->room_end)
			{

				ft_printf("LL%d-%d    ", anthill->s_fourmi->num_fourmi, anthill->s_fourmi->num_room);
			}
			if (anthill->s_path->s_path_room->next)
			{

				ft_printf("LLL%d-%d    ", anthill->s_fourmi->num_fourmi, anthill->s_path->s_path_room->next->num_room);
				anthill->s_fourmi->num_room = anthill->s_path->s_path_room->next->num_room;
			}

			available(anthill->s_path->s_path_room->num_room, anthill, 1);
			anthill->s_path->s_path_room->free = 1;
			anthill->s_fourmi->position_path = anthill->s_path->s_path_room->next;
		}

	}
}

void	ft_display(t_anthill	*anthill)
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
	while (anthill->end_fourmi->num_room != anthill->room_end)
	{
		anthill->s_fourmi = anthill->begin_fourmi;
		while (anthill->s_fourmi && anthill->end_fourmi->num_room != anthill->room_end)
		{

			if (anthill->s_fourmi->position_path)
				anthill->s_path->s_path_room = anthill->s_fourmi->position_path;
			else
				anthill->s_path->s_path_room = anthill->s_path->begin_path_room->next;
			ft_for_each_path(anthill);
			anthill->s_fourmi = anthill->s_fourmi->next;
		}
		ft_putchar('\n');
	}
}
