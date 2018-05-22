/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:18:21 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/22 17:14:29 by mrakhman         ###   ########.fr       */
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

char **read_to_array(char *filename)
{
	char *str;
	char **array;

	str = ret_file_string(filename);
	array = ft_strsplit(str, '\n');
	return(array);
}

char **get_one_tetrimino(char **str)
{
	static int i = -4;

	i = i + 4;
	if (str[i])
		return (str + i);
	return (0);
}

int min_coordinate_j(char **str)
{
	int i;
	int j;
	int j_min;

	i = 0;
	j_min = 10;
	while (str[i] && i < 4)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#' && j < j_min)
			{
				j_min = j;
				break;
			}
			j++;
		}
		i++;
	}
	printf("(j_min = %d)\n", j_min); // !!!!!!!!!!!!!!!!!!!!!!!
	return (j_min);
}

int min_coordinate_i(char **str)
{
	int i;
	int j;
	int i_min;

	i = 0;
	i_min = 10;
	while (str[i] && i < 4)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#' && i < i_min)
			{
				i_min = i;
				printf("(i_min = %d)\n", i_min); // !!!!!!!!!!!!!!
				return (i_min);
			}
			j++;
		}
		i++;
	}
	return (i_min);
}

void swap_dot_and_sharp(char **str, int i_min)
{
	int i;
	int j;
	char *tmp;

	tmp = "11110";
	i = 0;
	j = 0;
	if (i_min > 0)
	{
		while (str[i] && str[i + i_min] && i < 4)
		{
			ft_strcpy(tmp, str[i]);




int	main(int argc, char **argv)
{
	char	**file;
	char	**one_tetrimino;
	int i_min;
	int j_min;
	int i;

	i = 0;

	if (argc != 2)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	file = read_to_array(argv[1]);
	one_tetrimino = get_one_tetrimino(file);
	i_min = min_coordinate_i(one_tetrimino);
	// min_coordinate_j(one_tetrimino);
	swap_dot_and_sharp(one_tetrimino, i_min);



	while (one_tetrimino)
	{
		while (i < 4)
		{
			printf("%s\n", one_tetrimino[i]);
			i++;
		}
		if (!one_tetrimino[i])
			return (0);
		one_tetrimino = get_one_tetrimino(file);
		swap_dot_and_sharp(one_tetrimino, i_min);
		printf("\n");
		// min_coordinate_i(one_tetrimino);
		// min_coordinate_j(one_tetrimino);
		i = 0;
	}
	return (0);
}
