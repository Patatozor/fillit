/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:20:19 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 11:58:25 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_figure	initialize_figure(char *str, int index)
{
	t_figure	figure;
	t_figure	*pfigure;
	t_point		max;
	int			i;
	char		*str_chunk;

	i = 0;
	max.x = 0;
	max.y = 0;
	figure.max = max;
	figure.letter = 'A' + index;
	str_chunk = ft_strsub(str, index * 21, 20);
	while (i < 4)
	{
		figure.points[i] = initialize_point(str_chunk, i);
		i++;
	}
	pfigure = &figure;
	correct_points(pfigure);
	return (figure);
}
