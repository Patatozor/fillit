/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:11:32 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 12:18:49 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

t_point	*initialize_field(int sqr_len)
{
	t_pointa	*game_field;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if (!(game_fied = malloc(sizeof(t_point) * (sqr_len * sqr_len))))
		return (NULL);
	while (x < (sqr_len * sqr_len))
	{
		(game_field[i])
	}
}
