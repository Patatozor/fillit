/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:11:32 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 15:40:33 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

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
