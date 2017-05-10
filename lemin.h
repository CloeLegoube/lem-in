/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:18:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/09 17:20:11 by clegoube         ###   ########.fr       */
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
	struct s_fourmi		*s_fourmi;
	struct s_tube		*s_tube;
	struct s_room		*s_room;
	struct s_anthill	*next;
}					t_anthill;

typedef struct		s_fourmi
{
	int				num_fourmi;
	int				num_room;
	struct s_fourmi	*next;
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
void				ft_stock_map(char **line, t_anthill *anthill);
void				ft_stock_piece(char **line, t_anthill *anthill);
void				ft_stock_struct(char **line, t_anthill *anthill);
void				ft_stock_stars(t_anthill *anthill);
void				ft_resize_piece(t_anthill *anthill, char **piece, char *subline,
					char *subcol);
int					count_char(char *s, char c);
char				*supp_lines(t_anthill *anthill, char **piece);
char				*supp_cols(t_anthill *anthill, char **piece);
void				ft_find_solutions(t_anthill *anthill);
void				ft_strategy_game(t_list **mylist, t_anthill *anthill);
int					ft_calcul_score(int i, int j, t_anthill *anthill);
void				ft_check_fighter(t_anthill *anthill);
int					ft_check_piece(int i, int j, t_anthill *anthill);
int					ft_check_line(t_anthill *anthill, int line);
int					ft_check_col(t_anthill *anthill, int col);
int					ft_check_line_down(t_anthill *anthill, int until);

#endif
