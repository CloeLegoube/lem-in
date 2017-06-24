/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/06/23 18:59:18 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_lines(t_anthill *anthill)
{
	t_lines	*tmp;

	if (anthill->begin_lines)
	{
		anthill->s_lines = anthill->begin_lines;
		while (anthill->s_lines)
		{
			tmp = anthill->s_lines->next;
			if (anthill->s_lines)
			{
				free(anthill->s_lines->line);
				free(anthill->s_lines);
			}
			anthill->s_lines = tmp;
		}
	}
}

void	ft_free_fourmis(t_anthill *anthill)
{
	t_fourmi *tmp;

	if (anthill->begin_fourmi)
	{
		anthill->s_fourmi = anthill->begin_fourmi;
		while (anthill->s_fourmi)
		{
			tmp = anthill->s_fourmi->next;
			if (anthill->s_fourmi)
				free(anthill->s_fourmi);
			anthill->s_fourmi = tmp;
		}
	}
}

void	ft_free_tubes(t_anthill *anthill)
{
	t_tube *tmp;

	if (anthill->begin_tube)
	{
		anthill->s_tube = anthill->begin_tube;
		while (anthill->s_tube)
		{
			tmp = anthill->s_tube->next;
			if (anthill->s_tube)
			{
				free(anthill->s_tube->str_from);
				free(anthill->s_tube->str_to);
				free(anthill->s_tube);
			}
			anthill->s_tube = tmp;
		}
	}
}

void	ft_free_rooms(t_anthill *anthill, t_room *begin)
{
	t_room *tmp;

	if (begin)
	{
		anthill->s_room = begin;
		while (anthill->s_room)
		{
			tmp = anthill->s_room->next;
			if (anthill->s_room)
			{
				free(anthill->s_room->name);
				if (anthill->s_room->liste_tubes)
					free(anthill->s_room->liste_tubes);
				free(anthill->s_room);
			}
			anthill->s_room = tmp;
		}
	}
}

void	ft_free_path(t_anthill *anthill)
{
	t_path	*tmp;

	if (anthill->begin_path)
	{
		anthill->s_path = anthill->begin_path;
		while (anthill->s_path)
		{
			tmp = anthill->s_path->next;
			if (anthill->s_path)
				free_path(anthill);
			anthill->s_path = tmp;
		}
	}
}
