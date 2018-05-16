/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:10:25 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/16 22:40:31 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft/libft.h"
// # define FILE_ERROR (-1)
// # define MALLOC_ERROR (-2)
// # define CAT_ERROR (-3)

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_figure
{
	t_point	points[4];
	char letter;
}				t_figure;

_Bool	tetrimino_is_valid(t_figure *t_figure);
char	*ret_file_string(char *filename);
int		smallest_square_side(int tetrimino_count);
int		wrong_symbols(char *str);
int		len_4_symbols(char *str);
int		height_4_lines(char *str);

#endif
