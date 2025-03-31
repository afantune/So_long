/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:47:56 by afantune          #+#    #+#             */
/*   Updated: 2025/03/31 13:29:58 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_player(t_vars *vars)
{
	int	i;
	int	j;

	vars->player = malloc(sizeof(t_player));
	if (vars->player == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->player->move = 0;
	vars->player->move_count = 0;
	i = 0;
	while (i < vars->map->rc[0])
	{
		j = 0;
		while (j < vars->map->rc[1])
		{
			if (vars->map->map[i][j] == P)
			{
				vars->player->x = j * vars->wall->width;
				vars->player->y = i * vars->wall->height;
			}
			j++;
		}
		i++;
	}
	vars->player->idle = NULL;
	vars->player->running = NULL;
}

void	load_idle_animation(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = get_texture_path("./textures/Player/idle_r/idle", i, ".xpm",
				path);
		if (path == NULL)
		{
			vars->player->idle_frames = i;
			break ;
		}
		else
		{
			add_animation_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_run_animation(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = get_texture_path("./textures/Player/run_r/run", i, ".xpm", path);
		if (path == NULL)
		{
			vars->player->run_frames = i;
			break ;
		}
		else
		{
			add_animation_frames(vars, path, sprite);
			i++;
		}
	}
}

t_animation	*get_player_sprite(t_vars *vars)
{
	if (vars->player->move == 0)
		return (image(vars->player->idle, vars->player->idle_frames));
	else
		return (image(vars->player->running, vars->player->run_frames));
}

void	load_player_animations(t_vars *vars)
{
	vars->player->idle = malloc(sizeof(t_animation));
	if (vars->player->idle == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->player->idle->img = NULL;
	vars->player->idle->next = NULL;
	load_idle_animation(vars, vars->player->idle);
	vars->player->running = malloc(sizeof(t_animation));
	if (vars->player->running == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->player->running->img = NULL;
	vars->player->running->next = NULL;
	load_run_animation(vars, vars->player->running);
}
