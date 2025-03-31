/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:47:47 by afantune          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:03 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wall_set_2(t_vars *vars, int i, int j)
{
	if ((i == 0 && j == 0) || (i == 0 && j == vars->map->rc[1] - 1)
		|| (i == vars->map->rc[0] - 1 && j == 0) || (i == vars->map->rc[0] - 1
			&& j == vars->map->rc[1] - 1))
	{
		wall_rend(vars, j * vars->wall->width, i * vars->wall->height, 0);
	}
	else if (i != 0 && i != vars->map->rc[0] - 1 && (j == 0
			|| j == vars->map->rc[1] - 1))
	{
		wall_rend(vars, j * vars->wall->width, i * vars->wall->height, 2);
	}
	else if ((i == 0 || i == vars->map->rc[0] - 1) && (j != 0
			|| j != vars->map->rc[1] - 1))
	{
		wall_rend(vars, j * vars->wall->width, i * vars->wall->height, 1);
	}
	else
		wall_rend(vars, j * vars->wall->width, i * vars->wall->height, 3);
}

void	wall_set(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->map[i][j] == 1)
				wall_set_2(vars, i, j);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img, j
					* vars->wall->width, i * vars->wall->height);
			j++;
		}
		j = 0;
		i++;
	}
}

t_box	wall_bound(t_vars *vars, int key, int i, int j)
{
	t_box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->width;
		temp.m_max = temp.m_min + vars->wall->width;
		temp.m_bd = vars->player->running->height;
		temp.min = i * vars->wall->height;
		temp.max = temp.min + vars->wall->height;
		temp.bd = vars->player->running->width;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->height;
		temp.m_max = temp.m_min + vars->wall->height;
		temp.m_bd = vars->player->running->height;
		temp.min = j * vars->wall->width;
		temp.max = temp.min + vars->wall->width;
		temp.bd = vars->player->running->width;
	}
	return (temp);
}

void	list_wall(t_vars *vars, t_animation *wall)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = get_texture_path("./textures/Walls/wall", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_animation_frames(vars, path, wall);
			i++;
		}
	}
}

void	wall_rend(t_vars *vars, int x, int y, int index)
{
	int			i;
	t_animation	*temp;

	i = 0;
	temp = vars->wall;
	while (i++ < index)
		temp = temp->next;
	mlx_put_image_to_window(vars->mlx, vars->win, temp->img, x, y);
}
