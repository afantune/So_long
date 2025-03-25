/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:36 by afantune          #+#    #+#             */
/*   Updated: 2025/03/25 12:48:25 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_animation(t_animation *anim, t_vars *vars)
{
	if (anim)
	{
		free_animation(anim->next, vars);
		mlx_destroy_image(vars->mlx, anim->img);
		free(anim);
	}
}

void	free_player(t_player *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->idle, vars);
		free_animation(p->running, vars);
		free(p);
	}
}

void	free_vars(t_vars *vars)
{
	if (vars)
	{
		free_player(vars->player, vars);
		free_portal(vars->exit, vars);
		free_animation(vars->wall, vars);
		free_map_struct(vars->map);
		free_animation(vars->food, vars);
		free_animation(vars->base, vars);
		free(vars);
	}
}
