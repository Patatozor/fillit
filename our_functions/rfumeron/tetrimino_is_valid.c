/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:48:25 by mrakhman          #+#    #+#             */
/*   Updated: 2018/06/03 17:51:04 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_connections_point(t_figure *f, int i)
{
	t_point	p;
	int		counter;
	int		j;

	counter = 0;
	j = i;
	p = (f->p)[i];
	while (++j <= 3)
	{
		if (p.x == ((f->p)[j]).x)
		{
			if (p.y == ((f->p)[j]).y + 1 || p.y == ((f->p)[j]).y - 1)
				counter += 2;
		}
		if (p.y == ((f->p)[j]).y)
		{
			if (p.x == ((f->p)[j]).x + 1 || p.x == ((f->p)[j]).x - 1)
				counter += 2;
		}
	}
	return (counter);
}

int			tetrimino_is_valid(t_figure *f)
{
	int		counter;

	counter = 0;
	counter += count_connections_point(f, 0);
	counter += count_connections_point(f, 1);
	counter += count_connections_point(f, 2);
	return ((counter == 6 || counter == 8) ? 1 : 0);
}

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
