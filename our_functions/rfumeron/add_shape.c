/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:08:29 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/24 19:08:32 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	add_shape(char **grid, t_figure f, t_point *pos, int len)
{
	int	i;
	t_point	*p;

	i = -1;
	if ((pos->x + f->xmax) > len || (pos->y + f->ymax) > len)
		return (0);
	while (++i < 4)
	{
		p = (f->p)[i];
		if (grid[p->x + pos->x][p->y + pos->y] != '.')
			return (0);
	}
	while (--i >= 0)
	{
		p = (f->p)[i];
		grid[p->x + pos->x][p->y + pos->y] = f->letter;;
	}
	return (1);
}
