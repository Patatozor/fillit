/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:20:19 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 15:44:21 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_figure	initialize_figure(char *str, int index)
{
	t_figure	figure;
	t_figure	*pfigure;
	int			i;
	char		*str_chunk;

	i = 0;
	figure.xmax = 0;
	figure.ymax = 0;
	figure.letter = 'A' + index;
	str_chunk = ft_strsub(str, index * 21, 20);
	while (i < 4)
	{
		(figure.points)[i] = initialize_point(str_chunk, i);
		i++;
	}
	pfigure = &figure;
	correct_points(pfigure);
	return (figure);
}
