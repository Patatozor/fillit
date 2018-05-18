/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:07:57 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 15:45:28 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_figure	*store_shapes(char *str)
{
	int			i;
	int			shapes;
	t_figure	*shapes_table;

	i = 0;
	if (!(shapes = count_shapes(str)))
		return (NULL);
	if (!(shapes_table = malloc(sizeof(t_figure) * shapes)))
		return (NULL);
	while (i < shapes)
	{
		shapes_table[i] = initialize_figure(str, i);
		i++;
	}
	return (shapes_table);
}
