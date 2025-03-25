/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:56 by afantune          #+#    #+#             */
/*   Updated: 2025/03/25 12:10:16 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_map(t_vars *vars)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			tile = vars->map->map[y][x] + 0;
			if (tile == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
			else if (tile == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player, x,
					y);
			else if (tile == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->food, x, y);
			else if (tile == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x, y);
			x++;
		}
		y++;
	}
}
