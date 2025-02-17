#include "game.h"

void render_map(t_vars *vars)
{
    int x;
    int y;

    y = 0;
    while (y < vars->map_height)
    {
        x = 0;
        while (x < vars->map_width)
        {
            char tile = vars->map[y][x] + 0;
            if (tile == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
            else if (tile == 'P')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->p1, x, y);
            else if (tile == 'C')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->food, x, y);
            else if (tile == 'E')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x, y);
            x++;
        }
        y++;
    }
}
