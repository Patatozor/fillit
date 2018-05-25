/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:53:04 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/25 02:45:11 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		*str;
	int			side_len;
	t_figure 	*shapes;

	if (argc != 2)
		return (display_error(0));
	str = (ret_file_string(argv[1]));
	if (str == NULL)
		return (display_error(0));
	if ((count_shapes = count_shapes(str) == 0))
	{
		free(str);
		return (display_error(0));
	}
	if ((main_store(&str, count_shapes) == 0))
	{
		free(str);
		return (display_error(0));
	}
	return (1);
}
