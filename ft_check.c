/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 23:23:25 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_check_correct_path(t_anthill *anthill)
{
	int i;
	int nb_path;

	anthill->s_path = anthill->begin_path;
	i = 0;
	nb_path = 0;
	while (anthill->s_path)
	{
		ft_printf("num_room %d VS %d\n", anthill->s_path->end_path_room->num_room,anthill->room_end );
		if (anthill->s_path->end_path_room->num_room != anthill->room_end)
			i++;
		anthill->s_path = anthill->s_path->next;
		nb_path++;
	}
	if (i == nb_path)
		ft_exit(2);
}

void	ft_display_lines(t_anthill *anthill)
{
	anthill->s_lines = anthill->begin_lines;
	ft_printf("%d\n", anthill->nb_fourmis);
	while (anthill->s_lines)
	{
		ft_printf("%s\n", anthill->s_lines->line);
		anthill->s_lines = anthill->s_lines->next;
	}
}

// int		ft_exit(t_anthill *anthill)
// {
// 	if(anthill->error)
// 	{
// 		ft_printf("ERROR\n");
// 		exit(0);
// 	}
// 	return (1);
// }

void	ft_exit(int nb)
{
	ft_printf("ERROR %d\n", nb);
	exit(0);
}

char	*ft_strstart(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (little[i] == '\0')
			return ((char *)big + i);
		if ( big[i] == little[i])
			i++;
		else
			return (NULL);
	}
	return (NULL);
}


void		ft_check(t_anthill *anthill, char **line)
{
	char	*new_line;
	t_lines	*struct_line;

	if (ft_strstart(*line, "L"))
	{
		// ft_printf("my check error %s - line = %s", ft_strstart(*line, "L"), *line);
		anthill->error = 1;
		return ;
	}
	if (!(struct_line = (t_lines*)malloc(sizeof(t_lines))))
		return ;
	new_line = ft_strnew(ft_strlen(*line));
	new_line = ft_strdup(*line);
	struct_line->line = new_line;
	if (!anthill->begin_lines)
		anthill->begin_lines = struct_line;
	else
		anthill->s_lines->next = struct_line;
	anthill->s_lines = struct_line;
	// if (!ft_strstr(*line, "##start") && !ft_strstr(*line, "##start") && ft_strstart(*line, "#"))
	// 	return ;
	if (ft_stock_room(ft_strsplit(*line, ' '), anthill, line))
		anthill->nb_rooms++;
	else
		anthill->nb_tubes += ft_stock_tube(ft_strsplit(*line, '-'), anthill);
}
