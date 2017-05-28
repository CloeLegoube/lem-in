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

void	ft_free_lines(t_anthill *anthill)
{
	t_lines	*tmp;

	anthill->s_lines = anthill->begin_lines;
	while (anthill->s_lines)
	{
		free(anthill->s_lines->line);
		tmp = anthill->s_lines->next;
		free(anthill->s_lines->next);
		free(anthill->s_lines);
		anthill->s_lines = tmp;
	}
	free(anthill->s_lines);
	free(anthill->begin_lines);
	free(tmp);
}

void	ft_free_fourmis(t_anthill *anthill)
{
	t_fourmi	*tmp;

	anthill->s_fourmi = anthill->begin_fourmi;
	while (anthill->s_fourmi)
	{
		tmp = anthill->s_fourmi->next;
		free(anthill->s_fourmi->next);
		free(anthill->s_fourmi->previous);
		free(anthill->s_fourmi->position_path);
		free(anthill->s_fourmi);
		anthill->s_fourmi = tmp;
	}
	free(anthill->s_fourmi);
	free(anthill->begin_fourmi);
	free(anthill->end_fourmi);
	free(tmp);
}

void	ft_free_tubes(t_anthill *anthill)
{
	t_tube	*tmp;

	anthill->s_tube = anthill->begin_tube;
	while (anthill->s_tube)
	{
		free(anthill->s_tube->str_from);
		free(anthill->s_tube->str_to);
		tmp = anthill->s_tube->next;
		free(anthill->s_tube->next);
		free(anthill->s_tube);
		anthill->s_tube = tmp;
	}
	free(anthill->s_tube);
	free(anthill->begin_tube);
	free(tmp);
}

void	ft_free_rooms(t_anthill *anthill)
{
	t_room	*tmp;

	anthill->s_room = anthill->begin_room;
	while (anthill->s_room)
	{
		free(anthill->s_room->name);
		tmp = anthill->s_room->next;
		free(anthill->s_room->next);
		free(anthill->s_room);
		anthill->s_room = tmp;
	}
	free(anthill->s_room);
	free(anthill->begin_room);
	free(tmp);
}

void	ft_free_path(t_anthill *anthill)
{
	t_path	*tmp;

	anthill->s_path = anthill->begin_path;
	while (anthill->s_path)
	{
		free(anthill->s_path->tab);
		//ATTENTION
		free(anthill->s_path->s_path_room);
		free(anthill->s_path->begin_path_room);
		free(anthill->s_path->end_path_room);
		tmp = anthill->s_path->next;
		free(anthill->s_path->next);
		free(anthill->s_path->previous);
		free(anthill->s_path);
		anthill->s_path = tmp;
	}
	free(anthill->s_path);
	free(anthill->begin_path);
	free(tmp);
}
