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

void	main_display(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	draw_player(vars);
}
