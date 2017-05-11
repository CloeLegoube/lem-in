/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/09 17:42:51 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_initialize_struct(t_anthill *anthill)
{
	t_fourmi	*fourmi;
	t_tube		*tube;
	t_room		*room;

	anthill->nb_fourmis = 0;
	anthill->nb_rooms = 0;
	anthill->nb_tubes = 0;
	if (!(fourmi = (t_fourmi*)malloc(sizeof(t_fourmi))))
		return (0);
	fourmi->num_fourmi = 0;
	fourmi->num_room = 0;
	fourmi->next = NULL;
	anthill->s_fourmi = fourmi;
	if (!(tube = (t_tube*)malloc(sizeof(t_tube))))
		return (0);
	tube->num_tube = 0;
	tube->from = 0;
	tube->to = 0;
	tube->next = NULL;
	anthill->s_tube = tube;
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	room->num_room = 0;
	room->start = 0;
	room->end = 0;
	room->coordo[0] = 0;
	room->coordo[1] = 0;
	room->next = NULL;
	anthill->s_room = room;
	return (1);
}

int		ft_stock_room(char **tab, t_anthill *anthill, char **line)
{
	int i;
	t_room	new;	

	i = 0;
	//new = *anthill->s_room;
	while (tab[i])
		i++;
	if (ft_strstr(*line, "##start"))
		new.start = 1;
	if (ft_strstr(*line, "##end"))
		new.end = 1;
	if (i != 3)
		return (0);
	else
	{
		anthill->s_room = &new;
		new.num_room = ft_atoi(tab[0]);
		new.coordo[0] = ft_atoi(tab[1]);
		new.coordo[1] = ft_atoi(tab[2]);
		printf("Start ? %d - End ? %d\n", new.start, new.end);
		printf("Numero room : %d - Coordo[%d][%d]\n", anthill->s_room->num_room, anthill->s_room->coordo[0], anthill->s_room->coordo[1]);
		new.next = anthill->s_room;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}


int		ft_stock_tube(char **tab, t_anthill *anthill)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 2)
		return (0);
	else
	{
		anthill->s_tube->num_tube = anthill->nb_tubes;
		anthill->s_tube->from = ft_atoi(tab[0]);
		anthill->s_tube->to = ft_atoi(tab[1]);
		anthill->s_tube->next = NULL;
	}
	// printf("Numero tube : %d - Coordo[%d][%d]\n", anthill->s_tube->num_tube, anthill->s_tube->from, anthill->s_tube->to);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

int		main(void)
{
	char		*line;
	t_anthill	*anthill;
	int			count_room;
	int			count_tube;
	//char		**tab;


	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (0);
	ft_initialize_struct(anthill);
	count_room = 0;
	count_tube = 0;
	line = NULL;
	get_next_line(0, &line);
	anthill->nb_fourmis = ft_atoi(line);
	printf("nb fourmis = %d\n", anthill->nb_fourmis);
		while (get_next_line(0, &line))
		{
			printf("%s\n", line);

			anthill->nb_rooms += ft_stock_room(ft_strsplit(line, ' '), anthill, &line);
			anthill->nb_tubes += ft_stock_tube(ft_strsplit(line, '-'), anthill);

			// tab = ft_strsplit(line, ' ');
			//ft_stock_struct(&line, anthill);
			//ft_find_solutions(game);
			//ft_free_game(game);
		}
	printf("nb_rooms = %d\n", anthill->nb_rooms);
	printf("nb_tubes = %d\n", anthill->nb_tubes);

	// free(game);
	free(line);
	return (0);
}
