/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:12:34 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 04:36:17 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(int slen, t_figure **f, int count_shapes)
{
	char 		**grid;
	t_limits	l;
	t_point		pos;

	grid = initialize_field(slen);
	l.slen = slen;
	l.count_shapes = count_shapes;
	l.index = 0;
	pos.x = 0;
	pos.y = 0;
	if ((fill_grid(&pos, f, &grid, &l) == count_shapes))
	{
		print_square(grid, slen);
		return (1);
	}
	else
	{
		free(grid);
		return (solve(slen + 1, f, count_shapes));
	}
	return (0);
}
