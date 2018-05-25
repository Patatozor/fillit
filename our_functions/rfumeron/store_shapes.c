/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:07:57 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/25 02:31:19 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_figure	*store_shapes(char **str, int count_shapes)
{
	int			i;
	char		*str_chunk;
	t_figure	*shapes_table;

	i = 0;
	if (!(shapes_table = malloc(sizeof(t_figure) * shapes)))
		return (NULL);
	while (i < shapes)
	{
		str_chunk = ft_strsub(str, i * 21, 20);
		if (!tetrimino_has_4_points(str_chunk))
			return (NULL);
		shapes_table[i] = initialize_figure(str_chunk, i);
		free(str_chunk);
		if (!tetrimino_is_valid(&(shapes_table[i])))
			return (NULL);
		i++;
	}
	return (shapes_table);
}
