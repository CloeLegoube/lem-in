/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/30 18:45:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_room	*find_room(int target, t_anthill *anthill, t_room **room)
{
    anthill->s_room = anthill->begin_room;
    while (anthill->s_room)
    {
        if (anthill->s_room->num_room != target)
            anthill->s_room = anthill->s_room->next;
        else
        {
            if (!(*room = (t_room*)malloc(sizeof(t_room))))
                return (0);
            (*room)->num_room = anthill->s_room->num_room;
			// ft_printf("anthill->s_room->num_room %d", anthill->s_room->num_room);
            (*room)->name = anthill->s_room->name;
            (*room)->name = ft_strnew(ft_strlen(anthill->s_room->name));
            (*room)->name = ft_strdup(anthill->s_room->name);
            (*room)->coordo[0] = anthill->s_room->coordo[0];
            (*room)->coordo[1] = anthill->s_room->coordo[1];
            (*room)->start = anthill->s_room->start;
            (*room)->end = anthill->s_room->end;
            (*room)->free = 1;
            (*room)->next = NULL;
            return (*room);
        }
    }
    return (*room);
}

static int	init_struct_path(t_path	**path, t_room **path_from, t_room **path_to)
{
	if (!(*path = (t_path*)malloc(sizeof(t_path))))
		return (0);
		(*path)->tab = NULL;
        (*path)->stop = 0;
		(*path)->len = 0;
		(*path)->shorter = 0;
		(*path)->longer = 0;
        (*path)->len = 0;
        (*path)->num_path = 0;
		(*path)->begin_path_room = NULL;
        (*path)->s_path_room = *path_from;
        if (*path_to)
            (*path)->s_path_room->next = *path_to;
        if (!(*path)->begin_path_room)
            (*path)->begin_path_room = *path_from;
        if (*path_to)
            (*path)->end_path_room = *path_to;
		(*path)->next = NULL;
		// ft_printf("(*path)->begin_path_room %d\n", (*path)->begin_path_room->num_room);

	return (0);
}

int		ft_stock_start_path(t_anthill *anthill)
{
    t_room	*path_from;
    t_room	*path_to;
    t_path	*path;

    path_from = NULL;
    path_to = NULL;
    path = NULL;
    anthill->s_tube = anthill->begin_tube;
	while (anthill->s_tube)
	{
        if (anthill->s_tube->from == anthill->room_start)
        {
            path_from = find_room(anthill->s_tube->from, anthill, &path_from);
            path_to = find_room(anthill->s_tube->to, anthill, &path_to);
            init_struct_path(&path, &path_from, &path_to);
            if (!anthill->begin_path)
            {
                anthill->begin_path = path;
                path->previous = NULL;
            }
            else
            {
                anthill->s_path->next = path;
                path->previous = anthill->s_path;
            }
			anthill->s_path = path;
            anthill->end_path = path;
        }
        anthill->s_tube = anthill->s_tube->next;
	}
	return (1);
}
