/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:17:17 by lvania            #+#    #+#             */
/*   Updated: 2019/09/28 11:46:17 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char *argv[])
{
	t_shape		*shape;
	t_shape		*head_shape;
	int			size;
	int			count;
	int			**map;

	if (argc == 1)
	{
		write(1, "fillit target_name\n", 19);
		return (0);
	}
	shape = creat_new_list();
	head_shape = shape;
	count = parser(&argv[1], &shape);
	if (count == 0 || count > 26)
	{
		write(1, "error\n", 6);
		return (0);
	}
	map = map_fill_zero();
	size = ft_sqrt(count * 4);
	while (!solver(map, head_shape, size))
		size++;
	finishing_touch(map, size, head_shape);
	return (0);
}

void			finishing_touch(int **map, int size, t_shape *shape)
{
	print_shape(map, size);
	del_list(&shape);
	map_del(map);
}
