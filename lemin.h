/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:18:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/25 19:20:31 by clegoube         ###   ########.fr       */
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
	int					error;
	struct s_lines		*begin_lines;
	struct s_lines		*s_lines;
	struct s_fourmi		*s_fourmi;
	struct s_fourmi		*begin_fourmi;
	struct s_fourmi		*end_fourmi;
	struct s_tube		*s_tube;
	struct s_tube		*begin_tube;
	struct s_room		*s_room;
	struct s_room		*begin_room;
	struct s_path		*s_path;
	struct s_path		*begin_path;
	struct s_path		*end_path;
	struct s_kind_path	*s_kind_path;
	struct s_calcul		*s_calcul;
	struct s_anthill	*next;
}					t_anthill;

typedef struct		s_lines
{
	char			*line;
	struct s_lines	*next;
}					t_lines;


typedef struct		s_match_path
{
	struct s_path		*s_path;
	struct s_match_path	*previous;
	struct s_match_path	*next;
}					t_match_path;

typedef struct		s_calcul
{
	int				total;
	int				nb_path;
	int				left;
	int				*tab;
}					t_calcul;

typedef struct		s_fourmi
{
	int				num_fourmi;
	int				num_room;
	struct s_fourmi	*next;
	struct s_fourmi	*previous;
	struct s_room	*position_path;
}					t_fourmi;

typedef struct		s_tube
{
	int				num_tube;
	int				from;
	int				to;
	char			*str_from;
	char			*str_to;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	int				num_room;
	char			*name;
	int				free;
	int				start;
	int				end;
	int				coordo[2];
	struct s_room	*next;
}					t_room;

typedef struct		s_kind_path
{
	int				len_short;
	int				nb_short;
	char			*tab_short;
	int				len_long;
	int				nb_long;
	char			*tab_long;
	char			*wrong_path;
}					t_kind_path;

typedef struct		s_path
{
	int				num_path;
	int				*tab;
	int				stop;
	int				len;
	int				shorter;
	int				longer;
	struct s_room	*s_path_room;
	struct s_room	*begin_path_room;
	struct s_room	*end_path_room;
	struct s_path	*previous;
	struct s_path	*next;
}					t_path;

int					get_next_line(const int fd, char **line);
void				ft_check(t_anthill *anthill, char **line);
int					ft_printf(char *format, ...);
char				**ft_strsplit(char const *s, char c);
int					ft_stock_room(char **tab, t_anthill *anthill, char **line);
int					ft_stock_tube(char **tab, t_anthill *anthill);
int					ft_stock_fourmi(t_anthill *anthill);
int					ft_stock_start_path(t_anthill *anthill);
void				ft_stock_path(t_anthill *anthill, t_path *begin_path);
void				ft_stock_tab(t_anthill *anthill);
void				ft_stock_copy_path(t_path **copy_path, t_anthill *anthill);
void				ft_check_each_tube(t_anthill *anthill, int check);
t_room				*find_room(int target, t_anthill *anthill, t_room **room);
void				init_struct_kind_path(t_anthill	*anthill);
void				ft_display(t_anthill	*anthill);
int					ft_delete_wrong_path(t_anthill	*anthill);
void		ft_lstswap(t_path **start, t_path *e1, t_path *e2);
int					test(t_anthill	*anthill);
int		ft_check_if_room_exist(t_path *path, int tube);
void	ft_sort_path(t_anthill	*anthill);
char 	*ft_name_by_room(t_anthill *anthill, int room);
int		ft_find_room_by_name(t_anthill *anthill, char *name);

#endif
