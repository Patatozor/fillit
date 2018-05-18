/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:53:04 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/18 17:28:16 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char		*str;
	t_figure 	*shapes;

	if (argc != 2)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	str = NULL;
	str = (ret_file_string(argv[1]));
	printf("%s\n", str);
	if ((shapes = store_shapes(str)) == NULL)
		return (0);
	printf("x: %d y: %d\n", (shapes[1]).xmax, (shapes[1]).ymax);
	return (1);

}
