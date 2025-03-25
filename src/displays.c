/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:09:23 by afantune          #+#    #+#             */
/*   Updated: 2025/02/17 13:09:24 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	base_rend(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map->rc[0])
	{
		while (j < vars->map->rc[1])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->base->img,
				j * vars->wall->w, i * vars->wall->h);
			j++;
		}
		j = 0;
		i++;
	}
}

void	main_display(t_vars *vars)
{
	wall_set(vars);
	food_rend(vars);
}

void	d_anim_helper(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

t_animation	*image_helper(int frame, t_animation *temp)
{
	int	i;

	i = 0;
	while (i < frame)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

t_animation	*image(t_animation *sprite, int frame)
{
	static int	i;
	t_animation	*temp;

	temp = sprite;
	if (i >= frame - 1)
		i = 0;
	else
		i++;
	return (image_helper(i, temp));
}