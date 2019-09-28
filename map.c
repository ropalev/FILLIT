/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:14:19 by lvania            #+#    #+#             */
/*   Updated: 2019/09/26 14:16:31 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			**map_create(int size)
{
	int		**map;
	int		i;

	i = 0;
	if (!(map = ((int **)malloc(sizeof(int *) * size))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * size)))
		{
			map_del(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int			**map_fill_zero(void)
{
	int		**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = map_create(104);
	while (i < 104)
	{
		j = 0;
		while (j < 104)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void		map_del(int **map)
{
	int		i;

	i = 0;
	while (i < 104)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
