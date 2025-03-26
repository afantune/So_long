/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:48:05 by afantune          #+#    #+#             */
/*   Updated: 2025/03/26 13:19:58 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_wall(t_vars *vars)
{
	vars->wall = malloc(sizeof(t_animation));
	if (vars->wall == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->wall->img = NULL;
	vars->wall->next = NULL;
	list_wall(vars, vars->wall);
}

void	load_base(t_vars *vars)
{
	vars->base = malloc(sizeof(t_animation));
	if (vars->base == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->base->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/Walls/base.xpm", &vars->base->width,
			&vars->base->height);
	vars->base->next = NULL;
}

void	load_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->exit = malloc(sizeof(t_portal));
	if (vars->exit == NULL)
		malloc_errors(vars, NULL, NULL);
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->map[i][j] == E)
			{
				vars->exit->x = j * vars->wall->width;
				vars->exit->y = i * vars->wall->height;
			}
			j++;
		}
		j = 0;
		i++;
	}
	vars->exit->exit = 0;
	vars->exit->enabled = NULL;
	vars->exit->disabled = NULL;
}

void	load_exit_en_dis(t_vars *vars)
{
	vars->exit->disabled = malloc(sizeof(t_animation));
	if (vars->exit->disabled == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->exit->disabled->img = NULL;
	vars->exit->disabled->next = NULL;
	load_exit0(vars, vars->exit->disabled);
	vars->exit->enabled = malloc(sizeof(t_animation));
	if (vars->exit->enabled == NULL)
		malloc_errors(vars, NULL, NULL);
	vars->exit->enabled->img = NULL;
	vars->exit->enabled->next = NULL;
	load_exit1(vars, vars->exit->enabled);
}

int	loadplayers(t_vars *vars)
{
	if (!vars->base)
		load_base(vars);
	if (!vars->wall)
		load_wall(vars);
	if (!vars->player)
		load_player(vars);
	if (!vars->exit)
		load_exit(vars);
	if (!vars->player->idle && !vars->player->running)
		load_player_animations(vars);
	if (!vars->food)
	{
		vars->food = malloc(sizeof(t_animation));
		if (vars->food == NULL)
			malloc_errors(vars, NULL, NULL);
		vars->food->img = NULL;
		vars->food->next = NULL;
		load_food(vars, vars->food);
	}
	if (!vars->exit->enabled && !vars->exit->disabled)
		load_exit_en_dis(vars);
	return (0);
}
