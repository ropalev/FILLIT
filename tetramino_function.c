/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:53:14 by lvania            #+#    #+#             */
/*   Updated: 2019/09/26 14:54:43 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_place(t_shape *tetramino, int x, int y, int size)
{
	if (x + tetramino->coord[0] >= size || y + tetramino->coord[1] >= size ||
		x + tetramino->coord[0] < 0 || y + tetramino->coord[1] < 0 ||
		x + tetramino->coord[2] >= size || y + tetramino->coord[3] >= size ||
		x + tetramino->coord[2] < 0 || y + tetramino->coord[3] < 0 ||
		x + tetramino->coord[4] >= size || y + tetramino->coord[5] >= size ||
		x + tetramino->coord[4] < 0 || y + tetramino->coord[5] < 0 ||
		x + tetramino->coord[6] >= size || y + tetramino->coord[7] >= size ||
		x + tetramino->coord[6] < 0 || y + tetramino->coord[7] < 0)
		return (0);
	return (1);
}

int		check_place_zero(int **map, t_shape *tetramino, int x, int y)
{
	if (map[x + tetramino->coord[0]][y + tetramino->coord[1]] != 0 ||
		map[x + tetramino->coord[2]][y + tetramino->coord[3]] != 0 ||
		map[x + tetramino->coord[4]][y + tetramino->coord[5]] != 0 ||
		map[x + tetramino->coord[6]][y + tetramino->coord[7]] != 0)
		return (0);
	return (1);
}

void	tetramino_set(int **map, t_shape *tetramino, int x, int y)
{
	map[x + tetramino->coord[0]][y + tetramino->coord[1]] = tetramino->letter;
	map[x + tetramino->coord[2]][y + tetramino->coord[3]] = tetramino->letter;
	map[x + tetramino->coord[4]][y + tetramino->coord[5]] = tetramino->letter;
	map[x + tetramino->coord[6]][y + tetramino->coord[7]] = tetramino->letter;
}

void	tetramino_unset(int **map, t_shape *tetramino, int x, int y)
{
	map[x + tetramino->coord[0]][y + tetramino->coord[1]] = 0;
	map[x + tetramino->coord[2]][y + tetramino->coord[3]] = 0;
	map[x + tetramino->coord[4]][y + tetramino->coord[5]] = 0;
	map[x + tetramino->coord[6]][y + tetramino->coord[7]] = 0;
}
