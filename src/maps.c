/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:32:26 by afantune          #+#    #+#             */
/*   Updated: 2025/03/31 14:18:52 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	handle_error(int error_code, int fd, char *line, char c)
{
	if (error_code == 1)
	{
		printf("Error: Invalid Map \n");
		exit(1);
	}
	if (error_code == 2)
	{
		close(fd);
		printf("Error: Invalid Char found -> '%c' \n", c);
		if (line)
			free(line);
		exit(1);
	}
	if (error_code == 3)
	{
		close(fd);
		printf("Error: Invalid Map \n");
		if (line)
			free(line);
		exit(1);
	}
}

void	free_map(int **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_struct(t_map *map)
{
	if (map)
	{
		free_map(map->map, map->rc[0]);
		free(map);
	}
}

int	validate_map(char *path, int index)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(1, 0, NULL, 0);
	line = get_next_line(fd);
	if (!line)
		handle_error(3, fd, NULL, 0);
	len = ft_strlen(line);
	while (line)
	{
		index = 0;
		while (c_check(line[index]) && index != len)
			index++;
		if (line[index] != '\0')
			handle_error(2, fd, line, line[index]);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int	rc[2];
	int	**map;
	int	start_pos[2];

	map = NULL;
	if (argc != 2)
	{
		printf("Error: Invalid Arguments\n");
		exit(1);
	}
	if (validate_map(argv[1], 0) && set_r_c(rc, argv[1]))
		map = map_create(rc, map, argv[1]);
	start_pos[0] = 0;
	start_pos[1] = 0;
	check_map_errors(rc, map);
	check_path(map, argv[1], start_pos, rc);
	start_game(map, rc);
	return (0);
}
