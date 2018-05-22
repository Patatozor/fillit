/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:18:21 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/22 22:26:20 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ret_file_string(char *filename)
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

int		get_nb_tetrimino(char *str)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

// char **read_to_array(char *filename)
// {
// 	char *str;
// 	char **array;

// 	str = ret_file_string(filename);
// 	array = ft_strsplit(str, '\n');
// 	return(array);
// }

char **get_one_tetrimino(char **str)
{
	static int i = -4;

	i = i + 4;
	if (str[i])
		return (str + i);
	return (0);
}

//t_tetrimino	*arrange_array(t_tetrimino *start)

t_coordinate min_coordinate(char **str)
{
	int i;
	int j;
	t_coordinate coord;

	i = 0;
	coord.x = 4;
	coord.y = 4;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i][j] == '#')
			{
				coord.x = j < coord.x ? j : coord.x;
				coord.y = i < coord.y ? i : coord.y;
			}
			j++;
		}
		i++;
	}
	printf("(%d; %d)\n", coord.x, coord.y); // !!!!!!!!!!!!!!!!!!!!!!!
	return (coord);
}

// int min_coordinate_i(char **str)
// {
// 	int i;
// 	int j;
// 	int i_min;

// 	i = 0;
// 	i_min = 10;
// 	while (str[i] && i < 4)
// 	{
// 		j = 0;
// 		while (str[i][j])
// 		{
// 			if (str[i][j] == '#' && i < i_min)
// 			{
// 				i_min = i;
// 				printf("(i_min = %d)\n", i_min); // !!!!!!!!!!!!!!
// 				return (i_min);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (i_min);
// }

void move_upper_left(char **str)
{
	int i;
	int j;
	t_coordinate coord;

	coord = min_coordinate(str);
	i = 0;
	while (coord.y + i < 4)
	{
		j = -1;
		while (coord.x + ++j < 4)
			str[i][j] = str[coord.y + i][coord.x + j];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i >= 4 - coord.y || j >= 4 - coord.x)
				str[i][j] = '.';
		}
		i++;
	}
}

t_tetrimino *parse(char *str)
{
	t_tetrimino *ttr;
	int nb_ttr;
	char **array;
	int i;

	nb_ttr = get_nb_tetrimino(str);
	ttr = malloc(sizeof(t_tetrimino) * (nb_ttr + 1));
	i = 0;
	array = ft_strsplit(str, '\n');
	while (i < nb_ttr)
	{
		ttr[i].tetrimino = get_one_tetrimino(array);
		move_upper_left(ttr[i].tetrimino);
		ttr[i].letter = i + 'A';
		ttr[i].height = 0; // ALARM! TODO!
		ttr[i].width = 0; // ALARM! TODO!
		i++;
	}
	return (ttr);
}



int	main(int argc, char **argv)
{
	char	**file;
	char	**one_tetrimino;
	int i;

	i = 0;

	if (argc != 2)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	// file = read_to_array(argv[1]);
	// one_tetrimino = get_one_tetrimino(file);

	// move_upper_left(one_tetrimino, min_coordinate_i(one_tetrimino), min_coordinate_j(one_tetrimino));



	// while (one_tetrimino)
	// {
	// 	while (i < 4)
	// 	{
	// 		printf("%s\n", one_tetrimino[i]);
	// 		i++;
	// 	}
	// 	if (!one_tetrimino[i])
	// 		return (0);
	// 	one_tetrimino = get_one_tetrimino(file);
	// move_upper_left(one_tetrimino, min_coordinate_i(one_tetrimino), min_coordinate_j(one_tetrimino));
	// 	printf("\n");
	// 	// min_coordinate_i(one_tetrimino);
	// 	// min_coordinate_j(one_tetrimino);
	// 	i = 0;
	// }

	return (0);
}
