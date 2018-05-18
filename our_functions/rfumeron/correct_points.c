/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:58:42 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 13:13:59 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

void	correct_points(t_figure *pfigure)
{
	int		xmi;
	int		ymi;
	int		i;

	xmi = 4;
	ymi = 4;
	i = 0;
	while (i < 4)
	{
		xmi = ((pfigure->points[i]).x < xmi) ? (pfigure->points[i]).x : xmi;
		ymi = ((pfigure->points[i]).y < ymi) ? (pfigure->points[i]).y : ymi;
		i++;
	}
	while (--i >= 0)
	{
		(pfigure->points[i]).x -= xmi;
		(pfigure->points[i]).y -= ymi;
		if ((pfigure->points[i]).x > pfigure->xmax)
			pfigure->xmax = (pfigure->points[i]).x;
		if ((pfigure->points[i]).y > pfigure->ymax)
			pfigure->ymax = (pfigure->points[i]).y;
	}
}
