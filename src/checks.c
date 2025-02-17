#include "game.h"

void    game_checks(t_vars *vars)
{
    int i;
    int j;
    int c;

    c = 0;
    i = 0;
    j = 0;
    while (i < vars->map->rc[0])
    {
        while (j < vars->map->rc[1])
        {
            if (vars->map->map[i][j] == 'C')
                c++;
            j++;
        }
        j = 0;
        i++;
    }
    if (c == 0)
    {
        vars->exit->exit = 1;
    }
}

