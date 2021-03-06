/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:50:47 by lvania            #+#    #+#             */
/*   Updated: 2019/09/26 16:43:34 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solver(int **map, t_shape *tet, int size)
{
	int		row;
	int		col;

	row = 0;
	if (tet->next == NULL)
		return (1);
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (check_place(tet, row, col, size) &&
					check_place_zero(map, tet, row, col))
			{
				tetramino_set(map, tet, row, col);
				if (solver(map, tet->next, size))
					return (1);
				tetramino_unset(map, tet, row, col);
			}
			col++;
		}
		row++;
	}
	return (0);
}
