/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/09 17:21:30 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

// int		*ft_intdup(int *s, int len)
// {
// 	int		i;
// 	int		*dest;
//
// 	i = 0;
// 	if (!(dest = (int*)malloc(sizeof(int) * len)))
// 		return (NULL);
// 	while (i < len)
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }

void		ft_stock_tab(t_anthill *anthill)
{
	int i;
    int len;

	i = 0;
    anthill->s_path = anthill->begin_path;
    while (anthill->s_path)
	{
		anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		len = 0;
		while (anthill->s_path->s_path_room)
		{
			len++;
			anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
		}
        if (!(anthill->s_path->tab = (int *)malloc(sizeof(int) * len)))
            return ;
        anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
        i = 0;
        while (anthill->s_path->s_path_room)
        {
            anthill->s_path->tab[i++]= anthill->s_path->s_path_room->num_room;
            anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
        }
        anthill->s_path->len = len;
        anthill->s_path = anthill->s_path->next;
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
	me = anthill->begin_path;
	while (me)
	{
		my_next = me->next;
		while (my_next)
		{
			printf("me->len %d) my_next %d \n",me->len, my_next->len);
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
