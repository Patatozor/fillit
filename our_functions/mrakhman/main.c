/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:03:02 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/16 22:40:30 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(int argc, char **argv)
{
	char *str;
	str = NULL;
	// printf("%s\n", ret_file_string(argv[1]));
	// printf("%d\n", smallest_square_side(27));
	str = (ret_file_string(argv[1]));
	printf("%s\n", str);
//	printf("%d\n", wrong_symbols(str));
//	printf("%d\n", len_4_symbols(str));
	printf("%d\n", height_4_lines(str));
return (0);
}