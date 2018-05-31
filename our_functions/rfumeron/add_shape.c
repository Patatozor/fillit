/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:08:29 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 04:51:14 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	add_shape(char ***grid, t_figure *f, t_point *p, int len)
{
	int		i;
	t_point	pt;
	char	**g;

	i = -1;
	g = *grid;
	if ((p->x + f->xmax) > len || (p->y + f->ymax) > len)
		return (0);
	while (++i < 4)
	{
		pt = (f->p)[i];
		if (g[pt.x + p->x][pt.y + p->y] != '.')
			return (0);
	}
	while (--i >= 0)
	{
		pt = (f->p)[i];
		g[pt.x + p->x][pt.y + p->y] = f->letter;;
	}
	return (1);
}
