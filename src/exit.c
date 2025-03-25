/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:10:37 by afantune          #+#    #+#             */
/*   Updated: 2025/03/25 15:10:38 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_exit0(t_vars *vars, t_animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = get_texture_path("./textures/exit/exit0/exit", i, ".xpm", path);
		if (path == NULL)
		{
			vars->exit->exit_dis_frame = i;
			break ;
		}
		else
		{
			add_animation_frames(vars, path, food);
			i++;
		}
	}
}

void	load_exit1(t_vars *vars, t_animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = get_texture_path("./textures/exit/exit1/exit", i, ".xpm", path);
		if (path == NULL)
		{
			vars->exit->exit_en_frame = i;
			break ;
		}
		else
		{
			add_animation_frames(vars, path, food);
			i++;
		}
	}
}

t_animation	*exit_img(t_vars *vars)
{
	if (vars->exit->exit == 0)
		return (image(vars->exit->disabled, vars->exit->exit_dis_frame));
	else
		return (image(vars->exit->enabled, vars->exit->exit_en_frame));
}

t_box	exit_bound(t_vars *vars, int key, int i, int j)
{
	t_box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->width;
		temp.m_max = temp.m_min + vars->exit->enabled->width;
		temp.m_bd = vars->player->running->height;
		temp.min = i * vars->wall->height;
		temp.max = temp.min + vars->exit->enabled->height;
		temp.bd = vars->player->running->width;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->height;
		temp.m_max = temp.m_min + vars->exit->enabled->height;
		temp.m_bd = vars->player->running->height;
		temp.min = j * vars->wall->width;
		temp.max = temp.min + vars->exit->enabled->width;
		temp.bd = vars->player->running->width;
	}
	return (temp);
}

void	free_portal(t_portal *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->disabled, vars);
		free_animation(p->enabled, vars);
		free(p);
	}
}
