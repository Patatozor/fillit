/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:06:22 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 04:48:28 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_shapes(char *str)
{
	size_t	len;
	int		count;

	len = ft_strlen(str);
	count = len / 21 + 1;
	if (count > 0 && count < 27)
		return (count);
	else
		return (0);
}

int	get_nb_tetrimino(char *str)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}
