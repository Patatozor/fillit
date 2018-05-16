/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square_side.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:45:06 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/16 20:11:49 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Function calculates the smallest square for N Tetriminos. It should be increased by 1 in a loop
 */

int		smallest_square_side(int tetrimino_count)
{
	int side_len;

	side_len = 0;
	if (tetrimino_count > 0 && tetrimino_count <= 26)
	{

		while ((side_len * side_len) < (tetrimino_count * 4))
			side_len++;
		return (side_len);
	}
	return (0);
}
