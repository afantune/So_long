/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:08 by afantune          #+#    #+#             */
/*   Updated: 2025/03/27 14:49:57 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	count_collectibles(t_vars *vars, int *collectibles)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map->rc[0])
	{
		j = 0;
		while (j < vars->map->rc[1])
			if (vars->map->map[i][j++] == C)
				(*collectibles)++;
		i++;
	}
}

void	game_checks(t_vars *vars)
{
	int	collectibles;
	int	p_tile[2];
	int	e_tile[2];

	collectibles = 0;
	count_collectibles(vars, &collectibles);
	vars->exit->exit = (collectibles == 0);
	p_tile[0] = vars->player->x / vars->wall->width;
	p_tile[1] = vars->player->y / vars->wall->height;
	e_tile[0] = vars->exit->x / vars->wall->width;
	e_tile[1] = vars->exit->y / vars->wall->height;
	if (p_tile[0] == e_tile[0] && p_tile[1] == e_tile[1] && vars->exit->exit)
	{
		ft_printf("You Win!\n");
		quit(vars);
	}
}

void	validate_path(t_map *map, int i, int j, int *path)
{
	if (i < 0 || j < 0 || i >= map->rc[0] || j >= map->rc[1]
		|| map->map[i][j] == 1)
		return ;
	if (map->map[i][j] == E)
	{
		path[0] = 1;
		return ;
	}
	map->map[i][j] = 1;
	validate_path(map, i - 1, j, path);
	validate_path(map, i + 1, j, path);
	validate_path(map, i, j - 1, path);
	validate_path(map, i, j + 1, path);
}

void	path_checker(char *path, int **map, int *pos, int *rc)
{
	t_map	*temp;
	int		err[1];

	temp = malloc(sizeof(t_map));
	if (!temp)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	temp->map = NULL;
	temp->rc = NULL;
	err[0] = 0;
	temp->map = map_create(rc, map, path);
	temp->rc = rc;
	validate_path(temp, pos[0], pos[1], err);
	if (err[0] != 1)
	{
		printf("No Valid Path\n");
		free_map_struct(temp);
		exit(1);
	}
	free_map_struct(temp);
}

int	check_path(int **map, char *path, int *start, int *rc)
{
	if (start[0] == rc[0] - 1 && start[1] == rc[1] - 1)
		return (map[start[0]][start[1]]);
	if (map[start[0]][start[1]] == C || map[start[0]][start[1]] == P)
		path_checker(path, map, start, rc);
	if (start[1] == rc[1] - 1)
	{
		start[0]++;
		start[1] = 0;
		return (check_path(map, path, start, rc));
	}
	start[1]++;
	return (check_path(map, path, start, rc));
}
