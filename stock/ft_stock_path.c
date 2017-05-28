/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/25 11:26:20 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		ft_add_new_room(t_anthill *anthill, int target, t_path **path)
{
    t_room	*path_to;

    path_to = NULL;
    path_to = find_room(target, anthill, &path_to);
    if (path_to)
    {
        (*(path))->end_path_room->next = path_to;
        (*(path))->end_path_room = path_to;
        if ((*(path))->end_path_room->num_room != anthill->room_end)
        {
            return(0);
            anthill->s_path->s_path_room = path_to;
        }
		(*(path))->stop = 1;
    }
    return (1);
}

void		ft_copy_room(t_path	**path, t_path **copy_path)
{
    t_room	*new_room;

    new_room = NULL;
    if (!(new_room = (t_room*)malloc(sizeof(t_room))))
        return ;
        new_room->num_room = (*(copy_path))->s_path_room->num_room;
        new_room->name = (*(copy_path))->s_path_room->name;
        new_room->name = ft_strnew(ft_strlen((*(copy_path))->s_path_room->name));
        new_room->name = ft_strdup((*(copy_path))->s_path_room->name);
        new_room->coordo[0] = (*(copy_path))->s_path_room->coordo[0];
        new_room->coordo[1] = (*(copy_path))->s_path_room->coordo[1];
        new_room->start = (*(copy_path))->s_path_room->start;
		new_room->end = (*(copy_path))->s_path_room->end;
		new_room->free = 1;
    if (!(*(path))->begin_path_room)
        (*(path))->begin_path_room = new_room;
    else
        (*(path))->s_path_room->next = new_room;
    (*(path))->s_path_room = new_room;
    (*(path))->end_path_room = new_room;
}
void		ft_stock_copy_path(t_path **copy_path, t_anthill *anthill)
{
    t_path	*path;
    int check;

    path = NULL;
    check = 1;
    if (!(path = (t_path*)malloc(sizeof(t_path))))
        return ;
	path->tab = NULL;
    path->num_path = 0;
    (*(copy_path))->s_path_room = (*(copy_path))->begin_path_room;
    while ((*(copy_path))->s_path_room)
    {
        if (check)
        {
            if (anthill->s_tube->from == (*(copy_path))->s_path_room->num_room)
                check  = 0;
            ft_copy_room(&path, copy_path);
        }
        (*(copy_path))->s_path_room = (*(copy_path))->s_path_room->next;
    }
    path->s_path_room = path->begin_path_room;
	path->next = (*(copy_path))->next;
	path->previous = (*(copy_path));
	(*(copy_path))->next = path;
	ft_add_new_room(anthill, anthill->s_tube->to, &path);
}
// int		ft_check_if_room_exist(t_path *path, int tube)
// {
// 	path->s_path_room = path->begin_path_room;
//
// 	while (path->s_path_room)
// 	{
// 		ft_printf("num_room %d = tube %d\n", path->s_path_room->num_room , tube);
//
// 		if (path->s_path_room->num_room == tube)
// 			return(0);
// 		path->s_path_room = path->s_path_room->next;
// 	}
// 	path->s_path_room = path->end_path_room;
// 	return(1);
// }

void		ft_check_each_tube(t_anthill *anthill, int check)
{
	int		tube_match;

	tube_match = 0;
	anthill->s_tube = anthill->begin_tube;
    while (anthill->s_tube)
    {
        ft_printf("from %d -> num_room %d\n", anthill->s_tube->from, anthill->s_path->s_path_room->num_room);

        if (anthill->s_tube->from == anthill->s_path->s_path_room->num_room)
        {
			tube_match++;
            if (!check)
            {
                check++;
				if (!ft_check_if_room_exist((anthill->s_path), anthill->s_tube->to))
                {
                    ft_printf("ici1 room %d already exist in the path\n", anthill->s_tube->to);
                    anthill->s_path->stop = 1;

                }
				else
                {
                    ft_printf("add new room \n");
                    ft_add_new_room(anthill, anthill->s_tube->to, &(anthill->s_path));

                }
				if (anthill->s_tube)
					anthill->s_tube = anthill->s_tube->next;
            }
            else
            {
				if (ft_check_if_room_exist(anthill->s_path, anthill->s_tube->to))
				{
                    ft_printf("copy the path\n");
                    // anthill->s_path->stop = 0;
					ft_stock_copy_path(&(anthill->s_path), anthill);
					break;
				}
				else
                {
                    ft_printf("ici2 room %d already exist in the path\n", anthill->s_tube->to);

                    anthill->s_path->stop = 1;

                }
				check = 0;
            }
        }
        else
            anthill->s_tube = anthill->s_tube->next;
    }
	if (!tube_match)
		anthill->s_path->stop = 1;
}

void	ft_stock_path(t_anthill *anthill, t_path *begin_path)
{
    t_path	*keep_path;
	int     check;
    int     i;

    keep_path = NULL;
	i = 1;
    anthill->s_path = begin_path;
	while (anthill->s_path)
	{
		anthill->s_path->s_path_room = anthill->s_path->end_path_room;
        check = 0;
        ft_printf("num_room %d = anthill->room_end %d\n", anthill->s_path->s_path_room->num_room, anthill->room_end);
		if (anthill->s_path->s_path_room->num_room != anthill->room_end)
        	ft_check_each_tube(anthill, check);
        ft_printf("stop %d\n", anthill->s_path->stop, anthill->room_end);
		if (!anthill->s_path->stop && anthill->s_path->end_path_room->num_room != anthill->room_end)
			ft_stock_path(anthill, anthill->s_path);
        if (anthill->s_path)
			anthill->s_path = anthill->s_path->next;
	}
}
