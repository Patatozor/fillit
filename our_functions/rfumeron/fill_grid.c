/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:10:28 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/30 21:47:07 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fill_grid(t_point *pos, t_figure *f, char **grid, t_limits *l)
{
	if (limits->index == limits->count_shapes + 1)
		return (1);
	else
	{
		if ((add_shape(grid, f, limits, pos, l->slen) == 1))
		{
			l->index++;
			f++;
			pos->x = 0;
			pos->y = 0;
			return (fill_grid(pos, f, grid, l));
		}
		else
		{
			if (increment_pos(pos, l->slen))
				fill_grid(pos, f, grid, l);
			else
				return (0);
		}		
	}
}
