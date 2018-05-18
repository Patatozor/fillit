/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:32:19 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 11:59:09 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_point	*initialize_point(char *str, int index)
{
	int		i;
	int		j;
	t_point	point;

	i = 0;
	j = 0;
	point.x = 4;
	point.y = 4;
	while (i < 20 && str[i])
	{
		if (str[i] == '#')
		{
			if (j == index)
			{
				point.x = i % 5;
				point.y = i / 5;
				return (point);
			}
			j++;
		}
		i++;
	}
	return (point);
}
