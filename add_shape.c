/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:08:29 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/04 16:25:56 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_add_shape(char ***grid, t_figure f, t_point p, int len)
{
	int		i;
	t_point	*pt;
	char	**g;

	i = -1;
	g = *grid;
	if ((p.x + f.xmax) >= len || (p.y + f.ymax) >= len)
		return (0);
	pt = f.p;
	if (g[pt[0].x + p.x][pt[0].y + p.y] != '.')
		return (0);
	if (g[pt[1].x + p.x][pt[1].y + p.y] != '.')
		return (0);
	if (g[pt[2].x + p.x][pt[2].y + p.y] != '.')
		return (0);
	if (g[pt[3].x + p.x][pt[3].y + p.y] != '.')
		return (0);
	add_shape(grid, f, p);
	return (1);
}

void	add_shape(char ***grid, t_figure f, t_point p)
{
	int		i;
	t_point	pt;
	char	**g;

	i = -1;
	g = *grid;
	while (++i < 4)
	{
		pt = (f.p)[i];
		g[pt.x + p.x][pt.y + p.y] = f.letter;
	}
}

void	remove_shape(char ***grid, t_figure f, t_point p)
{
	int		i;
	t_point	pt;
	char	**g;

	i = -1;
	g = *grid;
	while (++i < 4)
	{
		pt = (f.p)[i];
		g[pt.x + p.x][pt.y + p.y] = '.';
	}
}
