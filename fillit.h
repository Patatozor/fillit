/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:10:25 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/04 19:37:29 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_figure
{
	t_point	p[4];
	int		xmax;
	int		ymax;
	char	letter;
}				t_figure;

char			*read_file_to_str(char *filename);
char			**initialize_field(int sqr_len);
int				smallest_square_side(int tetrimino_count);
int				error_check(char *str);
int				display_error(int ret);
int				count_shapes(char *str);
int				get_nb_tetrimino(char *str);
int				tetrimino_has_4_points(char *s);
int				tetrimino_is_valid(t_figure *f);
int				main_store(char **str, int count_shapes);
int				fill_grid(t_figure *f, char ***grid, int slen);
int				can_add_shape(char ***grid, t_figure f, t_point p, int len);
void			add_shape(char ***grid, t_figure f, t_point p);
void			increment_pos(t_point *p, int slen);
void			remove_shape(char ***grid, t_figure f, t_point p);
void			correct_points(t_figure *pfigure);
void			print_square(char **grid, int len);
void			solve(int side_len, t_figure *shapes, int count_shapes);
void			free_grid(char ***grid, int slen);
t_figure		*store_shapes(char **str, int count_shapes);
t_figure		initialize_figure(char *str, int index);
t_figure		end_shape(void);
t_point			initialize_point(char *str, int index);
t_point			new_point(void);

#endif
