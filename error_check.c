/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:04:52 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/30 19:33:06 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	wrong_symbols(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int	len_4_symbols(char *str)
{
	int	i;
	int	symbol_count;

	i = 0;
	while (str[i] && str[i + 1])
	{
		symbol_count = 0;
		while (str[i] != '\n')
		{
			symbol_count++;
			i++;
		}
		if (symbol_count != 4)
			return (0);
		while (str[i] == '\n')
			i++;
	}
	return (1);
}

int	height_4_lines(char *str)
{
	int		i;
	int		j;
	int		nb_tetri;
	int		line_count;
	char	*one_tetri;

	nb_tetri = get_nb_tetrimino(str);
	i = 0;
	while (i < nb_tetri)
	{
		one_tetri = ft_strsub(str, i * 21, 20);
		line_count = 0;
		j = 0;
		while (one_tetri[j])
		{
			if (one_tetri[j] == '\n')
				line_count++;
			j++;
		}
		if (line_count != 4)
			return (0);
		i++;
	}
	return (1);
}

int	gap_between_figures(char *str)
{
	int		i;
	int		nb_tetri;
	char	*one_tetri;

	nb_tetri = get_nb_tetrimino(str);
	i = 0;
	while (i < nb_tetri)
	{
		one_tetri = ft_strsub(str, i * 21, 21);
		if (one_tetri[20] != '\n' && one_tetri[20] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	error_check(char *str)
{
	if (wrong_symbols(str) == 0)
		return (0);
	if (len_4_symbols(str) == 0)
		return (0);
	if (height_4_lines(str) == 0)
		return (0);
	if (gap_between_figures(str) == 0)
		return (0);
	return (1);
}
