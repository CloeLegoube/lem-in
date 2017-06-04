/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/04 15:23:51 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		init_struct_tube(t_tube	**tube)
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
		new->str_from = ft_strnew(ft_strlen(begin));
		new->str_from = ft_strdup(begin);
		new->str_to = ft_strnew(ft_strlen(end));
		new->str_to = ft_strdup(end);
		// printf("\n***** FIND ROOMS / from*****\n");
		// printf("new->str_from = %s - \n");

		new->from = ft_find_room_by_name(anthill, new->str_from);
		// printf("***** FIND ROOMS / to*****\n");

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
		// printf("Numero tube : %d - Coordo[%d][%d]\n", anthill->s_tube->num_tube, anthill->s_tube->from, anthill->s_tube->to);
	return (1);
}


int		ft_stock_tube(char **tab, t_anthill *anthill)
{
	int check;

	check = 0;
	if (ft_tablen(tab) != 2)
		return (0);
	else if (ft_strstart(tab[0], "#"))
		return (1);
	// else
	// 	ft_exit(9);
	check = ft_stock_double_tube(anthill, tab[0], tab[1]);
	if ((anthill->line_start == 1 || anthill->line_end == 1) && check)
		ft_exit(10);
	// ft_stock_double_tube(anthill, tab[1], tab[0]);
	anthill->nb_tubes ++;

		// ft_free_tab(&tab);

	return (1);
}
