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

#include "fillit.h"

char		*ret_file_string(char *filename)
{
	char 	*file;
	char	*tmp;
	char	buf[BUFF_SIZE];
	int		fd;
	int		read_ret;

	file = malloc(sizeof(char));
	file[0] = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return ("error");
	while ((read_ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = file;
		file = ft_strjoin(file, buf);
		free(tmp);
	}
	close(fd);
	return (file);
}
