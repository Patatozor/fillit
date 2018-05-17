/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:03:02 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/17 20:44:00 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	str = NULL;
	str = (ret_file_string(argv[1]));
	printf("%s\n", str);
// printf("%d\n", smallest_square_side(27));
	printf("wrong_symbols: \t\t%d\n", wrong_symbols(str));
	printf("len_4_symbols: \t\t%d\n", len_4_symbols(str));
	printf("height_4_lines: \t%d\n", height_4_lines(str));
	printf("gap_between_figures: \t%d\n", gap_between_figures(str));
	return (0);
}
