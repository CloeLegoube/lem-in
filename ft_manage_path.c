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

#include "lemin.h"

int		ft_check_if_room_exist(t_path *path, int tube)
{
	path->s_path_room = path->begin_path_room;

	while (path->s_path_room)
	{
		if (path->s_path_room->num_room == tube)
			return(0);
		path->s_path_room = path->s_path_room->next;
	}
	path->s_path_room = path->end_path_room;
	return(1);
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


void    norme(t_path *tmp3, t_path *e1, t_path *e2)
{
    if (tmp3 && tmp3 != e1)
        tmp3->previous = e1;
    e1->next = tmp3;
    if (tmp3 == e1)
        e1->next = e2;
    if (e1->previous == e1)
        e1->previous = e2;
}

void    ft_lstswap(t_path **start, t_path *e1, t_path *e2)
{
    t_path *tmp2;
    t_path *tmp3;
    tmp2 = e2->previous;
    tmp3 = e2->next;
    e2->previous = e1->previous;
    if (e1->previous)
        e1->previous->next = e2;
    else
        (*start) = e2;
    if (e1->next && e1->next != e2)
        e1->next->previous = e2;
    e2->next = e1->next;
    if (e1->next == e2)
        e2->next = e1;
    if (e2->previous == e2)
        e2->previous = e1;
    e1->previous = tmp2;
    if (tmp2)
        tmp2->next = e1;
    else
        *start = e1;
    norme(tmp3, e1, e2);
}

// num 1) tab = 0214 - len 4
// num 2) tab = 02314 - len 5
// num 3) tab = 0234 - len 4
// num 4) tab = 0314 - len 4
// num 5) tab = 034 - len 3
// 5 1 3 4 2

// int		ft_sort_path(t_anthill	*anthill, t_path	*next_path)
// {
// 	int 	i;
// 	t_path	*my_previous;
// 	t_path	*my_next;
// 	t_path	*move_path;
//
// 	i = 0;
// 	my_previous = NULL;
// 	my_next = NULL;
// 	move_path = NULL;
// 	// anthill->s_path = anthill->begin_path;
// 	// while (anthill->s_path)
// 	// {
// 	// 	i++;
// 	// 	anthill->s_path = anthill->s_path->next;
// 	// }
// 	// while (i > 0)
// 	// {
// 	if (next_path)
// 		anthill->s_path = anthill->begin_path;
// 	else
// 		anthill->s_path = next_path;
// 	while (anthill->s_path)
// 	{
// 		if (anthill->s_path->len > anthill->s_path->next->len)
// 		{
// 			ft_lstswap(&(anthill->s_path), anthill->s_path, anthill->s_path->next);
//
// 		}
// 		if (anthill->s_path)
// 			anthill->s_path = anthill->s_path->next;
// 		else
// 		{
// 			ft_sort_path(anthill, anthill->s_path->next);
// 		}
// 	}
//
// 	return (0);
// }


int		ft_sort_path(t_anthill	*anthill)
{
	int 	i;
	t_path	*my_previous;
	t_path	*my_next;
	t_path	*me;

	i = 0;
	my_previous = NULL;
	my_next = NULL;
	me = NULL;

	anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
		i++;
		anthill->s_path = anthill->s_path->next;
	}
	ft_printf("ici 5\n");

	while (i > 0)
	{
		ft_printf("*****************************************\n");

		if (!anthill->s_path)
			anthill->s_path = anthill->begin_path;
		ft_printf("*****************************************\n");
		ft_printf("*****************************************\n\n\n\n\n");

		while (anthill->s_path)
		{
			// ft_printf("ici\n");
			//
			// if (!anthill->s_path->previous)
			// 	ft_printf("-- NULL -> %d -> %d)\n", anthill->s_path->num_path, anthill->s_path->next->num_path);
			// else if (!anthill->s_path->next)
			// 	ft_printf("-- %d -> %d -> NULL)\n",anthill->s_path->previous->num_path, anthill->s_path->num_path);
			// else
			// 	ft_printf("-- %d -> %d -> %d)\n",anthill->s_path->previous->num_path, anthill->s_path->num_path, anthill->s_path->next->num_path);

			// ft_printf("LEN %d > %d\n",anthill->s_path->len, anthill->s_path->next->len );
			while (anthill->s_path && anthill->s_path->next && anthill->s_path->len > anthill->s_path->next->len)
			{
				// ft_printf("ici2\n");
				//
				//
				// if (!anthill->s_path->previous)
				// 	ft_printf("Num_room A NULL -> %d -> %d)\n\n", anthill->s_path->num_path, anthill->s_path->next->num_path);
				// else if (!anthill->s_path->next)
				// 	ft_printf("Num_room A %d -> %d -> NULL)\n\n",anthill->s_path->previous->num_path, anthill->s_path->num_path);
				// else
				// 	ft_printf("Num_room A %d -> %d -> %d)\n\n",anthill->s_path->previous->num_path, anthill->s_path->num_path, anthill->s_path->next->num_path);
				me = anthill->s_path;
				ft_printf("ME -> %d)\n\n", me->num_path);
				ft_lstswap(&(anthill->s_path), anthill->s_path, anthill->s_path->next);
				anthill->s_path = me;
				if (!anthill->s_path->previous)
					ft_printf("Num_room B NULL -> %d -> %d)\n\n", anthill->s_path->num_path, anthill->s_path->next->num_path);
				else if (!anthill->s_path->next)
					ft_printf("Num_room B %d -> %d -> NULL)\n\n",anthill->s_path->previous->num_path, anthill->s_path->num_path);
				else
					ft_printf("Num_room B %d -> %d -> %d)\n\n",anthill->s_path->previous->num_path, anthill->s_path->num_path, anthill->s_path->next->num_path);

			}
			if (anthill->s_path && anthill->s_path->next)
			{
				anthill->s_path = anthill->s_path->next;
				ft_printf("ici3\n");

			}
			else
			{
				i--;
				ft_printf("00000000000000000 i = %d\n", i);
				// anthill->s_path = NULL;
				// if (i == 0)
				// 	return (0);
				// else
					break;


			}
			if (i == 0)
				return (0);
			// ft_sort_path(anthill);
			// ft_printf("++++++++++++++\n");
		}
		ft_printf("ici i %d\n", i);

		// i--;
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

		}
		anthill->s_path = anthill->s_path->next;
	}
	return (0);
}
