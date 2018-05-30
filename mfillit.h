/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfillit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:10:25 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/30 18:17:37 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MFILLIT_H
# define MFILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft/libft.h"

// # define FILE_ERROR (-1)
// # define MALLOC_ERROR (-2)
// # define CAT_ERROR (-3)

// typedef	struct	s_point
// {
// 	int		x;
// 	int		y;
// }				t_point;

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					height;
	int					width;
}						t_tetrimino;
typedef struct	s_coordinate
{
	int		x;
	int		y;
}				t_coordinate;

// t_tetrimino				*arrange(t_tetrimino *start);
// t_tetrimino				*splittab(char **tab);
// t_tetrimino				*newtetri(char **tetrimino, int num);



char			*read_file_to_string(char *filename);
char			**initialize_field(int sqr_len);
int				smallest_square_side(int tetrimino_count);
int				error_check(char *str);
// int				count_shapes(char *str);
// void			correct_points(t_figure *pfigure);
// t_figure		*store_shapes(char *str);
// t_figure		initialize_figure(char *str, int index);
// t_point			initialize_point(char *str, int index);

#endif