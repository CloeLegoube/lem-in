/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/14 15:52:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		init_struct_tube(t_tube **tube)
{
	if (!(*tube = (t_tube*)malloc(sizeof(t_tube))))
		return (0);
	(*tube)->num_tube = 0;
	(*tube)->from = 0;
	(*tube)->to = 0;
	(*tube)->next = NULL;
	(*tube)->str_from = NULL;
	(*tube)->str_to = NULL;
	return (0);
}

int		ft_stock_double_tube(t_anthill *anthill, char *begin, char *end)
{
	t_tube	*new;

	new = NULL;
	init_struct_tube(&new);
	new->str_from = ft_strdup(begin);
	new->str_to = ft_strdup(end);
	new->from = ft_find_room_by_name(anthill, new->str_from);
	new->to = ft_find_room_by_name(anthill, new->str_to);
	if (!anthill->begin_tube)
	{
		new->num_tube = 1;
		anthill->begin_tube = new;
	}
	else
	{
		new->num_tube = anthill->s_tube->num_tube + 1;
		anthill->s_tube->next = new;
	}
	anthill->s_tube = new;
	anthill->end_tube = new;
	return (1);
}

int		ft_if_start_end_exist(t_anthill *anthill, int room)
{
	anthill->s_tube = anthill->begin_tube;
	while (anthill->s_tube)
	{
		if (room == anthill->s_tube->from || room == anthill->s_tube->to )
			return(1);
		anthill->s_tube = anthill->s_tube->next;
	}
	ft_exit(15, anthill, NULL);
	return(0);
}

int		ft_stock_tube(char **tab, t_anthill *anthill, char *line)
{
	int		check;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	check = 0;
	if (ft_tablen(tab) != 2 || count > 1)
		return (0);
	else if (ft_strstart(tab[0], "#"))
		return (1);
	check = ft_stock_double_tube(anthill, tab[0], tab[1]);
	if ((anthill->line_start == 1 || anthill->line_end == 1) && check)
		ft_exit(10, anthill, NULL);
	anthill->nb_tubes++;
	ft_tabdel(tab);
	return (1);
}
