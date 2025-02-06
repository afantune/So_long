#include "game.h"

void	check_map_1(int **map, int row, int col, t_map_errs *err)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((j == 0 || j == col - 1) && map[i][j] != 1)
                err->w = -1;
            if ((i == 0 || i == row - 1) && map[i][j] != 1)
                err->w = -1;
			if (map[i][j] == P)
				err->p++;
			if (map[i][j] == E)
				err->e++;
			if (map[i][j] == C)
				err->c++;
			j++;
		}
		i++;
	}
}

int	check_map(int **map, int row, int col)
{
	t_map_errs	*err;

	err = malloc(sizeof(t_map_errs));
    if (!err)
    {
        perror("Error allocating memory");
        return (0);
    }
	err->w = 0;
	err->c = 0;
	err->p = 0;
	err->e = 0;
	check_map_1(map, row, col, err);
	if (err->w == -1 || err->c == 0 || err->e != 1 || err->p != 1)
	{
		printf("Error: ");
        if (err->w == -1)
            printf("The map is not surrounded by walls.\n");
        else if (err->c == 0)
            printf("The map needs at least one collectible.\n");
        else if (err->e != 1)
            printf("The map requires exactly one exit.\n");
        else if (err->p != 1)
            printf("The map requires exactly one player.\n");
		free(err);
		return (0);
	}
	free(err);
	return (1);
}

int	set_r_c(int *rc, char *path)
{
	char	*temp;
	int		fd;

	fd = open(path, O_RDONLY);
	temp = get_next_line(fd);
	rc[1] = -1;
	rc[0] = 0;
	while (temp != NULL)
	{
		if (rc[1] == -1)
			rc[1] += ft_strlen(temp);
		rc[0]++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	*fill_row(int *row, int fd, int n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(fd);
	while (i < n)
	{
		row[i] = temp[i] - 48;
		i++;
	}
	free(temp);
	return (row);
}

int	**map_create(int *rc, int **map, char *path)
{
	int	i;
	int	fd;

	fd = open(path, O_RDONLY);
	i = 0;
	map = malloc(sizeof(int *) * rc[0]);
    if (!map)
    {
        printf("Memory allocation failed for matrix.\n");
        return (NULL);
    }

	while (i < rc[0])
	{
		map[i] = malloc(sizeof(int) * rc[1]);
		map[i] = fill_row(map[i], fd, rc[1]);
		i++;
	}
	close (fd);
	return (map);
}