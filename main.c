/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/25 20:00:12 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		test(t_anthill	*anthill)
{
	int i;
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
	// 	printf("num_tube = %d\n", anthill->s_tube->num_tube);
	// 	printf("from %d - to %d\n\n", anthill->s_tube->from, anthill->s_tube->to);
	// 	anthill->s_tube = anthill->s_tube->next;
	// }
	//
	// anthill->s_room = anthill->begin_room;
	// printf("***** Structure ROOMS *****\n");
	// while (anthill->s_room)
	// {
	// 	printf("num_room = %d\n", anthill->s_room->num_room);
	// 	printf("start ? %d - end ? %d\n", anthill->s_room->start, anthill->s_room->end);
	// 	printf("coordo[%d][%d]\n\n", anthill->s_room->coordo[0], anthill->s_room->coordo[1]);
	// 	printf("Free ? %d\n", anthill->s_room->free);
	// 	anthill->s_room = anthill->s_room->next;
	// }
	i = 0;
	anthill->s_path = anthill->begin_path;
	printf("***** Structure PATH *****\n");
	while (anthill->s_path)
	{
		// printf("PATH -->\n");
		// anthill->s_path->s_path_room = anthill->s_path->begin_path_room;
		// while (anthill->s_path->s_path_room)
		// {
		// 	printf("num_room = %d\n", anthill->s_path->s_path_room->num_room);
		// 	printf("free ? %d\n", anthill->s_path->s_path_room->free);
		// 	printf("coordo[%d][%d]\n\n", anthill->s_path->s_path_room->coordo[0], anthill->s_path->s_path_room->coordo[1]);
		// 	anthill->s_path->s_path_room = 	anthill->s_path->s_path_room->next;
		//
		// }
		printf("num %d) tab = %s - len %d\n",anthill->s_path->num_path, anthill->s_path->tab, anthill->s_path->len);
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
	// printf("total = %d\n", anthill->s_calcul->total);
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
	anthill->room_start = 0;
	anthill->room_end = 0;
	anthill->line_start = 0;
	anthill->line_end = 0;
	anthill->begin_tube = NULL;
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

int		main(void)
{
	char		*line;
	t_anthill	*anthill;

	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (0);
	ft_initialize_struct_anthill(anthill);
	line = NULL;
	get_next_line(0, &line);
	anthill->nb_fourmis = ft_atoi(line);
	printf("nb fourmis = %d\n", anthill->nb_fourmis);
	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
		anthill->nb_rooms += ft_stock_room(ft_strsplit(line, ' '), anthill, &line);
		anthill->nb_tubes += ft_stock_tube(ft_strsplit(line, '-'), anthill);
	}
	printf("nb_rooms = %d\n", anthill->nb_rooms);
	printf("nb_tubes = %d\n", anthill->nb_tubes);
	printf("room_start = %d\n", anthill->room_start);
	printf("room_end = %d\n", anthill->room_end);
	ft_stock_fourmi(anthill);
	ft_stock_start_path(anthill);
	ft_stock_path(anthill, anthill->begin_path);
	ft_stock_tab(anthill);
	ft_sort_path(anthill);
	// ft_match_paths(anthill);
	// calcul_distrib_fourmis(anthill);
	init_struct_kind_path(anthill);
	ft_display(anthill);

	test(anthill);
	// free(game);
	free(line);
	return (0);
}
