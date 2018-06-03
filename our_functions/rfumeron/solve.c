/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:12:34 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/03 17:52:04 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(int slen, t_figure *f, int count_shapes)
{
	char 		**grid;

	grid = initialize_field(slen);
	if ((fill_grid(f, &grid, slen) == 1))
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

void	print_square(char **grid, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			ft_putchar(grid[j][i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
