//
// Created by Leto Vania on 22/09/2019.
//

#include "fillit.h"
int 		**map_create(int size)
{
	int		**map;
	int		i;

	if (!(map = ((int **)malloc(sizeof(int *) * size))))\
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * size)))
		{
			map_del(map);
			return (NULL);
		}
	}
	return (map);
}

void		map_fill_zero(int **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 104)
	{
		while (j < 104)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void 		map_del(int **map)
{
	int i;

	i = 0;
	while (i < 104)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void 		map_change_to_letter(int **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			map[i][j] = map[i][j] + '0';
			j++;
		}
		i++;
		// может сразу добавить вывод на экран ?
	}
}


