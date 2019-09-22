int 	check_place (int **map, t_termito *tetramino, int x, int y, int size)
{
	if (map[x + tetramino->cord[2]][y + tetramino->cord[3]] > size ||
		map[x + tetramino->cord[2]][y + tetramino->cord[3]] < size ||
		map[x + tetramino->cord[4]][y + tetramino->cord[5]] > size ||
		map[x + tetramino->cord[4]][y + tetramino->cord[5]] < size ||
		map[x + tetramino->cord[6]][y + tetramino->cord[7]] > size ||
		map[x + tetramino->cord[6]][y + tetramino->cord[7]] < size)
		return (0);
	if (map[x + tetramino->cord[2]][y + tetramino->cord[3]] != 0 ||
		map[x + tetramino->cord[4]][y + tetramino->cord[5]] != 0 ||
		map[x + tetramino->cord[6]][y + tetramino->cord[7]] != 0)
		return (0);
	return (1);
}

void 	tetramino_set(int **map, t_termito *tetramino, int x, int y)
{
	map[x][y] = tetramino->letter;
	map[x + tetramino->cord[2]][y + tetramino->cord[3]] = tetramino->letter;
	map[x + tetramino->cord[4]][y + tetramino->cord[5]] = tetramino->letter;
	map[x + tetramino->cord[6]][y + tetramino->cord[7]] = tetramino->letter;
}

void	tetramino_unset(int **map, t_termito *tetramino, int x, int y)
{
	map[x][y] = 0;
	map[x + tetramino->cord[2]][y + tetramino->cord[3]] = 0;
	map[x + tetramino->cord[4]][y + tetramino->cord[5]] = 0;
	map[x + tetramino->cord[6]][y + tetramino->cord[7]] = 0;
}