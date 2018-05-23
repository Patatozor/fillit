/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:48:25 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/18 17:30:51 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tetrimino_has_4_points(char *s)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s == '#')
			counter++;
		s++;
	}
	return ((counter == 4) ? 1 : 0);
}

int		tetrimino_is_valid(t_figure *f)
{
	int		counter;
	int		i;
	t_point	*p;

	i = 0;
	counter = 0;
	while (++i < 3)
	{
		p = &(f->p[i]);
		if ((p->x == (f->p[i + 1]).x && p->y != (f->p[i + 1]).y)
			|| (p->y == (f->p[i + 1]).y && p->x != (f->p[i + 1]).x))
			counter += 2;
	}
	while (i >= 2)
	{
		p = &(f->p[i]);
		if ((p->x == (f->p[0]).x && p->y != (f->p[0]).y)
			|| (p->y == (f->p[0]).y && p->x != (f->p[0]).x))
			counter += 2;
		i--;
	}
	if ((p->x == (f->p[1]).x && p->y != (f->p[1]).y)
		|| (p->y == (f->p[1]).y && p->x != (f->p[1]).x))
		counter += 2;
	return ((counter == 6 || counter == 8) ? 1 : 0);
}
