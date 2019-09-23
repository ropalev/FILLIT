//
// Created by Leto Vania on 19/09/2019.
//

#include "libft/libft.h"
#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>

int     main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	t_shape	*shape;
	t_shape	*head;
	shape = creat_new_list();
	head = shape;
	parser(&argv[1], &shape);
	return (0);

}