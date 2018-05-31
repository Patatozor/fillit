/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:53:04 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/31 17:42:04 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		*str;
	int			countshapes;

	if (argc != 2)
		return (display_error(0));
	str = (read_file_to_str(argv[1]));
	if (str == NULL)
		return (display_error(0));
	countshapes = count_shapes(str);
	if (countshapes == 0)
	{
		free(str);
		return (display_error(0));
	}
	if ((main_store(&str, countshapes) == 0))
	{
		free(str);
		return (display_error(0));
	}
	return (1);
}