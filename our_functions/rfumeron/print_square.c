/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:08:17 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/01 14:46:09 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char **grid, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			ft_putchar(grid[j][i]);
		ft_putchar('\n');
	}
}
