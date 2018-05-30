/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:18:21 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/30 19:34:01 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfillit.h"
#include <stdio.h>

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

// 	str = read_file_to_str(filename);
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

t_coordinate min_coordinate(char **tetrimino)
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
			if (tetrimino[i][j] == '#')
			{
				coord.y = j < coord.y ? j : coord.y;
				coord.x = i < coord.x ? i : coord.x;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

void move_upper_left(char **tetrimino)
{
	int i;
	int j;
	t_coordinate coord;

	coord = min_coordinate(tetrimino);
	i = 0;
	while (coord.x + i < 4)
	{
		j = -1;
		while (coord.y + ++j < 4)
			tetrimino[i][j] = tetrimino[coord.x + i][coord.y + j];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i >= 4 - coord.x || j >= 4 - coord.y)
				tetrimino[i][j] = '.';
		}
		i++;
	}
}

int get_width(char **tetrimino)
{
	int i;
	int j;
	int max_j;
	int width;

	i = 0;
	width = 0;
	while (i < 4)
	{
		j = 0;
		max_j = 0;
		while (j < 4)
		{
			if (tetrimino[i][j] == '#')
				max_j++;
			j++;
		}
		width = max_j > width ? max_j : width;
		i++;
	}
	return (width);
}

int get_heith(char **tetrimino)
{
	int i;
	int j;
	int heith;

	i = 0;
	heith = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino[i][j] == '#')
			{
				heith++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (heith);
}

t_tetrimino *parse_file(char *str)
{
	t_tetrimino *ttr;
	int nb_ttr;
	char **array;
	int i;
	int ii; // delete 1

	nb_ttr = get_nb_tetrimino(str);
	ttr = malloc(sizeof(t_tetrimino) * (nb_ttr + 1));
	i = 0;
	array = ft_strsplit(str, '\n');
	while (i < nb_ttr)
	{
		ttr[i].tetrimino = get_one_tetrimino(array);
		ii = 0; // delete 2
		while (ii < 4) // delete 3
	 	{ // delete
			printf("%s\n", ttr[i].tetrimino[ii]); // delete 4
	 		ii++; // delete 5
	 	} // delete 6
		move_upper_left(ttr[i].tetrimino);
		ttr[i].letter = i + 'A';
		ttr[i].height = get_heith(ttr[i].tetrimino);
		ttr[i].width = get_width(ttr[i].tetrimino);
		printf("%c | (%d by %d)\n", ttr[i].letter, ttr[i].height, ttr[i].width); // delete 7
		ii = 0; // delete 8
		while (ii < 4) // delete 9
	 	{ // delete
			printf("%s\n", ttr[i].tetrimino[ii]); // delete 10
	 		ii++; // delete 11
	 	} // delete 12
	 	printf("\n"); // delete 13
		i++;
	}
	return (ttr);
}



int	main(int argc, char **argv)
{
	char 	*file_str;
	t_tetrimino *array_file;
	int i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	file_str = read_file_to_str(argv[1]);
	array_file = parse_file(file_str);


	return (0);
}
