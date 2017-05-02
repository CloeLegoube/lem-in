/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:18:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/05/02 16:19:09 by clegoube         ###   ########.fr       */
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

typedef struct		s_coor
{
	int				coordo[2];
	int				score;
	int				i;
	int				j;
	int				distance_fighter[2];
	int				au_dessus;
	int				a_gauche;
	struct s_coor	*next;
}					t_coor;

typedef struct		s_game
{
	int				player;
	char			fighter;
	int				position_fighter[2];
	int				map_line;
	int				piece_line_max;
	int				piece_line;
	int				map_col;
	int				piece_col;
	int				piece_col_max;
	char			symbol;
	char			**map;
	char			**piece;
	int				*coordo;
	int				center[2];
	int				stars;
	int				strategy;
}					t_game;

int					get_next_line(const int fd, char **line);
char				**ft_strsplit(char const *s, char c);
void				ft_stock_map(char **line, t_game *game);
void				ft_stock_piece(char **line, t_game *game);
void				ft_stock_struct(char **line, t_game *game);
void				ft_stock_stars(t_game *game);
void				ft_resize_piece(t_game *game, char **piece, char *subline,
					char *subcol);
int					count_char(char *s, char c);
char				*supp_lines(t_game *game, char **piece);
char				*supp_cols(t_game *game, char **piece);
void				ft_find_solutions(t_game *game);
void				ft_strategy_game(t_list **mylist, t_game *game);
int					ft_calcul_score(int i, int j, t_game *game);
void				ft_check_fighter(t_game *game);
int					ft_check_piece(int i, int j, t_game *game);
int					ft_check_line(t_game *game, int line);
int					ft_check_col(t_game *game, int col);
int					ft_check_line_down(t_game *game, int until);

#endif
