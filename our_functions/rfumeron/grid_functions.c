/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:00:54 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/03 18:01:22 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(char ***grid, int slen)
{
	int	i;
	char **g;

	i = -1;
	g = *grid;
	while (++i < slen)
	{
		free(g[i]);
	}
	free(g);
}

char	**initialize_field(int sqr_len)
{
	char	**grid;
	int		y;

	y = 0;
	grid = NULL;
	if (!(grid = malloc(sizeof(char *) * sqr_len)))
		return (NULL);
	while (y < sqr_len)
	{
		if (!(grid[y] = malloc(sizeof(char) * sqr_len)))
			return (NULL);
		ft_memset(grid[y], '.', sqr_len);
		y++;
	}
	return (grid);
}
