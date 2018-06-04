/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_shapes_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:02:01 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/04 16:16:33 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main_store(char **str, int count_shapes)
{
	t_figure	*shapes;
	int			side_len;

	if ((shapes = store_shapes(str, count_shapes)) == NULL)
		return (0);
	if ((side_len = smallest_square_side(count_shapes)) == 0)
		return (0);
	solve(side_len, shapes, count_shapes);
	free(shapes);
	return (1);
}

t_figure	*store_shapes(char **str, int count_shapes)
{
	int			i;
	char		*str_chunk;
	t_figure	*shapes_table;

	i = 0;
	if (!(shapes_table = malloc(sizeof(t_figure) * (count_shapes + 1))))
		return (NULL);
	while (i < count_shapes)
	{
		str_chunk = ft_strsub(*str, i * 21, 20);
		if (!tetrimino_has_4_points(str_chunk))
			return (NULL);
		shapes_table[i] = initialize_figure(str_chunk, i);
		free(str_chunk);
		if (!tetrimino_is_valid(&(shapes_table[i])))
			return (NULL);
		i++;
	}
	shapes_table[i] = end_shape();
	return (shapes_table);
}

t_figure	initialize_figure(char *str, int index)
{
	t_figure	fig;
	t_figure	*pfig;
	int			i;

	i = 0;
	fig.xmax = 0;
	fig.ymax = 0;
	fig.letter = 'A' + index;
	(fig.p)[0] = initialize_point(str, 0);
	(fig.p)[1] = initialize_point(str, 1);
	(fig.p)[2] = initialize_point(str, 2);
	(fig.p)[3] = initialize_point(str, 3);
	pfig = &fig;
	correct_points(pfig);
	return (fig);
}

t_figure	end_shape(void)
{
	t_figure	fig;

	fig.xmax = -1;
	fig.ymax = 0;
	fig.letter = '.';
	fig.p[0] = new_point();
	fig.p[1] = new_point();
	fig.p[2] = new_point();
	fig.p[3] = new_point();
	return (fig);
}

/*
 * ** Function calculates the smallest square for N Tetriminos.
 * ** It should be increased by 1 in a loop
*/

int			smallest_square_side(int tetrimino_count)
{
	int	side_len;

	side_len = 0;
	if (tetrimino_count > 0 && tetrimino_count <= 26)
	{
		while ((side_len * side_len) < (tetrimino_count * 4))
			side_len++;
		return (side_len);
	}
	return (0);
}
