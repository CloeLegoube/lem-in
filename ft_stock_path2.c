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
    path_to = find_room(target, anthill, &path_to);
    printf("Room to add %d\n", path_to->num_room);
    if (path_to)
    {
        (*(path))->end_path_room->next = path_to;
        (*(path))->end_path_room = path_to;
        printf("num_room : %d\n", (*(path))->s_path_room->next->num_room );
        if ((*(path))->end_path_room->num_room != anthill->room_end)
        {
            printf("go restart\n");
			// anthill->s_path->s_path_room = anthill->s_path->s_path_room->next;
			// ft_check_each_tube(anthill, 0);
            //ft_stock_path(anthill, anthill->begin_path);
            return(0);
			printf("After return\n");

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
        printf("copy_path %d\n", (*(copy_path))->s_path_room->num_room);
        new_room->num_room = (*(copy_path))->s_path_room->num_room;
        new_room->coordo[0] = (*(copy_path))->s_path_room->coordo[0];
        new_room->coordo[1] = (*(copy_path))->s_path_room->coordo[1];
        new_room->start = (*(copy_path))->s_path_room->start;
		new_room->end = (*(copy_path))->s_path_room->end;
		new_room->free = 1;
		printf("FREE %d\n", (*(copy_path))->s_path_room->free);
		printf("FREE %d\n", new_room->free);

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
		path->previous = (*(copy_path));
		(*(copy_path))->next = path;
		ft_add_new_room(anthill, anthill->s_tube->to, &path);
		printf("After new room si CHECK\n");


}

void		ft_check_each_tube(t_anthill *anthill, int check)
{
	t_path	*delete_path;
	int		tube_match;

	delete_path = NULL;
	tube_match = 0;
	printf("LOOP tube\n");
	anthill->s_tube = anthill->begin_tube;
    while (anthill->s_tube)
    {
		printf("Tube de %d a %d - num room : %d\n", anthill->s_tube->from, anthill->s_tube->to, anthill->s_path->s_path_room->num_room);

        if (anthill->s_tube->from == anthill->s_path->s_path_room->num_room)
        {
			tube_match++;
            if (!check)
            {
				printf("Pas check\n");
                check++;
				if (!ft_check_if_room_exist((anthill->s_path), anthill->s_tube->to))
				{
					printf(" !!! ROOM EXISTANTE tube\n");
					// Attention au free
					anthill->s_path->stop = 1;
					// anthill->s_path->previous->next = anthill->s_path->next;
					// anthill->s_path->next->previous = anthill->s_path->previous;
					// delete_path = anthill->s_path;
					// anthill->s_path = anthill->s_path->previous;
					// free(delete_path);
					// anthill->s_tube = anthill->s_tube->next;

					// break ;
					printf("BREAK 1\n");

				}
				else
				{
					ft_add_new_room(anthill, anthill->s_tube->to, &(anthill->s_path));
					printf("After new room si pas check\n");
				}

				if (anthill->s_tube)
					anthill->s_tube = anthill->s_tube->next;
            }
            else
            {
                printf("MATCH\n");
				if (ft_check_if_room_exist(anthill->s_path, anthill->s_tube->to))
				{
					printf("New PATH New ROOM copy\n");

					ft_stock_copy_path(&(anthill->s_path), anthill);
					break;
					printf("BREAK 2\n");


				}
				else
				{
					printf("!!!!! ROOM EXISTANTE copy\n");
					// anthill->s_tube = anthill->s_tube->next;
					anthill->s_path->stop = 1;

					// printf("go restart 2\n");
		            // ft_stock_path(anthill, anthill->s_path->previous);

					// printf("BREAK 3\n");


				}
				printf("BREAK 4\n");

				check = 0;

            }
			printf("BREAK 5\n");

        }
        else
            anthill->s_tube = anthill->s_tube->next;
		printf("BREAK 6\n");

    }
	if (!tube_match)
		anthill->s_path->stop = 1;
	// if (anthill->s_path->s_path_room->next->num_room != anthill->room_end)
	// 	ft_stock_path(anthill, anthill->begin_path);

}

int		test2(t_path	*path)
{
	int i;
	i = 0;
	printf("***** Structure PATH *****\n");
	printf("-----------------------------------------------\n");

		path->s_path_room = path->begin_path_room;
		while (path->s_path_room)
		{
			printf("num_room = %d\n", path->s_path_room->num_room);
			// printf("coordo[%d][%d]\n\n", path->s_path_room->coordo[0], path->s_path_room->coordo[1]);
			path->s_path_room = 	path->s_path_room->next;

		}
		// printf("tab = %s\n",path->tab);
		path = path->next;
		printf("-----------------------------------------------\n");

	return (0);
}


int		ft_stock_path(t_anthill *anthill, t_path *begin_path)
{
    t_path	*keep_path;
	int     check;
    int     i;

    keep_path = NULL;
	i = 1;
	printf("debut boucle\n");

    anthill->s_path = begin_path;
	printf("debut boucle 2\n");

	while (anthill->s_path)
	{
        printf("%d fois ********************\n", i);
		test2(anthill->s_path);
		anthill->s_path->s_path_room = anthill->s_path->end_path_room;
        // anthill->s_tube = anthill->begin_tube;
        check = 0;
		if (anthill->s_path->s_path_room->num_room != anthill->room_end)
        	ft_check_each_tube(anthill, check);


		printf("<<\n");
		printf("anthill->s_path->stop %d\n", anthill->s_path->stop);
		printf("end_path_room->num_room %d %d\n", anthill->s_path->end_path_room->num_room, anthill->room_end);
		if (!anthill->s_path->stop && anthill->s_path->end_path_room->num_room != anthill->room_end)
		{
			ft_stock_path(anthill, anthill->s_path);
		}
        if (anthill->s_path)
		{
			// printf("path num room %d>>\n", anthill->s_path->s_path_room->num_room);
			// printf("end num room %d>>\n", anthill->s_path->end_path_room->num_room);
			// if (anthill->s_path->s_path_room->num_room != 0)
			anthill->s_path = anthill->s_path->next;
			// printf("path num room %d>>\n", anthill->s_path->s_path_room->num_room);
			// printf("end num room %d>>\n", anthill->s_path->end_path_room->num_room);


		}
		printf(">>\n");

        printf("       ********************\n");
	}
    return(1);
}
