#include "fillit.h"

int		smallest_square_side(int tetrimino_count)
{
	int side_len;

	side_len = 0;
	if (tetrimino_count > 0 && tetrimino_count <= 26)
	{

		while ((side_len * side_len) < (tetrimino_count * 4))
			side_len++;
		return (side_len);
	}
	return (0);
}