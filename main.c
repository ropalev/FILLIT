//
// Created by Leto Vania on 19/09/2019.
//

#include <stdio.h>
#include "fillit.h"

int     main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    parser2(&argv[1]);
}

#include "libft/libft.h"
#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>
​
void	move_shape(t_shape *shape)
{
	int i;
	int y;
	int j;
	int x;

	x = shape->coord[0];
	y = shape->coord[1];
	i = 0;
	j = 1;
	while (i < 8)
	{
		shape->coord[j] -= y;
		if (shape->coord[i] < x)
			x = shape->coord[i];
		j += 2;
		i += 2;
	}
	j = 0;
	while (j < 8)
	{
		shape->coord[j] -= x;
		j += 2;
	}
}
​
int		save_coord(char *tetra, t_shape *shape)
{
	int		tag;
	int		i;
	​
	tag = 1;
	i = 0;
	while (i < 20)
	{
		if (tetra[i] == '\n')
			i++;
		if (tetra[i] == '#')
		{
			shape->coord[tag - 1] = i % 5;
			shape->coord[tag] = i / 5;
			tag += 2;
		}
		i++;
	}
	return (1);
}
​
int 	check_tetramino(char *str, int ret)
{
	int		i;
	int 	cnt_border;
	int 	cnt_cell;
	​
	i = 0;
	cnt_border = 0;
	cnt_cell = 0;
	while(str[i]) {
		if (str[i] == '#') {
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
		i++;
	}
	if (ret > 19 && str[20] != '\n')
		return (0);
	return ((cnt_border == 6 || cnt_border == 8) && cnt_cell == 4);
}
​
t_shape		*creat_new_list(void)
{
	t_shape		*node;
	​
	if (!(node = (t_shape *)malloc(sizeof(t_shape))))
		return (NULL);
	node->next = NULL;
	return (node);
}
​
void	parser2(char **file)
{
	char 	*buf;
	int 	fd;
	int 	ret;
	t_shape		*shape;
	t_shape		*head;
	​
	shape = creat_new_list();
	head = shape;
	buf = ft_strnew(21);
	fd = open(*file, O_RDONLY);
	{
		while((ret = read(fd, buf, 21)) >= 20)
		{
			buf[ret] = '\0';
			if(!check_tetramino(buf,ret))
				printf("%s\n", "Bracodeli!");
			else
			{
				if (save_coord(buf, shape))
				{
					move_shape(shape);
					shape->next = creat_new_list();
					shape = shape->next;
				}
			}
		}
	}
	char line[22] = {"....\n....\n....\n....\n\n"};
	int l = 0;
	int i = 0;
	while (head)
	{
		l = 0;
		i = 0;
		while (l < 20)
		{
			if (line[l] == '\n')
				l++;
			if (l % 5 == head->coord[i] && l / 5 == head->coord[i+1])
			{
				line[l] = '#';
				i+=2;
			}
			// printf("%d", head->coord[l++]);
			l++;
		}
		printf("%s", line);
		ft_strcpy(line, "....\n....\n....\n....\n\n");
		head = head->next;
	}
	free(buf);
	close(fd);
}
​
int     main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	parser2(&argv[1]);
	return (0);
	​
}