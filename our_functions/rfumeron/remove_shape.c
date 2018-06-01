/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:14:22 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/01 19:11:02 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	remove_shape(char ***grid, t_figure *f, int slen)
{
	int		i;
	int		j;
	char	letter;
	char	**g;

	i = -1;
	g = *grid;
	letter = f->letter;
	print_square(*grid, slen);
	while (++i < slen)
	{
		j = -1;
		while (++j < slen)
		{
			if (g[i][j] == letter)
				g[i][j] = '.';
		}
	}
	ft_putchar('\n');
	print_square(*grid, slen);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
}
