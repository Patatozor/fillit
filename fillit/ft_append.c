/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:03:32 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/11 17:48:17 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_append(char **s1, char *s2)
{
	char	*buf;
	size_t	lens1;
	size_t	lens2;

	if (!*s1)
		buf = ft_strdup(s2);
	else
	{
		lens1 = ft_strlen(*s1);
		lens2 = ft_strlen(s2);
		if (!(buf = malloc(sizeof(char) * (lens1 + lens2 + 1))))
			return (MALLOC_ERROR);
		ft_strncpy(buf, *s1, lens1);
		if (ft_strlcat(buf, s2, lens1 + lens2 + 1) != (lens1 + lens2 + 1))
			return (CAT_ERROR);
	}
	free(*s1);
	*s1 = ft_strdup(buf);
	free(buf);
	free(s2);
	return (1);
}
