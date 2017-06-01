/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/30 19:36:49 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		ft_add_new_room(t_anthill *anthill, t_tube *tube, t_path **path)
{
    t_room	*path_to;

    path_to = NULL;
    path_to = find_room(tube->to, anthill, &path_to, tube->from);
    if (path_to)
    {
        (*(path))->end_path_room->next = path_to;
        (*(path))->end_path_room = path_to;
        if ((*(path))->end_path_room->num_room != anthill->room_end)
        {
            return(0);
            anthill->s_path->s_path_room = path_to;
        }
		(*(path))->stop = 0;
    }
    return (1);
}

void		ft_copy_room(t_path	**path, t_path **copy_path)
{
    t_room	*new_room;

    new_room = NULL;
    // ft_printf("stay here 7\n");
    if (!(new_room = (t_room*)malloc(sizeof(t_room))))
        return ;
        // ft_printf("stay here 8\n");
        new_room->num_room = (*(copy_path))->s_path_room->num_room;
        new_room->name = (*(copy_path))->s_path_room->name;
        new_room->name = ft_strnew(ft_strlen((*(copy_path))->s_path_room->name));
        // ft_printf("stay here 9\n");

        new_room->name = ft_strdup((*(copy_path))->s_path_room->name);
        new_room->coordo[0] = (*(copy_path))->s_path_room->coordo[0];
        new_room->coordo[1] = (*(copy_path))->s_path_room->coordo[1];
        new_room->start = (*(copy_path))->s_path_room->start;
		new_room->end = (*(copy_path))->s_path_room->end;
		new_room->free = 1;
        // ft_printf("stay here 10\n");

    if (!(*(path))->begin_path_room)
    {
        // ft_printf("stay here 11\n");

        (*(path))->begin_path_room = new_room;

    }
    else
    {
        // ft_printf("stay here 12\n");
        (*(path))->s_path_room->next = new_room;
        // ft_printf("stay here 13\n");

    }

    (*(path))->s_path_room = new_room;
    (*(path))->end_path_room = new_room;
}



t_path		*ft_stock_copy_path(t_path **copy_path, t_anthill *anthill)
{
    t_path	*path;
    t_room	*tmp;
    int check;

    path = NULL;
    check = 1;
    // ft_printf("stay here 1\n");
    tmp = (*(copy_path))->s_path_room;

    if (!(path = (t_path*)malloc(sizeof(t_path))))
        return (NULL);
	path->tab = NULL;
    path->num_path = 0;
	path->stop = 0;
    path->begin_path_room = NULL;
    (*(copy_path))->s_path_room = (*(copy_path))->begin_path_room;

    while ((*(copy_path))->s_path_room)
    {
        // ft_printf("stay here 2\n");

        if (check)
        {
            // ft_printf("stay here 3\n");
            // ft_printf("stay anthill->s_tube->from %d\n", anthill->s_tube->from);
            // ft_printf("stay num_room %d\n", (*(copy_path))->s_path_room->num_room);

            if (anthill->s_tube && anthill->s_tube->from == (*(copy_path))->s_path_room->num_room)
                check  = 0;
            // ft_printf("stay here 5\n");
            ft_copy_room(&path, copy_path);
            // ft_printf("stay here 6\n");

        }
        (*(copy_path))->s_path_room = (*(copy_path))->s_path_room->next;
    }
    // ft_printf("stay here 4\n");

    path->s_path_room = path->begin_path_room;
	path->next = (*(copy_path))->next;
	path->previous = (*(copy_path));
	(*(copy_path))->next = path;
	ft_add_new_room(anthill, anthill->s_tube, &path);
    (*(copy_path))->s_path_room = tmp;
    return(path);
}

void		ft_check_each_tube(t_anthill *anthill, t_path *my_path)
{
    int nb_tubes;

    nb_tubes = 0;
	anthill->s_tube = anthill->begin_tube;
    while (anthill->s_tube)
    {
        // ft_printf("************************************\nAVANT from %d -> num_room %d\n", anthill->s_tube->from, my_path->s_path_room->num_room);
        // ft_printf("AVANT my_path->s_path_room->num_room %d\n", my_path->s_path_room->num_room);

        if (anthill->s_tube->from == my_path->s_path_room->num_room &&
            ( anthill->s_tube->to == anthill->room_end || !if_room_previous(anthill->s_tube->to, anthill)))
        {
                ft_add_new_room(anthill, anthill->s_tube, &(my_path));
                anthill->s_path->s_path_room = anthill->s_path->end_path_room;
                anthill->s_tube = NULL;
                printf("%d//) my_path->s_path_room->num_room = %d\n", my_path->s_path_room->num_room, my_path->end_path_room->num_room);

                // my_path->s_path_room = my_path->end_path_room;
                // anthill->s_tube = anthill->begin_tube;
                // my_path->s_path_room = my_path->s_path_room->next;

        }
        else
        {
            anthill->s_tube = anthill->s_tube->next;
            nb_tubes++;

        }
    }
    // ft_printf("-------------------------- \nnb_tubes %d = anthill->nb_tubes %d ?\n\n", nb_tubes,anthill->nb_tubes * 2 );
    if (nb_tubes == anthill->nb_tubes * 2)
        my_path->stop = 1;
}

int     ft_check_previous(t_anthill *anthill)
{
    int count;

    count = 0;
    anthill->s_room = anthill->begin_room;
    // printf("***** Structure ROOMS *****\n");

    while (anthill->s_room)
    {
        if (anthill->s_room->previous)
            count++;
        printf("%d) previous = %d\n", anthill->s_room->num_room, anthill->s_room->previous);
        // printf("start ? %d - end ? %d\n", anthill->s_room->start, anthill->s_room->end);
        // printf("coordo[%d][%d]\n\n", anthill->s_room->coordo[0], anthill->s_room->coordo[1]);
        // printf("Free ? %d\n", anthill->s_room->free);
        anthill->s_room = anthill->s_room->next;
    }
    printf("count= %d\n", count);

    if (count != anthill->nb_rooms)
        return(1);
    return(0);
}

void	ft_stock_path(t_anthill *anthill, t_path *begin_path)
{
    t_path	*my_path;
    int     i;

    my_path = NULL;
	i = 0;
    anthill->s_path = begin_path;
    anthill->s_path->s_path_room = anthill->s_path->end_path_room;
    printf("anthill->nb_rooms = %d\n", anthill->nb_rooms);

    ft_printf("0) num_room %d = stop %d\n", anthill->s_path->end_path_room->num_room, anthill->s_path->stop);

    while (i != anthill->nb_path)
    {
        ft_printf("1) num_room %d = stop %d\n", anthill->s_path->end_path_room->num_room, anthill->s_path->stop);

        // anthill->s_path = begin_path;
        ft_printf("boucle \n");
        my_path = begin_path;
    	while (my_path)
    	{

            if ((my_path->stop == 0 && my_path->end_path_room->num_room != anthill->room_end))
            {
                my_path->s_path_room = my_path->end_path_room;

                ft_printf("2) num_room %d = anthill->room_end %d\n", my_path->end_path_room->num_room, anthill->room_end);

                if (my_path->s_path_room->num_room != anthill->room_end )
                {
                    ft_check_each_tube(anthill, my_path);
                    ft_printf("3) num_room %d = anthill->room_end %d - stop %d\n", my_path->end_path_room->num_room, anthill->room_end, my_path->stop);
                }
                if (my_path->stop ||  my_path->end_path_room->num_room == anthill->room_end)
                    i++;

            }

            if (my_path)
    			my_path = my_path->next;
        }
        ft_printf("i %d = nb_path %d\n", i, anthill->nb_path);

        // if (anthill->s_path)
        //     anthill->s_path = anthill->s_path->next;
	}


}
