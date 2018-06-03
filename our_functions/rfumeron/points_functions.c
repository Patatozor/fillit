/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:02:49 by rfumeron          #+#    #+#             */
/*   Updated: 2018/06/03 18:02:51 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	new_point(void)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	return (p);
}

t_point	initialize_point(char *str, int index)
{
	int		i;
	int		j;
	t_point	p;

	i = 0;
	j = 0;
	p.x = 4;
	p.y = 4;
	while (i < 20 && str[i])
	{
		if (str[i] == '#')
		{
			if (j == index)
			{
				p.x = i % 5;
				p.y = i / 5;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

void	correct_points(t_figure *pfig)
{
	int		xmi;
	int		ymi;
	int		i;

	xmi = 4;
	ymi = 4;
	i = 0;
	while (i < 4)
	{
		xmi = ((pfig->p[i]).x < xmi) ? (pfig->p[i]).x : xmi;
		ymi = ((pfig->p[i]).y < ymi) ? (pfig->p[i]).y : ymi;
		i++;
	}
	while (--i >= 0)
	{
		(pfig->p[i]).x -= xmi;
		(pfig->p[i]).y -= ymi;
		if ((pfig->p[i]).x > pfig->xmax)
			pfig->xmax = (pfig->p[i]).x;
		if ((pfig->p[i]).y > pfig->ymax)
			pfig->ymax = (pfig->p[i]).y;
	}
}
