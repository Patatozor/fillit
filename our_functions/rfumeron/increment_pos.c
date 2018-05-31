/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 21:40:34 by rfumeron          #+#    #+#             */
/*   Updated: 2018/05/31 18:46:27 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	increment_pos(t_point *p, t_limits *l)
{
	if (p->x + 1 == l->slen && p->y + 1 == l->slen)
		return (0);
	else if (p->x + 1 < l->slen)
	{
		p->x++;
		return (1);
	}
	else
	{
		p->x = 0;
		p->y++;
		return (1);
	}
}
