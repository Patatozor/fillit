/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:12:34 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/03 17:19:11 by rfumeron         ###   ########.fr       */
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
