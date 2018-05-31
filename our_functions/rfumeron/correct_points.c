/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:58:42 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 17:41:15 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
