/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:03:41 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/11 17:48:02 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_readfile(char **s1, char *file)
{
	int		fd;
	int		ret;
	int		err_ret;
	char	*buf;

	err_ret = 0;
	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	if ((fd = open(file, O_RDONLY) == -1))
		return (WRONGFILE);
	while (ret = read(fd, buf, BUF_SIZE))
	{
		err_ret = ft_append(s1, buf);
		if (err_ret == CAT_ERROR || err_ret == MALLOC_ERROR)
			return (err_ret);
	}
	return (1);
}
