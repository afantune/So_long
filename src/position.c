/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:48:03 by afantune          #+#    #+#             */
/*   Updated: 2025/03/26 13:36:00 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_movement get_movement_direction(int keycode)
{
    t_movement move = {0};
    
    if (keycode == W || keycode == UP)
        move.dy = -SPEED;
    else if (keycode == S || keycode == DOWN)
        move.dy = SPEED;
    else if (keycode == A || keycode == LEFT)
        move.dx = -SPEED;
    else if (keycode == D || keycode == RIGHT)
        move.dx = SPEED;
        
    return move;
}

int	can_move(t_player *s_player, t_vars *vars, int new_x, int new_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = new_x / vars->wall->width;;
	tile_y = new_y / vars->wall->height;
	(void)s_player;
	if (tile_x < 0 || tile_y < 0 || tile_x >= vars->map->rc[1] || tile_y >= vars->map->rc[0])
        return 0;
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
	ft_printf("%d\n", ++vars->player->move_count);
	return (1);
}

void	update_pos(int keycode, t_player *player, t_vars *vars)
{
	t_movement	move;
	int			new_x;
	int			new_y;

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
