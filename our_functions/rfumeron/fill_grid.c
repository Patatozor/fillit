/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:10:28 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/03 17:41:40 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fill_grid(t_figure *fig, char ***grid, int slen)
{
	t_point		p;
	t_figure	f;
	
	f = *fig;
	p.y = 0;
	if (f.xmax  == -1)
		return (1);
	while (p.y < slen)
	{
		p.x = 0;
		while (p.x < slen)
		{
			if ((can_add_shape(grid, f, p, slen)) == 1)
			{
				add_shape(grid, f, p);
				if (fill_grid(fig + 1, grid, slen) == 1)
					return (1);
				else
					remove_shape(grid, f, p);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}
