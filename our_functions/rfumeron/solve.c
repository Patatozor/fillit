/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:12:34 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/01 14:47:53 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(int slen, t_figure *f, int count_shapes)
{
	char 		**grid;
	t_limits	l;
	t_point		pos;

	grid = initialize_field(slen);
	l.count_shapes = count_shapes;
	l.index = 0;
	l.slen = slen;
	pos.x = 0;
	pos.y = 0;
	if ((fill_grid(&pos, f, &grid, &l) == 1))
	{
		print_square(grid, slen);
		return ;
	}
	else
	{
		free_grid(&grid, slen);
		solve(slen + 1, f, count_shapes);
	}
}
