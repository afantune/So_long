/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:09:15 by afantune          #+#    #+#             */
/*   Updated: 2025/03/31 13:29:54 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	nullifier(t_vars *vars)
{
	vars->wall = NULL;
	vars->base = NULL;
	vars->player = NULL;
	vars->exit = NULL;
	vars->food = NULL;
}

int	c_check(int c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || c == '\n')
		return (1);
	else
		return (0);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
}
