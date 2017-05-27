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

void		ft_check(t_anthill *anthill, char **line)
{
	char	*new_line;
	t_lines	*struct_line;

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

	anthill->nb_rooms += ft_stock_room(ft_strsplit(*line, ' '), anthill, line);
	anthill->nb_tubes += ft_stock_tube(ft_strsplit(*line, '-'), anthill);
}
