/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:20:19 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/24 20:07:38 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_figure	initialize_figure(char *str, int index)
{
	t_figure	fig;
	t_figure	*pfig;
	int			i;
	char		*str_chunk;

	i = 0;
	fig.xmax = 0;
	fig.ymax = 0;
	fig.letter = 'A' + index;
	str_chunk = ft_strsub(str, index * 21, 20);
	while (i < 4)
	{
		(fig.p)[i] = initialize_point(str_chunk, i);
		i++;
	}
	pfig = &fig;
	correct_points(pfig);
	free(str);
	return (fig);
}
