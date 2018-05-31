
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:10:28 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 02:30:41 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fill_grid(t_point *p, t_figure *f, char ***grid, t_limits *l)
{
	ft_putnbr(l->index);
	ft_putchar('\n');
	if (l->index == l->count_shapes)
		return (1);
	else if ((add_shape(grid, &f[l->index], *p, l->slen) == 1))
	{
		l->index++;
		p->x = 0;
		p->y = 0;
		return (fill_grid(p, f, grid, l));
	}
	else if (increment_pos(p, l))
		return (fill_grid(p, f, grid, l));
	else
		return (0);
}
