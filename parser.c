//
// Created by Leto Vania on 19/09/2019.
//

#include "libft/libft.h"
#include <stdio.h>



int		check_field(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i % 5 == 4 || i == 20)
		{
			if (str[i] != '\n')
				return (0);
		}
		else
		{
			if (!(str[i] == '.' || str[i] == '#'))
				return (0);
		}
		i++;
	}
	return  (1);
}

int 	check_tetramino(char *str, int ret)
{
	int		i;
	int 	cnt_border;
	int 	cnt_cell;

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

void	parser2(char ** file)
{
	char 	*buf;
	int 	fd;
	int 	ret;

	buf = ft_strnew(21);
	fd = open(*file, O_RDONLY);
	{
		while ((ret = read(fd, buf, 21)) >= 20)
		{
			buf[ret] = '\0';
			if (!(check_tetramino(buf,ret) && check_field(buf)))
				printf("%s\n", "Бракоделы!");
			else
				printf("%s\n", "Валидная фигура");
		}
	}
	free(buf);
	close(fd);
}

