/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:04:52 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/16 23:00:31 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Function checks if all string elements are just '.' || '#' || '\n'
 */

int		wrong_symbols(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

/*
 * Function checks if Tetrimino is = 4 symbols wide (before \n)
 */

int		len_4_symbols(char *str)
{
	int i;
	int symbol_count;
	
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

/*
 * Function checks if Tetrimino is = 4 lines long
 */

// doesn't work

int height_4_lines(char *str)
{
	int i;
	int line_count;

	i = 0;
	line_count = 0;
	if (str[0] != '.' && str[0] != '#')
		return (0);
	while (str[i] && str[i + 1]) 
	{
		line_count = 0;
		while (str[i] != '\n' && str[i - 1] != '\n')
		{
			while (str[i] != '\n')
				i++;
			if (str[i] == '\n' && str[i - 1] != '\n')
			{
				line_count++;
				i++;
			}
		}
		if (line_count != 4)
			return (0);
		if (str[i] == '\n')
			i++;
	}
	return (1);
}

//int gap_between_figures(char *str);