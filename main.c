/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/26 20:09:34 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_exit(int nb, t_anthill *anthill, char **line)
{
	nb = 0;
	ft_printf("ERROR\n");
	ft_free(anthill);
	if (line && *line)
		ft_strdel(line);
	get_next_line(-2, NULL);
	exit(0);
}

t_anthill	*ft_initialize_struct_anthill(void)
{
	t_anthill *anthill;

	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (NULL);
	anthill->nb_rooms = 0;
	anthill->nb_tubes = 0;
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
	return (anthill);
}

void		ft_display_lines(t_anthill *anthill)
{
	anthill->s_lines = anthill->begin_lines;
	ft_printf("%d\n", anthill->nb_fourmis);
	while (anthill->s_lines)
	{
		ft_printf("%s\n", anthill->s_lines->line);
		anthill->s_lines = anthill->s_lines->next;
	}
}

void		ft_execute(t_anthill *anthill)
{
	ft_check_same_name(anthill);
	if (anthill->room_end == -42 || anthill->room_start == -42)
		ft_exit(12, anthill, NULL);
	ft_stock_fourmi(anthill);
	ft_stock_tube_room(anthill);
	ft_add_the_previous(anthill, anthill->room_start);
	ft_stock_start_path(anthill);
	ft_stock_path(anthill, anthill->begin_path);
	ft_stock_tab(anthill);
	ft_sort_path(anthill);
	ft_display_lines(anthill);
	ft_display(anthill);
	ft_free(anthill);
}

int			main(void)
{
	char		*line;
	t_anthill	*anthill;
	int			gnl;

	anthill = ft_initialize_struct_anthill();
	line = NULL;
	gnl = get_next_line(0, &line);
	if (gnl == 0 || gnl == -1)
		ft_exit(7, anthill, &line);
	if (!ftdigit(line))
		ft_exit(5, anthill, &line);
	anthill->nb_fourmis = ft_atoi(line);
	if (anthill->nb_fourmis <= 0)
		ft_exit(13, anthill, &line);
	free(line);
	while ((gnl = get_next_line(0, &line)))
	{
		if (gnl == -1)
			ft_exit(7, anthill, &line);
		ft_check(anthill, &line);
		free(line);
	}
	ft_execute(anthill);
	get_next_line(-2, NULL);
	return (0);
}
