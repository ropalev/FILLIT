//
// Created by Leto Vania on 20/09/2019.
//

int 	solver(int start_row, int start_col, t_tetromino *tet)
{
	int 	row;
	int		col;
	int 	square_size;
	char	**map;

	while(*tet)
	{
		while (row < square_size) // заменить на start_row
		{
			while (col < square_size) // заменит start_col
			{
				if(put_tetromino(char **map, t_tetromino)) // uf true
					solver(row + 1, col + 1,tet->next);
				remove_tetromino(char **map, t_tetromino);
				col++;
			}
			row++;
		}
		if (!tet->next && size < min_size)
			min_size = size;
	}

}


// для квадрата размером size_square
// для каждой i,j ячейки попробовать установить фигуру
// 		если фигура выходит за границы квадрата или наезжает на другую фигуру сдвинуть фигуру ввправо
//		если не получается сдвинуть вправо сдвинуть вниз
//	повторять пока первая фигура не окажеться в правом верхнем углу
//		если отсутствует площадь куда можно поставить фигуру, увеличение размера квадрата и начать сначала
//