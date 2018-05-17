/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:48:25 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/17 20:44:47 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

_Bool	tetrimino_is_valid(t_tetrimino *tetrimino)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetrimino->tetrimino[i][j] == '#')
			{
				if (i > 0 && tetrimino->tetrimino[i - 1][j] == '#')
					counter++;
				if (i < 3 && tetrimino->tetrimino[i + 1][j] == '#')
					counter++;
				if (j > 0 && tetrimino->tetrimino[i][j - 1] == '#')
					counter++;
				if (j < 3 && tetrimino->tetrimino[i][j + 1] == '#')
					counter++;
			}
		}
	}
	return (counter == 6 || counter == 8);
}
