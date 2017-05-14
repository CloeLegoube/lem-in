/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:18:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/12 23:10:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define BUFF_SIZE 235

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

#include <string.h>

typedef struct		s_anthill
{
	int					nb_fourmis;
	int					nb_rooms;
	int					nb_tubes;
	int					room_start;
	int					line_start;
	int					room_end;
	int					line_end;
	struct s_fourmi		*s_fourmi;
	struct s_fourmi		*begin_fourmi;
	struct s_tube		*s_tube;
	struct s_tube		*begin_tube;
	struct s_room		*s_room;
	struct s_room		*begin_room;
	struct s_room		*s_path;
	struct s_room		*begin_path;
	struct s_anthill	*next;
}					t_anthill;

typedef struct		s_fourmi
{
	int				num_fourmi;
	int				num_room;
	struct s_fourmi	*next;
	struct s_fourmi	*previous;
}					t_fourmi;

typedef struct		s_tube
{
	int				num_tube;
	int				from;
	int				to;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	int				num_room;
	int				start;
	int				end;
	int				coordo[2];
	struct s_room	*next;
}					t_room;

int					get_next_line(const int fd, char **line);
char				**ft_strsplit(char const *s, char c);
int					ft_stock_room(char **tab, t_anthill *anthill, char **line);
int					ft_stock_tube(char **tab, t_anthill *anthill);
int					ft_stock_fourmi(t_anthill *anthill);
int					ft_stock_path(t_anthill *anthill);

#endif
