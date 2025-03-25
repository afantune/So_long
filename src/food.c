/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:47:37 by afantune          #+#    #+#             */
/*   Updated: 2025/03/25 16:03:10 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_food(t_vars *vars, t_animation *food)
{
	static int	i;
	char		*path;

	path = NULL;
	while (i != -1)
	{
		path = get_texture_path("./textures/food/food", i, ".xpm", path);
		if (path == NULL)
			i = -1;
		else
		{
			add_animation_frames(vars, path, food);
			i++;
		}
	}
}

void	food_rend(t_vars *vars)
{
	int			i;
	int			j;
	t_animation	*temp;

	i = 0;
	j = 0;
	temp = vars->food;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			if (vars->map->map[i][j] == C)
				mlx_put_image_to_window(vars->mlx, vars->win, temp->img, j
					* vars->wall->width + 10, i * vars->wall->height + 10);
			if (temp->next)
				temp = temp->next;
			else
				temp = vars->food;
			j++;
		}
		j = 0;
		i++;
	}
}

t_box	col_bound(t_vars *vars, int key, int i, int j)
{
	t_box	temp;

	if (key == A || key == D)
	{
		temp.m_min = j * vars->wall->width;
		temp.m_max = temp.m_min + vars->food->width;
		temp.m_bd = vars->player->running->height;
		temp.min = i * vars->wall->height;
		temp.max = temp.min + vars->food->height;
		temp.bd = vars->player->running->width;
	}
	if (key == W || key == S)
	{
		temp.m_min = i * vars->wall->height;
		temp.m_max = temp.m_min + vars->food->height;
		temp.m_bd = vars->player->running->height;
		temp.min = j * vars->wall->width;
		temp.max = temp.min + vars->food->width;
		temp.bd = vars->player->running->width;
	}
	return (temp);
}
