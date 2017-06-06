/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/06 17:04:37 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	ft_stock_tab(t_anthill *anthill)
{
	int i;
	int len;

	anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
		anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		len = 0;
		while (anthill->s_path->s_path_room)
		{
			len++;
			anthill->s_path->s_path_room = anthill->s_path->s_path_room->next;
		}
		if (!(anthill->s_path->tab = (int *)malloc(sizeof(int) * len)))
			return ;
		anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		i = 0;
		while (anthill->s_path->s_path_room)
		{
			anthill->s_path->tab[i++] = anthill->s_path->s_path_room->num_room;
			anthill->s_path->s_path_room = anthill->s_path->s_path_room->next;
		}
		anthill->s_path->len = len;
		anthill->s_path = anthill->s_path->next;
	}
}

void	ft_sort_path(t_anthill *anthill)
{
	t_path	*my_next;
	t_path	*me;

	me = anthill->begin_path;
	while (me)
	{
		my_next = me->next;
		while (my_next)
		{
			if (me->len < my_next->len)
			{
				ft_lstswap(&(anthill->begin_path), me, my_next);
				ft_sort_path(anthill);
			}
			anthill->end_path = my_next;
			my_next = my_next->next;
		}
		me = me->next;
	}
}
