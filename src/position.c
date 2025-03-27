/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:48:03 by afantune          #+#    #+#             */
/*   Updated: 2025/03/27 14:37:45 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_movement	get_movement_direction(int keycode)
{
	t_movement	move;

	move.dx = 0;
	move.dy = 0;
	if (keycode == W)
		move.dy = -SPEED;
	else if (keycode == S)
		move.dy = SPEED;
	else if (keycode == A)
		move.dx = -SPEED;
	else if (keycode == D)
		move.dx = SPEED;
	return (move);
}

static int	check_tile_collision(t_vars *vars, int tile_x, int tile_y)
{
	if (tile_x < 0 || tile_y < 0 || tile_x >= vars->map->rc[1]
		|| tile_y >= vars->map->rc[0])
		return (0);
	if (vars->map->map[tile_y][tile_x] == 1)
		return (0);
	return (1);
}

int	can_move(t_player *player, t_vars *vars, int new_x, int new_y)
{
	int	tile_x;
	int	tile_y;

	(void)player;
	tile_x = new_x / vars->wall->width;
	tile_y = new_y / vars->wall->height;
	if (!check_tile_collision(vars, tile_x, tile_y))
		return (0);
	if (vars->map->map[tile_y][tile_x] == C)
		vars->map->map[tile_y][tile_x] = 0;
	if (vars->map->map[tile_y][tile_x] == E && vars->exit->exit == 1)
		vars->end = 1;
	return (1);
}

void	update_pos(int keycode, t_player *player, t_vars *vars)
{
	t_movement	move;
	int			new_x;
	int			new_y;

	if (keycode != W && keycode != A && keycode != S && keycode != D)
		return ;
	move = get_movement_direction(keycode);
	new_x = player->x + move.dx;
	new_y = player->y + move.dy;
	if (can_move(player, vars, new_x, new_y))
	{
		player->x = new_x;
		player->y = new_y;
		player->move = 1;
		ft_printf("Moves: %d\n", ++player->move_count);
		mlx_clear_window(vars->mlx, vars->win);
		render_map(vars);
	}
}
