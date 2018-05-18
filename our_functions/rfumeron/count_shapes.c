/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:06:22 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/18 14:43:06 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fillit.h"

int	count_shapes(char *str)
{
	size_t	len;
	int		count;

	len = ft_strlen(str);
	count = len / 21 + 1;
	if (count > 0 && count < 27)
		return (count);
	else
		return (0);
}
