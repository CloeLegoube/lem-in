/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_anthill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 21:35:07 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/19 22:22:54 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
