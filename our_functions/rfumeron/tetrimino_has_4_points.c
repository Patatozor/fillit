/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_has_4_points.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 02:17:25 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 17:00:36 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	tetrimino_has_4_points(char *s)
{
	int counter;

	counter = 0;
	while (*s)
	{
		if (*s == '#')
			counter++;
		s++;
	}
	return ((counter == 4) ? 1 : 0);
}
