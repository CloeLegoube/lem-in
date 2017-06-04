/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/04 14:07:07 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		test(t_anthill	*anthill)
{
	int i;
	printf("nb_rooms = %d\n", anthill->nb_rooms);
	printf("nb_tubes = %d\n", anthill->nb_tubes);
	printf("room_start = %d\n", anthill->room_start);
	printf("room_end = %d\n", anthill->room_end);
	// anthill->s_lines = anthill->begin_lines;
	// printf("***** Structure LINES *****\n");
	// printf("nb fourmis = %d\n", anthill->nb_fourmis);
	// while (anthill->s_lines)
	// {
	// 	// printf("PATH -->\n");
	// 	// anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
	// 	// while (anthill->s_path->s_path_room)
	// 	// {
	// 	// 	printf("num_room = %d\n", anthill->s_path->s_path_room->num_room);
	// 	// 	printf("free ? %d\n", anthill->s_path->s_path_room->free);
	// 	// 	printf("coordo[%d][%d]\n\n", anthill->s_path->s_path_room->coordo[0], anthill->s_path->s_path_room->coordo[1]);
	// 	// 	anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
	// 	//
	// 	// }
	// 	ft_printf("%s\n", anthill->s_lines->line);
	// 	anthill->s_lines = anthill->s_lines->next;
	// }
	// anthill->s_fourmi = anthill->begin_fourmi;
	// printf("***** Structure FOURMIS ***** \n");
	// while (anthill->s_fourmi)
	// {
	// 	printf("num_fourmi = %d\n", anthill->s_fourmi->num_fourmi);
	// 	printf("num_room = %d\n\n", anthill->s_fourmi->num_room);
	// 	anthill->s_fourmi = anthill->s_fourmi->next;
	// }
	// printf("end_room = %d\n\n", anthill->end_fourmi->num_room);
	//

	// anthill->s_tube = anthill->begin_tube;
	// printf("***** Structure TUBES *****\n");
	// 	while (anthill->s_tube)
	// {
	// 	// printf("num_tube = %d\n", anthill->s_tube->num_tube);
	// 	// printf("str from %s - to %s\n", anthill->s_tube->str_from, anthill->s_tube->str_to);
	// 	printf("num tube %d) ", anthill->s_tube->num_tube);
	// 	printf("from %d - to %d \n", anthill->s_tube->from, anthill->s_tube->to);
	// 	anthill->s_tube = anthill->s_tube->next;
	// }

	// anthill->s_room = anthill->begin_room;
	// printf("***** Structure ROOMS *****\n");
	// while (anthill->s_room)
	// {
	// 	printf("num_room = %d - ", anthill->s_room->num_room);
	// 	printf("name = %s - ", anthill->s_room->name);
	// 	printf("previous = %d -  ", anthill->s_room->previous);
	// 	// printf("start ? %d - end ? %d\n", anthill->s_room->start, anthill->s_room->end);
	// 	// printf("coordo[%d][%d]\n\n", anthill->s_room->coordo[0], anthill->s_room->coordo[1]);
	// 	// printf("Free ? %d\n", anthill->s_room->free);
	// 	i = 0;
	// 	while (i < anthill->s_room->len_tube)
	// 		// printf("%d-",anthill->s_path->tab[i++]);
	// 		printf("%d-",anthill->s_room->liste_tubes[i++]);
	// 	printf(" len %d  \n", anthill->s_room->len_tube);
	// 	anthill->s_room = anthill->s_room->next;
	// }
	// anthill->s_path = anthill->begin_path;
	// printf("***** Structure PATH *****\n");
	// while (anthill->s_path)
	// {
	// 	printf("PATH -->\n");
	// 	anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
	// 	while (anthill->s_path->s_path_room)
	// 	{
	// 		printf("num_room =s %d\n", anthill->s_path->s_path_room->num_room);
	// 		printf("name = %s\n", anthill->s_path->s_path_room->name);
	// 		// printf("free ? %d\n", anthill->s_path->s_path_room->free);
	// 		// printf("coordo[%d][%d]\n\n", anthill->s_path->s_path_room->coordo[0], anthill->s_path->s_path_room->coordo[1]);
	// 		anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
	//
	// 	}
	//
	// 	anthill->s_path = anthill->s_path->next;
	// }

	anthill->s_path = anthill->begin_path;
	printf("**********\n");
	while (anthill->s_path)
	{
		// printf("PATH -->\n");
		// anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		// while (anthill->s_path->s_path_room)
		// {
		// 	printf("num_room =s %d\n", anthill->s_path->s_path_room->num_room);
		// 	printf("name = %s\n", anthill->s_path->s_path_room->name);
		// 	// printf("free ? %d\n", anthill->s_path->s_path_room->free);
		// 	// printf("coordo[%d][%d]\n\n", anthill->s_path->s_path_room->coordo[0], anthill->s_path->s_path_room->coordo[1]);
		// 	anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
		//
		// }
		i = 0;
		printf("num %d) tab = ",anthill->s_path->num_path);
		while (i < anthill->s_path->len)
			// printf("%d-",anthill->s_path->tab[i++]);
			printf("%s-",ft_name_by_room(anthill, anthill->s_path->tab[i++]));
		printf(" len %d  \n\n", anthill->s_path->len);

		anthill->s_path = anthill->s_path->next;
	}

	// anthill->match_path = anthill->begin_match_path;
	// printf("***** Structure MATCH PATH *****\n");
	// while (anthill->match_path)
	// {
	// 	printf("num %d) tab = %s - len %d\n",anthill->match_path->s_path->num_path, anthill->match_path->s_path->tab, anthill->match_path->s_path->len);
	// 	anthill->match_path = anthill->match_path->next;
	// }
	// printf("***** CALCUL *****\n");
	// printf("total = %d\n", anthill0->s_calcul->total);
	// printf("nb_path = %d\n", anthill->s_calcul->nb_path);
	// printf("left = %d\n", anthill->s_calcul->left);
	// i = -1;
	// while (++i < anthill->s_calcul->nb_path)
	// 	printf("tab[%d] = %d\n", i, anthill->s_calcul->tab[i]);
	//
	// //
	// //
	// // printf("***** KIND PATH *****\n");
	// // printf("len_short = %d\n", anthill->s_kind_path->len_short);
	// // printf("nb_short = %d\n", anthill->s_kind_path->nb_short);
	// // printf("tab short = %s)\n", anthill->s_kind_path->tab_short);
	// // printf("len_long = %d\n", anthill->s_kind_path->len_long);
	// // printf("nb_long = %d\n", anthill->s_kind_path->nb_long);
	// // printf("tab long = %s)\n", anthill->s_kind_path->tab_long);
	return (0);
}

int		ft_initialize_struct_anthill(t_anthill *anthill)
{
	anthill->nb_fourmis = 0;
	anthill->nb_rooms = 0;
	anthill->nb_tubes = 0;
	anthill->check_end = 0;
	anthill->boucle = 0;
	anthill->end_boucle = 0;
	anthill->stop = 0;
	anthill->nb_path = 0;
	anthill->room_start = -42;
	anthill->room_end = -42;
	anthill->line_start = 0;
	anthill->line_end = 0;
	anthill->begin_tube = NULL;
	anthill->end_tube = NULL;
	anthill->s_lines = NULL;
	anthill->begin_lines = NULL;
	anthill->begin_room = NULL;
	anthill->begin_fourmi = NULL;
	anthill->end_fourmi = NULL;
	anthill->begin_path = NULL;
	anthill->end_path = NULL;
	anthill->s_fourmi = NULL;
	anthill->s_tube = NULL;
	anthill->s_room = NULL;
	anthill->s_path = NULL;
	anthill->s_kind_path = NULL;
	return (1);
}

void	ft_free(t_anthill *anthill)
{
	ft_free_lines(anthill);
	ft_free_fourmis(anthill);
	ft_free_tubes(anthill);
	ft_free_rooms(anthill);
	ft_free_path(anthill);
	free(anthill);
}

int		main(void)
{
	char		*line;
	t_anthill	*anthill;

	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (0);
	ft_initialize_struct_anthill(anthill);
	line = NULL;
	if (get_next_line(0, &line) == -1)
		ft_exit(7);
	if (!ft_strdigit(line))
		ft_exit(5);
	anthill->nb_fourmis = ft_atoi(line);
	while (get_next_line(0, &line))
	{
		ft_check(anthill, &line);
		// ft_exit(anthill);
		// if(!ft_display_lines(anthill))
		// 	return (0);
	}
	ft_stock_fourmi(anthill);
	// ft_room_previous(anthill);
	ft_stock_tube_room(anthill);
	ft_add_the_previous(anthill, anthill->room_start);
	// test(anthill);
	// printf("anthill->boucle%d\n", anthill->boucle);
	// while(!if_all_room_has_previous(anthill) && !anthill->stop)
	// {
	//
	// 	ft_add_the_previous(anthill, anthill->room_start);
	// 	printf("**anthill->boucle** = %d - %d\n", anthill->boucle, anthill->end_boucle);
	//
	// 	if (anthill->boucle != anthill->end_boucle)
	// 		anthill->stop = 1;
	//
	// }
	// // test(anthill);
	//
	ft_stock_start_path(anthill);
	// //
	// // test(anthill);
	// //
	ft_stock_path(anthill, anthill->begin_path);

	ft_stock_tab(anthill);
	ft_sort_path(anthill);
	// test(anthill);
	//
	// // //
	// ft_check_correct_path(anthill);
	ft_display_lines(anthill);
	//
	// // ft_match_paths(anthill);
	// // calcul_distrib_fourmis(anthill);
	// // init_struct_kind_path(anthill);
	ft_display(anthill);
	// LLL1-713
	// LLL2-713
	// LLL1-918    LLL3-713
	// LLL2-918
	// LLL1-437    LLL3-918
	// LLL2-437
	// LLL1-end    LLL3-437
	// LLL2-end
	// LLL3-end
	// free(game);
	free(line);
	return (0);
}
