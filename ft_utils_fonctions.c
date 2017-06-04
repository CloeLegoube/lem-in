/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:46:33 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/03 18:12:06 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_find_room_by_name(t_anthill *anthill, char *name)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		// printf("%s = %s -> %d\n", name, anthill->s_room->name, ft_strcmp(name, anthill->s_room->name));

		if (!ft_strcmp(name, anthill->s_room->name))
			return (anthill->s_room->num_room);
		anthill->s_room = anthill->s_room->next;
	}
	ft_exit(6);
	return (0);
}

char 	*ft_name_by_room(t_anthill *anthill, int room)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (room == anthill->s_room->num_room)
			return (anthill->s_room->name);
		anthill->s_room = anthill->s_room->next;
	}
	return (NULL);
}

int		if_room_previous(int room, t_anthill *anthill)
{
	t_room *path_room;

	path_room = anthill->begin_room;
	while (path_room)
	{
		if (room == path_room->num_room)
		{
			// printf("room = %d num_room %d\n",room, path_room->num_room);
			// printf("previous = %d\n", path_room->previous);

			if (path_room->previous != 0)
			{
				return(1);

			}
		}
		path_room = path_room->next;
	}
	return(0);
}

void		add_previous(int room, int prev, int num_round, t_anthill *anthill)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (room == anthill->s_room->num_room)
		{
			anthill->s_room->previous = prev;
			anthill->s_room->round = num_round;
		}
		anthill->s_room = anthill->s_room->next;
	}
}

int		ft_check_if_room_exist(t_path *path, int tube_to, int tube_from)
{
	t_room	*tmp;
	int check;

	check = 1;
	tmp = path->s_path_room;
	path->s_path_room = path->begin_path_room;
	// ft_printf("check room 1\n");
	// ft_printf("path->begin_path_room %d\n", path->begin_path_room->num_room);

	while (path->s_path_room)
	{
		if (check)
		{
			// ft_printf("tube_from %d\n", tube_from);
			// ft_printf("free %d\n", path->s_path_room->free);
			// ft_printf("start %d\n", path->s_path_room->start);
			// ft_printf("num_room %d\n", path->s_path_room->num_room);

			if (path->s_path_room->num_room == tube_from)
				check = 0;
			// ft_printf("num_room %d = tube_to %d\n", path->s_path_room->num_room , tube_to);

			if (path->s_path_room->num_room == tube_to)
			{
				path->s_path_room = path->end_path_room;
				// ft_printf("egal\n");
				return(1);

			}
		}
		path->s_path_room = path->s_path_room->next;
	}
	// ft_printf("check room 2\n");

	path->s_path_room = tmp;
	return(0);
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


int		ft_strdigit(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] == '-')
	{
		count++;
		i++;
	}
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


// int		ft_lstlen(t_anthill *anthill)
// {
// 	int i;
//
// 	i = 0;
// 	anthill->match_path = anthill->begin_match_path;
// 	while (anthill->match_path)
// 	{
// 		i++;
// 		anthill->match_path = anthill->match_path->next;
// 	}
// 	return (i);
// }
