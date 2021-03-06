/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:18:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/10/19 21:41:08 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define BUFF_SIZE 235

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <string.h>

typedef struct		s_anthill
{
	int					nb_fourmis;
	int					nb_rooms;
	int					nb_tubes;
	int					nb_path;
	int					room_start;
	int					line_start;
	int					room_end;
	int					line_end;
	int					error;
	int					check_end;
	int					boucle;
	int					end_boucle;
	int					stop;
	struct s_lines		*begin_lines;
	struct s_lines		*s_lines;
	struct s_fourmi		*s_fourmi;
	struct s_fourmi		*begin_fourmi;
	struct s_fourmi		*end_fourmi;
	struct s_tube		*s_tube;
	struct s_tube		*begin_tube;
	struct s_tube		*end_tube;
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
	int				previous;
	int				round;
	int				coordo[2];
	int				*liste_tubes;
	int				len_tube;
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
t_anthill			*ft_initialize_struct_anthill(void);
int					ft_check(t_anthill *anthill, char **line);
int					ft_printf(char *format, ...);
char				**ft_strsplit(char const *s, char c);
int					ft_stock_room(char **tab, t_anthill *anthill, char **line);
int					ft_stock_tube(char **tab, t_anthill *anthill, char *line);
void				ft_stock_fourmi(t_anthill *anthill);
int					ft_stock_start_path(t_anthill *anthill);
void				ft_stock_path(t_anthill *anthill, t_path *begin_path);
void				ft_stock_tab(t_anthill *anthill);
t_path				*ft_stock_copy_path(t_path **copy_path, t_anthill *anthill);
void				if_not_begin_room(t_anthill *anthill, t_room *new);
void				if_begin_room(t_anthill *anthill, t_room *new);
int					not_a_room(char **tab, t_anthill *anthill, char **line);
void				ft_check_each_tube(t_anthill *anthill, t_path *my_path);
t_room				*find_room(int target, t_anthill *anthill, t_room **room,
					int previous);
void				init_struct_kind_path(t_anthill	*anthill);
void				ft_display(t_anthill	*anthill);
int					ft_delete_wrong_path(t_anthill	*anthill);
void				ft_lstswap(t_path **start, t_path *e1, t_path *e2);
int					test(t_anthill	*anthill);
int					ft_check_if_room_exist(t_path *path, int tube_from,
					int tube_to);
void				ft_sort_path(t_anthill	*anthill);
char				*ft_name_by_room(t_anthill *anthill, int room);
int					ft_find_room_by_name(t_anthill *anthill, char *name);
void				ft_display_lines(t_anthill *anthill);
void				ft_exit(int nb, t_anthill *anthill, char **line);
void				ft_check_correct_path(t_anthill *anthill);
char				*ft_strstart(const char *big, const char *little);
int					ftdigit(char *s);
void				ft_free(t_anthill *anthill);
void				ft_free_lines(t_anthill *anthill);
void				ft_free_fourmis(t_anthill *anthill);
void				ft_free_tubes(t_anthill *anthill);
void				ft_free_rooms(t_anthill *anthill, t_room *begin);
void				ft_free_path(t_anthill *anthill);
void				free_path(t_anthill *anthill);
int					if_room_previous(int room, t_anthill *anthill);
void				add_previous(int room, int prev, int num_round,
					t_anthill *anthill);
int					ft_add_the_previous(t_anthill *anthill, int start);
int					if_all_room_has_previous(t_anthill *anthill);
int					his_previous(int room, t_anthill *anthill);
void				ft_stock_tube_room(t_anthill *anthill);
void				ft_check_same_name(t_anthill *anthill);
int					if_room_free(int num_room, t_anthill *anthill);
int					available(int num_room, t_anthill *anthill, int yes);
void				ft_tabdel(char **tab);
int					ft_if_start_end_exist(t_anthill *anthill, int room);
void				ft_add_lines(t_anthill *anthill, char *line);
#endif
