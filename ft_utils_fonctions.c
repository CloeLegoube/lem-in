/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:46:33 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/25 14:18:14 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_str_find_little(char *s1, char *s2, size_t from, size_t to)
{
	size_t	i;
	size_t	j;

	i = from;
	while (s1[i] && i < (ft_strlen(s1) - to))
	{
		j = from;
		while(s2[j] && j < (ft_strlen(s2) - to))
		{
			if(s1[i] != s2[j])
				j++;
			else
				return (0);
		}
		i++;
	}
	return(1);
}

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
