#include "game.h"

void main_display(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    draw_map(vars);
    draw_player(vars);
}