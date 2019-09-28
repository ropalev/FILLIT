/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:02:01 by lvania            #+#    #+#             */
/*   Updated: 2019/09/26 20:58:50 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		move_shape(t_shape **shape)
{
	int		i;
	int		y;
	int		j;
	int		x;

	x = (*shape)->coord[0];
	y = (*shape)->coord[1];
	i = 0;
	j = 1;
	while (i < 8)
	{
		(*shape)->coord[j] -= y;
		if ((*shape)->coord[i] < x)
			x = (*shape)->coord[i];
		j += 2;
		i += 2;
	}
	j = 0;
	while (j < 8)
	{
		(*shape)->coord[j] -= x;
		j += 2;
	}
}

void		save_coord(char *tetra, t_shape **shape, int count)
{
	int		tag;
	int		i;

	tag = 1;
	i = 0;
	while (i < 20)
	{
		if (tetra[i] == '\n')
			i++;
		if (tetra[i] == '#')
		{
			(*shape)->coord[tag - 1] = i / 5;
			(*shape)->coord[tag] = i % 5;
			tag += 2;
		}
		i++;
	}
	(*shape)->letter = 'A' + count;
}

int			check_tetramino(char *str, int ret)
{
	int		tag;
	int		i;

	i = 0;
	tag = 0;
	while (i < 21)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '.' || str[i] == '#') && i != 20)
				return (0);
			if (str[i] == '#' && ++tag > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
		if (ret == 21 && str[20] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int			check_tetramino_valid(char *str, int ret)
{
	int		i;
	int		cnt_border;
	int		cnt_cell;

	i = -1;
	cnt_border = 0;
	cnt_cell = 0;
	if (ret < 20)
		return (0);
	while (++i < ret)
	{
		if (str[i] == '#')
		{
			if ((i - 1) >= 0 && str[i - 1] == '#')
				cnt_border++;
			if ((i + 1) < 20 && str[i + 1] == '#')
				cnt_border++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				cnt_border++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				cnt_border++;
			cnt_cell++;
		}
	}
	return ((cnt_border == 6 || cnt_border == 8) && cnt_cell == 4);
}

int			parser(char **file, t_shape **shape)
{
	char	*buf;
	int		fd;
	int		ret;
	int		count;
	int		prev;

	count = 0;
	buf = (char*)malloc(sizeof(char) * 21);
	fd = open(*file, O_RDONLY);
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		buf[ret] = '\0';
		if (!read_shape(buf, ret, shape, count))
		{
			del_list(shape);
			return (0);
		}
		count++;
		prev = ret;
	}
	free(buf);
	close(fd);
	if (prev != 20)
		count = 0;
	return (count);
}
