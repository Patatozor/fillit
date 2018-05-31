/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 20:31:46 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 04:27:58 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main_store(char **str, int count_shapes)
{
	t_figure	*shapes;
	int			side_len;

	if ((shapes = store_shapes(str, count_shapes)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	if ((side_len = smallest_square_side(count_shapes)) == 0)
		return (0);
	return (solve(side_len, &shapes, count_shapes));
}
