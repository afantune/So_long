/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:45 by afantune          #+#    #+#             */
/*   Updated: 2025/04/08 14:05:39 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	events(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		quit(vars);
	if (keycode == W)
		update_pos(W, vars->player, vars);
	else if (keycode == S)
		update_pos(S, vars->player, vars);
	else if (keycode == A)
		update_pos(A, vars->player, vars);
	else if (keycode == D)
		update_pos(D, vars->player, vars);
	return (0);
}

int	callbacks(t_vars *vars)
{
	game_checks(vars);
	mlx_clear_window(vars->mlx, vars->win);
	main_display(vars);
	if (vars->exit->exit == 0)
		vars->exit->active = vars->exit->disabled;
	else
		vars->exit->active = vars->exit->enabled;
	if (vars->player->move == 0)
		vars->player->active = vars->player->idle;
	else
		vars->player->active = vars->player->running;
	d_anim_helper(vars, vars->exit->active->img, vars->exit->x, vars->exit->y);
	d_anim_helper(vars, vars->player->active->img, vars->player->x,
		vars->player->y);
	mlx_do_sync(vars->mlx);
	if (vars->end == 1)
		quit(vars);
	return (0);
}

int	on_release(int keycode, t_vars *vars)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		vars->player->move = 0;
	return (0);
}

t_vars	*init_game_vars(int **map, int *rc)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	ft_memset(vars, 0, sizeof(t_vars));
	vars->map = malloc(sizeof(t_map));
	if (vars->map == NULL)
	{
		free(vars);
		return (NULL);
	}
	ft_memset(vars->map, 0, sizeof(t_map));
	vars->end = 0;
	vars->map->map = map;
	vars->map->rc = rc;
	return (vars);
}

int	start_game(int **map, int *rc)
{
	static t_vars	*vars;

	vars = init_game_vars(map, rc);
	if (vars == NULL)
		malloc_errors(NULL, map, rc);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		malloc_errors(vars, map, rc);
	vars->win = mlx_new_window(vars->mlx, rc[1] * 60, rc[0] * 60, "so_long");
	if (vars->win == NULL)
		malloc_errors(vars, map, rc);
	mlx_loop_hook(vars->mlx, callbacks, vars);
	mlx_hook(vars->win, 2, 1L << 0, events, vars);
	mlx_hook(vars->win, 3, 1L << 1, on_release, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	loadplayers(vars);
	mlx_loop(vars->mlx);
	quit(vars);
	return (0);
}
