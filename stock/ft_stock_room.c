/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/03 17:36:03 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		init_struct_room(t_room	**room, char **tab, t_anthill *anthill)
{
	if (!(*room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*room)->num_room = 1;
	(*room)->name = ft_strnew(ft_strlen(tab[0]));
	(*room)->name = ft_strdup(tab[0]);
	(*room)->coordo[0] = ft_atoi(tab[1]);
	(*room)->coordo[1] = ft_atoi(tab[2]);
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->free = 1;
	(*room)->previous = 0;
	(*room)->round = -42;
	(*room)->next = NULL;
	(*room)->liste_tubes = NULL;
	(*room)->len_tube = 0;
	if (anthill->line_start)
		(*room)->start = 1;
	if (anthill->line_end)
		(*room)->end = 1;
	return (0);
}

// void	ft_room_previous(t_anthill *anthill)
// {
// 	anthill->s_room = anthill->begin_room;
// 	// printf("***** Structure ROOMS *****\n");
// 	while (anthill->s_room)
// 	{
// 		anthill->s_room->previous = anthill->room_start;
// 		printf("previous = %d\n", anthill->s_room->previous);
// 		anthill->s_room = anthill->s_room->next;
// 	}
// }

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
}

void	ft_stock_tube_room(t_anthill *anthill)
{
	int i;

	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		ft_count_tube_room(anthill, anthill->s_room->num_room);
		anthill->s_room->liste_tubes = (int *)malloc(sizeof(int) * anthill->s_room->len_tube);
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

int		ft_stock_room(char **tab, t_anthill *anthill, char **line)
{
	t_room	*new;

	if ((anthill->line_start || anthill->line_end) && ft_strstart(tab[0], "#"))
		ft_exit(3);
	if (ft_tablen(tab) != 3)
	{
		if (ft_strstart(tab[0], "#"))
		{
			if (ft_strstr(*line, "##start") || ft_strstr(*line, "##end"))
			{
				if (ft_strstr(*line, "##start"))
					anthill->line_start = 1;
				if (ft_strstr(*line, "##end"))
					anthill->line_end = 1;
			}
			return (1);
		}

		return (0);
	}
	else
	{
		new = NULL;
		if (ft_strstart(tab[0], "#"))
			return (1);
			// ft_printf("atoi %d %d", ft_strdigit(tab[1]), ft_strdigit(tab[2]));
		// ft_printf("stock room -%s-%s-%s-\n", tab[0], tab[1], tab[2]);
		if (!ft_strdigit(tab[1])|| !ft_strdigit(tab[2]))
			ft_exit(4);
		init_struct_room(&new, tab, anthill);
		if (!anthill->begin_room)
		{
			if (anthill->line_start)
			{
				anthill->room_start = new->num_room;
				anthill->line_start = 0;
			}
			if (anthill->line_end)
			{
				anthill->room_end = new->num_room;
				anthill->line_end = 0;
			}
			anthill->begin_room = new;
		}
		else
		{
			new->num_room = anthill->s_room->num_room + 1;
			if (anthill->line_start)
			{
				anthill->room_start = new->num_room;
				anthill->line_start = 0;
			}
			if (anthill->line_end)
			{
				anthill->room_end = new->num_room;
				anthill->line_end = 0;
			}
			anthill->s_room->next = new;
		}
		anthill->s_room = new;
		anthill->nb_rooms++;
		return (1);

		// ft_free_tab(&tab);
	}
	// anthill->room_end = 2;
	return (0);
}
