/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_road.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:48:18 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/25 21:08:02 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_lstlen(t_anthill *anthill)
{
	int i;

	i = 0;
	anthill->match_path = anthill->begin_match_path;
	while (anthill->match_path)
	{
		i++;
		anthill->match_path = anthill->match_path->next;
	}
	return (i);
}

void	init_calcul(t_anthill *anthill)
{
	t_calcul	*calcul;
	int			i;

	i = 0;
	if (!(calcul = (t_calcul*)malloc(sizeof(t_calcul))))
		return ;
	calcul->total = anthill->nb_fourmis;
	calcul->left = 0;
	calcul->nb_path = ft_lstlen(anthill);
	if (!(calcul->tab = (int *)malloc(sizeof(int) * calcul->nb_path)))
		return ;
	while(i < calcul->nb_path)
		calcul->tab[i++] = 0;
	anthill->s_calcul = calcul;
}

void	calcul_distrib_fourmis(t_anthill *anthill)
{
	int 		len_shorter;
	int			i;
	int			nb_path;
	t_calcul	*calcul;

	len_shorter = anthill->begin_match_path->s_path->len;
	init_calcul(anthill);
	calcul = anthill->s_calcul;
	nb_path = calcul->nb_path;
	printf("nb_path %d\n", nb_path);

	anthill->match_path = anthill->end_match_path;
	printf("***** CALCUL FONCTIONS *****\n");
	while (anthill->match_path)
	{
		printf("num_path %d\n", anthill->match_path->s_path->num_path);

		calcul->left = anthill->match_path->s_path->len - len_shorter;
		printf("anthill->left = %d - %d = %d\n", anthill->match_path->s_path->len, len_shorter, calcul->left);

		// anthill->left = 53 - 24 = 29;
		calcul->total = calcul->total - calcul->left;
		printf("calcul->total = %d\n", calcul->total);

		// anthill->total = 100 - 29 = 71;
		i = 0;
		while(i < nb_path)
		{
			calcul->tab[i] += calcul->total / nb_path;
			printf("calcul->total[%d] = %d - calcul->total / calcul->nb_path %d\n", i, calcul->tab[i], calcul->total / calcul->nb_path);
			i++;
		}
		calcul->total = calcul->left + calcul->total - ((calcul->total / calcul->nb_path) * calcul->nb_path);
		printf("calcul->total = %d\n", calcul->total);

		nb_path--;
		printf("num %d) tab = %s - len %d\n",anthill->match_path->s_path->num_path, anthill->match_path->s_path->tab, anthill->match_path->s_path->len);
		anthill->match_path = anthill->match_path->previous;
	}
}
