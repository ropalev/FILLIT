/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:13:02 by lvania            #+#    #+#             */
/*   Updated: 2019/09/26 14:13:55 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape			*creat_new_list(void)
{
	t_shape		*node;

	if (!(node = (t_shape *)malloc(sizeof(t_shape))))
		return (NULL);
	node->next = NULL;
	return (node);
}

void			del_list(t_shape **shape)
{
	if (*shape && (*shape)->next)
		del_list(&(*shape)->next);
	free(*shape);
	*shape = NULL;
}

int				read_shape(char *buf, int ret, t_shape **shape, int count)
{
	if (check_tetramino(buf, ret) && check_tetramino_valid(buf, ret))
	{
		save_coord(buf, shape, count);
		move_shape(shape);
		(*shape)->next = creat_new_list();
		*shape = (*shape)->next;
	}
	else
		return (0);
	return (1);
}
