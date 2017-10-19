/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_fourmi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/16 21:58:15 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_struct_fourmi(t_fourmi **fourmi)
{
	if (!(*fourmi = (t_fourmi*)malloc(sizeof(t_fourmi))))
		return (0);
	(*fourmi)->num_fourmi = 0;
	(*fourmi)->num_room = 0;
	(*fourmi)->next = NULL;
	(*fourmi)->previous = NULL;
	(*fourmi)->position_path = NULL;
	return (0);
}

void	ft_stock_fourmi(t_anthill *anthill)
{
	t_fourmi	*new;
	t_fourmi	*previous;
	int			i;

	new = NULL;
	previous = NULL;
	i = 1;
	while (i <= anthill->nb_fourmis)
	{
		previous = new;
		init_struct_fourmi(&new);
		new->num_fourmi = i;
		new->num_room = anthill->room_start;
		if (i == 1)
		{
			anthill->begin_fourmi = new;
		}
		else
		{
			new->previous = previous;
			previous->next = new;
		}
		i++;
	}
	anthill->end_fourmi = new;
}
