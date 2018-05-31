/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:20:19 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 04:40:42 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	initialize_figure(char *str, int index)
{
	t_figure	fig;
	t_figure	*pfig;
	int			i;

	i = 0;
	fig.xmax = 0;
	fig.ymax = 0;
	fig.letter = 'A' + index;
	while (i < 4)
	{
		(fig.p)[i] = initialize_point(str, i);
		i++;
	}
	pfig = &fig;
	correct_points(pfig);
	return (fig);
}
