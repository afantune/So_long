/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:28 by afantune          #+#    #+#             */
/*   Updated: 2025/04/08 15:14:14 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_map_errors(int *rc, int **map)
{
	if (!check_map(map, rc[0], rc[1]))
	{
		free_map(map, rc[0]);
		exit(1);
	}
}

void	malloc_errors(t_vars *vars, int **map, int *rc)
{
	printf("Error: Not Enough Memory To Malloc\n");
	if (map)
		free_map(map, rc[0]);
	free_vars(vars);
	exit(1);
}
