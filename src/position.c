/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:48:03 by afantune          #+#    #+#             */
/*   Updated: 2025/02/17 13:57:45 by afantune         ###   ########.fr       */
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

int	can_move(t_player *p1, t_vars *vars, int new_x, int new_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = new_x;
	tile_y = new_y;
	(void)p1;
	if (vars->map->map[tile_y][tile_x] == 1)
		return (0);
	if (vars->map->map[tile_y][tile_x] == C)
	{
		vars->map->map[tile_y][tile_x] = -90;
	}
	if (vars->map->map[tile_y][tile_x] == E && vars->exit->exit == 1)
	{
		vars->end = 1;
	}
	ft_printf("%d\n", ++vars->p1->move_count);
	return (1);
}

void	update_pos(int keycode, t_player *p1, t_vars *vars)
{
	t_movement	move;
	int			new_x;
	int			new_y;

	move = get_movement_direction(keycode);
	new_x = p1->x + move.dx;
	new_y = p1->y + move.dy;
	if (can_move(p1, vars, new_x, new_y))
	{
		p1->x = new_x;
		p1->y = new_y;
		p1->move = 1;
		ft_printf("Moves: %d\n", ++p1->move_count);
		mlx_clear_window(vars->mlx, vars->win);
        render_map(vars);
	}
}
