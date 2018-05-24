/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:07:57 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/24 20:38:17 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_figure	*store_shapes(char *str, int count_shapes)
{
	int			i;
	t_figure	*shapes_table;

	i = 0;
	if (!(shapes_table = malloc(sizeof(t_figure) * shapes)))
		return (NULL);
	while (i < shapes)
	{
		shapes_table[i] = initialize_figure(str, i);
		if (!tetrimino_is_valid(&(shapes_table[i])))
			return (NULL);
		i++;
	}
	return (shapes_table);
}
