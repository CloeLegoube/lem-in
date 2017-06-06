/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:46:33 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/06 21:46:38 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		available(int num_room, t_anthill *anthill, int yes)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (anthill->s_room->num_room != num_room)
			anthill->s_room = anthill->s_room->next;
		else
		{
			if (yes)
				anthill->s_room->free = 1;
			else
				anthill->s_room->free = 0;
			return (0);
		}
	}
	return (1);
}

void	ft_tabdel(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}


int		if_room_free(int num_room, t_anthill *anthill)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (anthill->s_room->num_room != num_room)
			anthill->s_room = anthill->s_room->next;
		else if (anthill->s_room->free)
			return(1);
		else
			return (0);
	}
	return (0);
}

int		ft_find_room_by_name(t_anthill *anthill, char *name)
{
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		if (!ft_strcmp(name, anthill->s_room->name))
			return (anthill->s_room->num_room);
		anthill->s_room = anthill->s_room->next;
	}
	ft_exit(6, anthill, NULL);
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

char	*ft_strstart(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (little[i] == '\0')
			return ((char *)big + i);
		if ( big[i] == little[i])
			i++;
		else
			return (NULL);
	}
	if ( big[i] == little[i])
		return ((char *)big + i);
	return (NULL);
}
