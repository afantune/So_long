#include "game.h"

void	nullifier(t_vars *vars)
{
	vars->wall = NULL;
	vars->base = NULL;
	vars->p1 = NULL;
	vars->exit = NULL;
	vars->food = NULL;
}

int	c_check(int c)
{
	if (c == '1' || c == '0' || c == 'C'
		|| c == 'P' || c == 'E' || c == '\n')
		return (1);
	else
		return (0);
}
