/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/25 21:30:59 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_stock_tab(t_anthill *anthill)
{
	t_path	*my_next;
	t_path	*me;
	t_match_path *my_path;
	t_match_path *next_path;

	my_next = NULL;
	my_path = NULL;
	next_path = NULL;
	me = anthill->begin_path;
	while (me)
	{

		my_next = me->next;
		while (my_next)
		{
			if (ft_str_find_little(me->tab,my_next->tab, 1, 1))
			{
				ft_printf("check -> %s - %d) VS %s - %d) = %d)\n\n", me->tab, me->num_path, my_next->tab, my_next->num_path, ft_str_find_little(me->tab,my_next->tab, 1, 1));
				init_match_path(anthill, &me, &my_next);
			}
			my_next = my_next->next;
		}
		me = me->next;
	}
}

// void	ft_reorder_path(t_anthill	*anthill)
// {
// 	t_path	*my_next;
// 	t_path	*me;
//
// 	my_next = NULL;
// 	me = anthill->end_path;
// 	while (me)
// 	{
// 		my_next = anthill->begin_path;
// 		while (my_next)
// 		{
// 			if (me->len < my_next->len)
// 				ft_lstswap(&(anthill->begin_path), me, my_next);
// 			my_next = my_next->next;
// 		}
// 		anthill->end_path = me;
// 		me = me->previous;
// 	}
// }

void	ft_sort_path(t_anthill	*anthill)
{
	t_path	*my_next;
	t_path	*me;

	my_next = NULL;
	me = anthill->begin_path;
	while (me)
	{
		my_next = me->next;
		while (my_next)
		{
			if (me->len < my_next->len)
				ft_lstswap(&(anthill->begin_path), me, my_next);
			anthill->end_path = my_next;
			my_next = my_next->next;
		}
		me = me->next;
	}
	// ft_reorder_path(anthill);
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
		// printf("TEST %d",anthill->s_path->len );
		if (anthill->s_path->end_path_room->num_room != anthill->room_end)
		{
			// printf("TEST num_room %d",anthill->s_path->end_path_room->num_room );

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
		{
			anthill->s_path->num_path = i++;
			anthill->end_path = anthill->s_path;
		}
		anthill->s_path = anthill->s_path->next;
	}
	return (0);
}

void		ft_stock_tab(t_anthill *anthill)
{
    int i;

    i = 0;
    anthill->s_path = anthill->begin_path;
    while (anthill->s_path)
	{
		anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		while (anthill->s_path->s_path_room)
		{
			i++;
			anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
		}
        if (!(anthill->s_path->tab = (char *)malloc(sizeof(char) * (i + 1))))
            return ;
        anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
        i = 0;
        while (anthill->s_path->s_path_room)
        {
            anthill->s_path->tab[i++]= anthill->s_path->s_path_room->num_room + 48;
            anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
        }
        anthill->s_path->tab[i]= '\0';
        anthill->s_path->len = ft_strlen(anthill->s_path->tab);
        anthill->s_path = anthill->s_path->next;
	}
}
