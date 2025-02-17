#include "game.h"

t_movement get_movement_direction(int keycode) 
{
    t_movement move = {0, 0};

    if (keycode == W)
        move.dy = -SPEED;
    else if (keycode == S)
        move.dy = SPEED;
    else if (keycode == A)
        move.dx = -SPEED;
    else if (keycode == D)
        move.dx = SPEED;

    return move;
}


int can_move(t_player *p1, t_vars *vars, int new_x, int new_y) 
{
    int tile_x = new_x / TILE_SIZE;
    int tile_y = new_y / TILE_SIZE;

    if (vars->map->mat[tile_y][tile_x] == 1)
        return 0;
    if (vars->map->mat[tile_y][tile_x] == C) {
        vars->map->mat[tile_y][tile_x] = -90;
    }
    if (vars->map->mat[tile_y][tile_x] == E && vars->exit->exit == 1) {
        vars->end = 1;
    }
    return 1;
}

void update_pos(int keycode, t_player *p1, t_vars *vars) 
{
    t_movement move = get_movement_direction(keycode);
    int new_x = p1->x + move.dx;
    int new_y = p1->y + move.dy;

    if (can_move(p1, vars, new_x, new_y)) {
        p1->x = new_x;
        p1->y = new_y;
        p1->move = 1;
        ft_printf("Moves: %d\n", ++p1->move_count);
    }
}
