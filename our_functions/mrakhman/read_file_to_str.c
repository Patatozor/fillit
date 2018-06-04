/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:26:35 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/30 17:14:29 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfillit.h"

/*
** Function reads from fd all file untill the end
** and stores it in a single string *file_str
*/

char	*read_file_to_string(char *filename)
{
	char	*file_str;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		read_ret;

	if (!(file_str = malloc(sizeof(char))))
		return (NULL);
	file_str[0] = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
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

char **read_file_to_array(char *filename)
{
	char *str;
	char **array;

	str = read_file_to_string(filename);
	array = ft_strsplit(str, '\n');
	return (array);
}
