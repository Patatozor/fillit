/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:11:24 by mrakhman          #+#    #+#             */
/*   Updated: 2018/06/03 18:11:27 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file_to_str(char *filename)
{
	char	*file_str;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		read_ret;

	file_str = malloc(sizeof(char));
	file_str[0] = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return ("error");
	while ((read_ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = file_str;
		buf[read_ret] = 0;
		file_str = ft_strjoin(file_str, buf);
		free(tmp);
	}
	close(fd);
	return (file_str);
}
