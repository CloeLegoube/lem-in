/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room_tube.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 23:29:23 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		init_struct_room(t_room	**room, char **tab, t_anthill *anthill)
{
	if (!(*room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*room)->num_room = 0;
	(*room)->name = ft_strnew(ft_strlen(tab[0]));
	(*room)->name = ft_strdup(tab[0]);
	(*room)->coordo[0] = ft_atoi(tab[1]);
	(*room)->coordo[1] = ft_atoi(tab[2]);
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->free = 1;
	(*room)->next = NULL;
	if (anthill->line_start)
		(*room)->start = 1;
	if (anthill->line_end)
		(*room)->end = 1;
	return (0);
}

static int		init_struct_tube(t_tube	**tube)
{
	if (!(*tube = (t_tube*)malloc(sizeof(t_tube))))
		return (0);
	(*tube)->num_tube = 0;
	(*tube)->from = 0;
	(*tube)->to = 0;
	(*tube)->next = NULL;
	return (0);
}

int		ft_strdigit(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			count++;
		else
			return (0);
		i++;
	}
	if (i == count)
		return (1);
	else
		return (0);
}


int		ft_stock_room(char **tab, t_anthill *anthill, char **line)
{
	t_room	*new;

	if (ft_tablen(tab) != 3)
	{
		if (ft_strstr(*line, "##start") || ft_strstr(*line, "##end"))
		{
			if (ft_strstr(*line, "##start"))
				anthill->line_start = 1;
			if (ft_strstr(*line, "##end"))
				anthill->line_end = 1;
		}
		return (0);
	}
	else
	{
		new = NULL;
		ft_printf("atoi %d %d", ft_strdigit(tab[1]), ft_strdigit(tab[2]));
		if (!ft_strdigit(tab[1])|| !ft_strdigit(tab[2]))
		{
			anthill->error = -42;
			return (0);
		}
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
		ft_free_tab(&tab);
	}
	return (1);
}

int		ft_stock_tube(char **tab, t_anthill *anthill)
{
	t_tube	*new;

	if (ft_tablen(tab) != 2)
		return (0);
	else
	{
		new = NULL;
		init_struct_tube(&new);
		new->num_tube = anthill->nb_tubes;
		new->str_from = ft_strnew(ft_strlen(tab[0]));
		new->str_from = ft_strdup(tab[0]);
		new->str_to = ft_strnew(ft_strlen(tab[1]));
		new->str_to = ft_strdup(tab[1]);
		// printf("\n***** FIND ROOMS / from*****\n");
		// printf("new->str_from = %s - \n");

		new->from = ft_find_room_by_name(anthill, new->str_from);
		// printf("***** FIND ROOMS / to*****\n");

		new->to = ft_find_room_by_name(anthill, new->str_to);
		if (!anthill->begin_tube)
			anthill->begin_tube = new;
		else
			anthill->s_tube->next = new;
		anthill->s_tube = new;
		// printf("Numero tube : %d - Coordo[%d][%d]\n", anthill->s_tube->num_tube, anthill->s_tube->from, anthill->s_tube->to);
		ft_free_tab(&tab);
	}
	return (1);
}
