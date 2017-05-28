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
	if (!ft_strstr(*line, "##start") && !ft_strstr(*line, "##start") && ft_strstart(*line, "#"))
		return ;
	anthill->nb_rooms += ft_stock_room(ft_strsplit(*line, ' '), anthill, line);
	if(anthill->error)
		return ;
	anthill->nb_tubes += ft_stock_tube(ft_strsplit(*line, '-'), anthill);
	if(anthill->error)
		return ;
}
