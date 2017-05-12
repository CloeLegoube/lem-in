/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:46:57 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 20:49:13 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (*tab == NULL)
		return ;
	while (*(tab[i]))
		ft_strdel(tab[i++]);
	free(*tab);
	*tab = NULL;
}
