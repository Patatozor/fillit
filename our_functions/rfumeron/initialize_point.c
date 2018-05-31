/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:32:19 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 02:25:22 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
