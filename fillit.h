/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:45:02 by lvania            #+#    #+#             */
/*   Updated: 2019/09/28 11:47:06 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_shape
{
	char				letter;
	int					coord[8];
	struct s_shape		*next;
}						t_shape;

int						parser(char **file, t_shape **shape);
void					map_del(int **map);
int						check_place(t_shape *tetramino, int x,
									int y, int size);
int						check_place_zero(int **map, t_shape *tetramino,
									int x, int y);
void					tetramino_set(int **map, t_shape *tetramino,
									int x, int y);
void					tetramino_unset(int **map, t_shape *tetramino,
									int x, int y);
int						check_tetramino(char *str, int ret);
int						check_tetramino_valid(char *str, int ret);
void					save_coord(char *tetra, t_shape **shape, int count);
void					move_shape(t_shape **shape);
int						read_shape(char *buf, int ret, t_shape **shape,
									int count);
void					del_list(t_shape **shape);
t_shape					*creat_new_list(void);
int						**map_create(int size);
int						**map_fill_zero(void);
void					map_change_to_letter(int **map, int size);
int						solver(int **map, t_shape *tet, int size);
int						ft_sqrt(int num);
void					print_shape(int **map, int size);
void					finishing_touch(int **map, int size, t_shape *shape);
#endif
