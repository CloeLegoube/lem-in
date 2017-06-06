/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/06 21:46:23 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_check_same_name(t_anthill *anthill)
{
	t_room	*room;

	room = NULL;
	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		room = anthill->begin_room;
		while (room)
		{
			if (anthill->s_room->num_room != room->num_room &&
				ft_strcmp(anthill->s_room->name, room->name) == 0)
				ft_exit(14, anthill, NULL);
			room = room->next;
		}
		anthill->s_room = anthill->s_room->next;
	}
}

void		ft_check(t_anthill *anthill, char **line)
{
	char	*new_line;
	t_lines	*struct_line;

	if (ft_strstart(*line, "L"))
		ft_exit(10, anthill, NULL);
	if (!(struct_line = (t_lines*)malloc(sizeof(t_lines))))
		return ;
	// new_line = ft_strnew(ft_strlen(*line));
	new_line = ft_strdup(*line);
	struct_line->line = new_line;
	struct_line->next = NULL;
	if (!anthill->begin_lines)
		anthill->begin_lines = struct_line;
	else
		anthill->s_lines->next = struct_line;
	anthill->s_lines = struct_line;
	if (!ft_stock_room(ft_strsplit(*line, ' '), anthill, line) &&
		(!ft_stock_tube(ft_strsplit(*line, '-'), anthill)))
		ft_exit(8, anthill, NULL);
}
