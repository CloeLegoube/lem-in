/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_path2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/03 14:13:19 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

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

int     his_previous(int room, t_anthill *anthill)
{
    anthill->s_room = anthill->begin_room;
    while (anthill->s_room)
    {
        // ft_printf("anthill->s_room->num_room %d - room %d\n", anthill->s_room->num_room, room);

        if (anthill->s_room->num_room == room)
            return (anthill->s_room->previous);
        anthill->s_room = anthill->s_room->next;
    }
    return(0);
}


t_room	*find_room2(int target, t_anthill *anthill, t_room **room)
{
    // if (target == anthill->room_end)
    //     previous = 0;
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
            (*room)->name = anthill->s_room->name;
            (*room)->name = ft_strnew(ft_strlen(anthill->s_room->name));
            (*room)->name = ft_strdup(anthill->s_room->name);
            (*room)->coordo[0] = anthill->s_room->coordo[0];
            (*room)->coordo[1] = anthill->s_room->coordo[1];
            (*room)->start = anthill->s_room->start;
            (*room)->end = anthill->s_room->end;
            (*room)->free = 1;
            (*room)->previous = anthill->s_room->previous;
            // add_previous((*room)->num_room, previous, anthill);
            (*room)->next = NULL;
            return (*room);
        }
    }
    return (*room);
}

int		ft_add_new_room(t_anthill *anthill, int room, t_path **path)
{
    t_room	*path_to;

    path_to = NULL;
    path_to = find_room2(room, anthill, &path_to);
    if (path_to)
    {
        path_to->next = (*(path))->begin_path_room;
        (*(path))->begin_path_room = path_to;
		(*(path))->stop = 0;
    }
    return (1);
}

int     nb_end(t_anthill *anthill)
{
    int count;

    count = 0;
    // ATTENTION AUX TUBES IDENTIQUES
    anthill->s_tube = anthill->begin_tube;
	// printf("***** Structure TUBES *****\n");
	while (anthill->s_tube)
	{
		if (anthill->s_tube->to == anthill->room_end)
            count++;
		anthill->s_tube = anthill->s_tube->next;
	}
    return (count);
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

// t_path		*ft_stock_copy_path(t_path **copy_path, t_anthill *anthill)
// {
//     t_path	*path;
//     t_room	*tmp;
//     int check;
//
//     path = NULL;
//     check = 1;
//     // ft_printf("stay here 1\n");
//     tmp = (*(copy_path))->s_path_room;
//
//     if (!(path = (t_path*)malloc(sizeof(t_path))))
//         return (NULL);
// 	path->tab = NULL;
//     path->num_path = 0;
// 	path->stop = 0;
//     path->begin_path_room = NULL;
//     (*(copy_path))->s_path_room = (*(copy_path))->begin_path_room;
//
//     while ((*(copy_path))->s_path_room)
//     {
//         // ft_printf("stay here 2\n");
//
//         if (check)
//         {
//             // ft_printf("stay here 3\n");
//             // ft_printf("stay anthill->s_tube->from %d\n", anthill->s_tube->from);
//             // ft_printf("stay num_room %d\n", (*(copy_path))->s_path_room->num_room);
//
//             if (anthill->s_tube && anthill->s_tube->from == (*(copy_path))->s_path_room->num_room)
//                 check  = 0;
//             // ft_printf("stay here 5\n");
//             ft_copy_room(&path, copy_path);
//             // ft_printf("stay here 6\n");
//
//         }
//         (*(copy_path))->s_path_room = (*(copy_path))->s_path_room->next;
//     }
//     // ft_printf("stay here 4\n");
//
//     path->s_path_room = path->begin_path_room;
// 	path->next = (*(copy_path))->next;
// 	path->previous = (*(copy_path));
// 	(*(copy_path))->next = path;
// 	ft_add_new_room(anthill, anthill->s_tube, &path);
//     (*(copy_path))->s_path_room = tmp;
//     return(path);
// }

void		delete_previous(int start, t_anthill *anthill)
{
    anthill->s_room = anthill->begin_room;
    while (anthill->s_room)
	{
        if (anthill->s_room->previous == start)
        {
            start = anthill->s_room->previous;
            anthill->s_room->previous = 0;
            anthill->s_room = anthill->begin_room;
        }
        else
		    anthill->s_room = anthill->s_room->next;
	}
}

int		if_path_find_room_end(int start, t_anthill *anthill)
{
    int nb_tubes;

    nb_tubes = 0;
    while (start != anthill->room_end || nb_tubes != anthill->nb_tubes * 2)
    {
        nb_tubes = 0;
        anthill->s_tube = anthill->begin_tube;
        while (anthill->s_tube)
        {
            if (anthill->s_tube->from == start &&
                (anthill->s_tube->to == anthill->room_end || !if_room_previous(anthill->s_tube->to, anthill)))
            {
                if (!if_path_find_room_end(anthill->s_tube->to, anthill))
                    delete_previous(anthill->s_tube->to, anthill);
                else
                {
                    delete_previous(anthill->s_tube->to, anthill);
                    add_previous(anthill->s_tube->to, anthill->s_tube->from, anthill);
                    start = anthill->s_tube->to;
                    anthill->s_tube = NULL;
                }
            }
            else
            {
                anthill->s_tube = anthill->s_tube->next;
                nb_tubes++;
            }
        }
    }
    if (start == anthill->room_end)
        return (1);
    return (0);
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
                // if (!if_path_find_room_end(anthill->s_tube->to, anthill))
                //     delete_previous(anthill->s_tube->to, anthill);
                // else
                // {
                //     delete_previous(anthill->s_tube->to, anthill);
                add_previous(anthill->s_tube->to, anthill->s_tube->from, anthill);

                    // ft_add_new_room(anthill, anthill->s_tube, &(my_path));
                    // anthill->s_path->s_path_room = anthill->s_path->end_path_room;
                    // anthill->s_tube = NULL;
                    // printf("%d//) my_path->s_path_room->num_room = %d\n", my_path->s_path_room->num_room, my_path->end_path_room->num_room);
                // }
                // my_path->s_path_room = my_path->end_path_room;
                // anthill->s_tube = anthill->begin_tube;
                // my_path->s_path_room = my_path->s_path_room->next;
        }
        else
        {
            nb_tubes++;

        }
    }
    // ft_printf("-------------------------- \nnb_tubes %d = anthill->nb_tubes %d ?\n\n", nb_tubes,anthill->nb_tubes * 2 );
    if (nb_tubes == anthill->nb_tubes * 2)
        my_path->stop = 1;
}

int if_all_room_has_previous(t_anthill *anthill)
{
    int nb_previous;

    nb_previous = 0;
    anthill->s_room = anthill->begin_room;
    printf("***** if_all_room_has_previous ROOMS *****\n");
    while (anthill->s_room)
    {
    	if (anthill->s_room->previous != 0)
            nb_previous++;
    	// printf("start ? %d - end ? %d\n", anthill->s_room->start, anthill->s_room->end);
    	// printf("coordo[%d][%d]\n\n", anthill->s_room->coordo[0], anthill->s_room->coordo[1]);
    	// printf("Free ? %d\n", anthill->s_room->free);
    	anthill->s_room = anthill->s_room->next;
    }
    printf("nb_previous %d =  anthill->nb_rooms %d\n",nb_previous,    anthill->nb_rooms);
    anthill->s_room = anthill->begin_room;
    printf("***** Structure ROOMS *****\n");
    while (anthill->s_room)
    {
        printf("num_room = %d - ", anthill->s_room->num_room);
        printf("name = %s - ", anthill->s_room->name);
        printf("previous = %d\n", anthill->s_room->previous);
        // printf("start ? %d - end ? %d\n", anthill->s_room->start, anthill->s_room->end);
        // printf("coordo[%d][%d]\n\n", anthill->s_room->coordo[0], anthill->s_room->coordo[1]);
        // printf("Free ? %d\n", anthill->s_room->free);
        anthill->s_room = anthill->s_room->next;
    }
    if (nb_previous == anthill->nb_rooms - 1)
        return(1);
    return(0);
}

int		ft_add_the_previous(t_anthill *anthill, int start)
{
    int nb_tubes;
    int count;
    int result;
    t_tube  *tmp;

    nb_tubes = 1;
    result = 0;
    count = 1;
	anthill->s_tube = anthill->begin_tube;
    // printf("anthill->nb_tubes %d-%d\n", anthill->nb_tubes, nb_tubes);

    while (anthill->s_tube || nb_tubes < anthill->nb_tubes)
    {
        // printf("tube %d-%d room_end %d start %d\n", anthill->s_tube->from, anthill->s_tube->to,anthill->room_end, start );
        // printf("num_rooms %d-%d\n", anthill->s_tube->from, anthill->s_tube->to);
        if (anthill->s_tube && (anthill->s_tube->from == start || anthill->s_tube->to == start))
        {
            if (anthill->s_tube->from == start &&
                !if_room_previous(anthill->s_tube->to, anthill))
            {
                    printf("Add previous %d to %d\n",anthill->s_tube->from,  anthill->s_tube->to);
                    anthill->check_end++;

                    add_previous(anthill->s_tube->to, anthill->s_tube->from, anthill);
                    // test(anthill);

                    // add_previous(anthill->s_tube->from, anthill->s_tube->to, anthill);
                    // start = anthill->s_tube->to;
                    // anthill->s_tube = anthill->begin_tube;
                    // nb_tubes = 0;
                    tmp = anthill->s_tube;
                    if (anthill->s_tube->to != anthill->room_end)
                    {
                        anthill->boucle++;
                        if (!ft_add_the_previous(anthill, anthill->s_tube->to))
                        {

                            anthill->s_tube = tmp;
                            if (!anthill->check_end)
                            {
                                printf("DELETE %d\n", anthill->s_tube->to);
                                delete_previous(anthill->s_tube->to, anthill);
                            }
                            else
                                printf("KEEP %d\n", anthill->s_tube->to);
                            result = 1;
                            anthill->check_end--;
                        }

                        printf("**boucle** = %d\n", anthill->boucle);

                    }

                    anthill->s_tube = tmp;

            }
            if (anthill->s_tube->to == start
                && !if_room_previous(anthill->s_tube->from, anthill))
            {
                    printf("pas de previous\n");
                    anthill->check_end++;

                    add_previous(anthill->s_tube->from, anthill->s_tube->to, anthill);
                    // add_previous(anthill->s_tube->to, anthill->s_tube->from, anthill);
                    // start = anthill->s_tube->from;
                    // anthill->s_tube = anthill->begin_tube;
                    // nb_tubes = 0;
                    tmp = anthill->s_tube;
                    if (anthill->s_tube->from != anthill->room_end)
                    {
                        anthill->boucle++;
                        if (!ft_add_the_previous(anthill, anthill->s_tube->from))
                        {
                            anthill->s_tube = tmp;
                            if (!anthill->check_end)
                            {
                                printf("DELETE %d\n", anthill->s_tube->from);
                                delete_previous(anthill->s_tube->from, anthill);
                            }
                            else
                                printf("KEEP %d\n", anthill->s_tube->from);

                            result = 1;
                            anthill->check_end--;
                        }
                        printf("**boucle** = %d\n", anthill->boucle);

                    }

                    anthill->s_tube = tmp;

            }
        }
        else
            nb_tubes++;
            if(anthill->s_tube)
                anthill->s_tube = anthill->s_tube->next;

        // printf("anthill->nb_tubes %d-%d\n", anthill->nb_tubes, nb_tubes);

    }
    printf("anthill->check_end %d\n",anthill->check_end);
    if (nb_tubes == anthill->nb_tubes)
    {
        anthill->end_boucle++;
    }
    if ((nb_tubes == anthill->nb_tubes && !anthill->check_end) || result)
        return(0);
    if (nb_tubes == anthill->nb_tubes)
    {
        return(1);
    }
    printf("anthill->end_boucle = %d\n", anthill->end_boucle);
    return(1);
}

    // void	ft_stock_path(t_anthill *anthill, t_path *begin_path)
    // {
    //     t_path	*my_path;
    //     int     i;
    //
    //     my_path = NULL;
    // 	i = 0;
    //     my_path = begin_path;
    //     my_path->s_path_room = my_path->end_path_room;
    //     	while (my_path)
    //     	{
    //
    //             if ((my_path->stop == 0 && my_path->end_path_room->num_room != anthill->room_end))
    //             {
    //                 my_path->s_path_room = my_path->end_path_room;
    //
    //                 ft_printf("2) num_room %d = anthill->room_end %d\n", my_path->end_path_room->num_room, anthill->room_end);
    //
    //                 if (my_path->s_path_room->num_room != anthill->room_end )
    //                 {
    //                     ft_check_each_tube(anthill, my_path);
    //                     ft_printf("3) num_room %d = anthill->room_end %d - stop %d\n", my_path->end_path_room->num_room, anthill->room_end, my_path->stop);
    //                 }
    //                 if (my_path->stop ||  my_path->end_path_room->num_room == anthill->room_end)
    //                     i++;
    //
    //             }
    //
    //             if (my_path)
    //     			my_path = my_path->next;
    //         }
    //         ft_printf("i %d = nb_path %d\n", i, anthill->nb_path);
    //
    //         // if (anthill->s_path)
    //         //     anthill->s_path = anthill->s_path->next;
    //
    //
    //
    // }

void	ft_stock_path(t_anthill *anthill, t_path *begin_path)
{
    // t_path	*my_path;
    int     room;
    // int     count;
    t_room *boucle_room;

    anthill->s_path = begin_path;
	printf("***** Stock path ****\n");
	while (anthill->s_path)
	{
        // anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		printf("***** Path %d ****\n", anthill->s_path->begin_path_room->num_room);

        room = anthill->s_path->begin_path_room->previous;
        // printf("room %d\n", room);
        boucle_room = anthill->begin_room;
        // count = 0;
        while (boucle_room)
        {
            printf("room %d - num_room %d\n", room, boucle_room->num_room);

            if (room == boucle_room->num_room)
            {
                printf("num_room %d - previous %d\n", boucle_room->num_room, boucle_room->previous);

				// if (boucle_room->previous ==  anthill->room_start)
				// {
				// 	ft_add_new_room(anthill, boucle_room->num_room, &(anthill->s_path));
				// 	ft_add_new_room(anthill, anthill->s_path->begin_path_room->previous, &(anthill->s_path));
				// }
				// else
					ft_add_new_room(anthill, boucle_room->num_room, &(anthill->s_path));

                break;
            }
            else
            {
                boucle_room = boucle_room->next;
                // count++;
            }
        }
        // printf("count %d - nb_rooms %d\n", count, anthill->nb_rooms);
		printf("anthill->s_path->begin_path_room->num_room %d - anthill->room_start %d\n", anthill->s_path->begin_path_room->num_room, anthill->room_start);

        if (anthill->s_path->begin_path_room->num_room == anthill->room_start)
		{
			printf("***** Change path ****\n");

			anthill->s_path = anthill->s_path->next;

		}

	}
}

// void	ft_stock_path(t_anthill *anthill, t_path *begin_path)
// {
//     t_path	*my_path;
//     int     i;
//
//     my_path = NULL;
// 	i = 0;
//     anthill->s_path = begin_path;
//     anthill->s_path->s_path_room = anthill->s_path->end_path_room;
//     printf("anthill->nb_rooms = %d\n", anthill->nb_rooms);
//
//     ft_printf("0) num_room %d = stop %d\n", anthill->s_path->end_path_room->num_room, anthill->s_path->stop);
//
//     while (i != anthill->nb_path)
//     {
//         ft_printf("1) num_room %d = stop %d\n", anthill->s_path->end_path_room->num_room, anthill->s_path->stop);
//
//         // anthill->s_path = begin_path;
//         ft_printf("boucle \n");
//         my_path = begin_path;
//     	while (my_path)
//     	{
//
//             if ((my_path->stop == 0 && my_path->end_path_room->num_room != anthill->room_end))
//             {
//                 my_path->s_path_room = my_path->end_path_room;
//
//                 ft_printf("2) num_room %d = anthill->room_end %d\n", my_path->end_path_room->num_room, anthill->room_end);
//
//                 if (my_path->s_path_room->num_room != anthill->room_end )
//                 {
//                     ft_check_each_tube(anthill, my_path);
//                     ft_printf("3) num_room %d = anthill->room_end %d - stop %d\n", my_path->end_path_room->num_room, anthill->room_end, my_path->stop);
//                 }
//                 if (my_path->stop ||  my_path->end_path_room->num_room == anthill->room_end)
//                     i++;
//
//             }
//
//             if (my_path)
//     			my_path = my_path->next;
//         }
//         ft_printf("i %d = nb_path %d\n", i, anthill->nb_path);
//
//         // if (anthill->s_path)
//         //     anthill->s_path = anthill->s_path->next;
// 	}
//
//
// }
