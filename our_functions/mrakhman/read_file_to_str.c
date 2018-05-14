/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:26:35 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/14 18:26:43 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

char		*ret_file(int argc, char **argv)
{
	int		result;
	char 	*file;
	char	*line;
	int		fd;

	result = 1;
	file = NULL;

	if (argc == 1)
		fd = open(argv[1], O_RDONLY);
	//check on open

		result = get_next_line(fd, &file);



	while (result > 0)
	{
		result = ft_strjoin(get_next_line(fd, &line));
		ft_strjoin(line)

	}

	return (0);
}
