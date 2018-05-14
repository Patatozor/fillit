/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:52:40 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/14 16:27:45 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>


# include "../src/libft/libft.h"
//# define BUFF_SIZE 4096

typedef struct s_tetrimino
{
	char **tetrimino;
	char letter;
	int x;
	int y;
	struct s_tetrimino *next;
}			t_tetrimino;

_Bool tetrimino_is_valid(t_tetrimino *tetrimino);

#endif
