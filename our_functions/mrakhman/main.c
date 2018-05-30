/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:03:02 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/30 19:33:04 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mfillit.h"

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
	str = (read_file_to_str(argv[1]));
	printf("%s\n", str);
// printf("%d\n", smallest_square_side(27));
	// printf("wrong_symbols: \t\t%d\n", wrong_symbols(str));
	// printf("len_4_symbols: \t\t%d\n", len_4_symbols(str));
	// printf("height_4_lines: \t%d\n", height_4_lines(str));
	// printf("gap_between_figures: \t%d\n", gap_between_figures(str));
	printf("error_check: \t%d\n", error_check(str));
	return (0);
}
