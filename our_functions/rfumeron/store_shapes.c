/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:07:57 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/03 17:16:18 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main_store(char **str, int count_shapes)
{
	t_figure	*shapes;
	int			side_len;

	if ((shapes = store_shapes(str, count_shapes)) == NULL)
		return (0);
	if ((side_len = smallest_square_side(count_shapes)) == 0)
		return (0);
	solve(side_len, shapes, count_shapes);
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
	while (i < 4)
	{
		(fig.p)[i] = initialize_point(str, i);
		i++;
	}
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
