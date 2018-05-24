/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:53:04 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/24 20:37:46 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		*str;
	int			side_len;
	t_figure 	*shapes;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	str = NULL;
	str = (ret_file_string(argv[1]));
	if ((count_shapes = count_shapes(str) == 0))
	{
		ft_putstr("error\n");
		return (0);
	}
	if ((main_store(&str, count_shapes) == 0))
	{
		ft_putstr("error\n");
		return (0);
	}
	free(str);
	return (1);
}
