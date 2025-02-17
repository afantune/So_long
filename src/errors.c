/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:28 by afantune          #+#    #+#             */
/*   Updated: 2025/02/17 13:08:30 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_map_errors(int *rc, int **map)
{
	if (rc[1] == rc[0])
	{
		printf("Map should be rectangle !\n");
		free_map(map, rc[0]);
		exit(1);
	}
	if (!check_map(map, rc[0], rc[1]))
	{
		free_map(map, rc[0]);
		exit(1);
	}
}

void	malloc_errors(t_vars *vars, int **map, int *rc)
{
	printf("Not enough memory to Malloc\n");
	if (map)
		free_map(map, rc[0]);
	free_vars(vars);
	exit(1);
}
