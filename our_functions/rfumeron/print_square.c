#include "fillit.h"

void	print_square(char **grid, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			ft_putchar(grid[i][j++]);
		ft_putchar('\n');
	}
}
