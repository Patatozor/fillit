/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:10:28 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/01 19:10:43 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	fill_grid(t_point *p, t_figure *f, char ***grid, t_limits *l)
{
	if (l->index == l->count_shapes)
		return (1);
	if ((add_shape(grid, &f[l->index], *p, l->slen) == 0))
	{
		if (increment_pos(p, l) == 1)
			return (fill_grid(p, f, grid, l));
		return (0);
	}
	reset_pos(p);
	l->index++;
	if (fill_grid(p, f, grid, l) == 0)
	{
	}
}

/*int	fill_grid(t_point *p, t_figure *f, char ***grid, t_limits *l)
{
	if (l->index == l->count_shapes)
		return (1);
	if ((add_shape(grid, &f[l->index], *p, l->slen) == 1))
	{
		l->index++;
		if (fill_grid(p, f, grid, l) == 0)
		{
			l->index--;
			remove_shape(grid, &f[l->index], l->slen);
			if (increment_pos(p, l) == 1)
				return (fill_grid(p, f, grid, l));
			return (0);
		}
		else
		{
			reset_pos(p);
			return (fill_grid(p, f, grid, l));
		}
	}
	if (increment_pos(p, l) == 1)
		return (fill_grid(p, f, grid, l));
	else
	{
		reset_pos(p);
		return (fill_grid(p, f, grid, l));
	}
	return (0);
}*/
