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
		printf("num_room %d = target %d\n", path->s_path_room->num_room, tube);

		if (path->s_path_room->num_room == tube)
			return(0);
		path->s_path_room = path->s_path_room->next;
	}
	path->s_path_room = path->end_path_room;
	return(1);
}

int		ft_add_new_room(t_anthill *anthill, int target, t_path **path)
{
    t_room	*path_to;

    path_to = NULL;
    printf("Pas check\n");
    path_to = find_room(target, anthill, &path_to);
    printf("Room to add %d\n", path_to->num_room);
    if (path_to)
    {
        (*(path))->end_path_room->next = path_to;
        (*(path))->end_path_room = path_to;
        printf("num_room : %d\n", (*(path))->s_path_room->next->num_room );
        if ((*(path))->s_path_room->next->num_room != anthill->room_end)
        {
            printf("go restart\n");
            ft_stock_path(anthill);
            return(0);
            anthill->s_path->s_path_room = path_to;
        }
    }
    return (1);
}

void		ft_copy_room(t_path	**path, t_path **copy_path)
{
    t_room	*new_room;

    new_room = NULL;
    if (!(new_room = (t_room*)malloc(sizeof(t_room))))
        return ;
        printf("copy_path %d\n", (*(copy_path))->s_path_room->num_room);
        new_room->num_room = (*(copy_path))->s_path_room->num_room;
        new_room->coordo[0] = (*(copy_path))->s_path_room->coordo[0];
        new_room->coordo[1] = (*(copy_path))->s_path_room->coordo[1];
        new_room->start = (*(copy_path))->s_path_room->start;
        new_room->end = (*(copy_path))->s_path_room->end;
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
	if (!ft_check_if_room_exist(path, anthill->s_tube->to))
	{
		printf("ROOM existante copy\n");
		free(path);
	}
	else
	{
		(*(copy_path))->next = path;
		ft_add_new_room(anthill, anthill->s_tube->to, &path);

	}
}

void		ft_check_each_tube(t_anthill *anthill, int check)
{
    while (anthill->s_tube)
    {
        if (anthill->s_tube->from == anthill->s_path->s_path_room->num_room)
        {
			printf("Tube de %d a %d - num room : %d\n", anthill->s_tube->from, anthill->s_tube->to, anthill->s_path->s_path_room->num_room);

            if (!check)
            {
                check++;
				if (!ft_check_if_room_exist((anthill->s_path), anthill->s_tube->to))
				{
					printf("ROOM existante tube\n");
					// Attention au free
					// anthill->s_path->s_path_room = anthill->s_path->next->s_path_room;
					// anthill->s_path->begin_path_room = anthill->s_path->next->begin_path_room;
					// anthill->s_path->end_path_room = anthill->s_path->next->end_path_room;
					anthill->s_path = anthill->s_path->next;
					break ;
				}
				else
                	ft_add_new_room(anthill, anthill->s_tube->to, &(anthill->s_path));
                anthill->s_tube = anthill->s_tube->next;
            }
            else
            {
                printf("MATCH\n");
                ft_stock_copy_path(&(anthill->s_path), anthill);
                break;
                check = 0;
            }
        }
        else
            anthill->s_tube = anthill->s_tube->next;
    }
}

int		ft_stock_path(t_anthill *anthill)
{
    t_path	*keep_path;
    int     check;

    keep_path = NULL;
    anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
        printf("x fois ********************\n");
		anthill->s_path->s_path_room = anthill->s_path->end_path_room;
        anthill->s_tube = anthill->begin_tube;
        check = 0;
		if (anthill->s_path->s_path_room->num_room != anthill->room_end)
        	ft_check_each_tube(anthill, check);
        printf("<<\n");
        if (anthill->s_path)
            anthill->s_path = anthill->s_path->next;
        printf(">>\n");
        printf("       ********************\n");
	}
    return(1);
}
