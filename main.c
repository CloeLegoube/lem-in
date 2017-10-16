/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/16 22:42:44 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_exit(int nb, t_anthill *anthill, char **line)
{
	// nb = 0;
	ft_printf("ERROR %d\n", nb);
	ft_free(anthill);
	if (line && *line)
		ft_strdel(line);
	get_next_line(-2, NULL);
	exit(0);
}

void		ft_execute(t_anthill *anthill)
{
	ft_check_same_name(anthill);
	ft_if_start_end_exist(anthill, anthill->room_start);
	ft_if_start_end_exist(anthill, anthill->room_end);
	if(anthill->room_start == anthill->room_end)
		ft_exit(16, anthill, NULL);
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

void		ft_comment_nb_fourmis(t_anthill *anthill, char *line, int gnl)
{
	while ((gnl = get_next_line(0, &line)) && ft_strstart(line, "#"))
	{
		if (gnl == 0 || gnl == -1)
			ft_exit(7, anthill, &line);
		ft_add_lines(anthill, line);
	}
	if (gnl == 0 || gnl == -1)
		ft_exit(7, anthill, &line);
	if (!ftdigit(line))
		ft_exit(5, anthill, &line);
	anthill->nb_fourmis = ft_atoi(line);
	if (ft_strstart(line, "-") || anthill->nb_fourmis <= 0)
		ft_exit(13, anthill, &line);
	ft_add_lines(anthill, line);
	free(line);
}

int			main(void)
{
	char		*line;
	t_anthill	*anthill;
	int			gnl;
	int			check;

	anthill = ft_initialize_struct_anthill();
	line = NULL;
	gnl = 0;
	check = 1;
	ft_comment_nb_fourmis(anthill, line, gnl);
	while (check && (gnl = get_next_line(0, &line)))
	{
		if (gnl == -1)
			ft_exit(7, anthill, &line);
		check = ft_check(anthill, &line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_execute(anthill);
	get_next_line(-2, NULL);
	return (0);
}

/*
Si les tubes n'ont pas de start OK
S'il y a un commentaire au debut OK
S'il y a un retour a la ligne a la fin OK
Boucle si les chemins ne sont pas compatibles OK
0-2
3-1
##end suivi d'un ##start ne renvoie rien OK
-2147483649 fourmis plante OK
*/
