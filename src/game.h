#ifndef GAME_H

# define GAME_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"

# define SPEED	15
# define W	13
# define A	0
# define S	1
# define D	2
# define P 32
# define C 19
# define E 21

typedef struct s_map
{
    int **map;
    int *rc;
} t_map;

typedef struct s_vars
{
    void *mlx;
    void *win;
    void *wall;
    void *base;
    void *p1;
    void *exit;
    void *food;
    int map_width;
    int map_height;
    int **map;
} t_vars;

typedef struct s_map_errs
{
	int	w;
	int	c;
	int	p;
	int	e;
	int	xtra;
}t_map_errs;

typedef struct s_animation
{
	void				*img;
	int					w;
	int					h;
	struct s_animation	*next;
}t_animation;

typedef struct s_player
{
	t_animation	*idle;
	t_animation	*run;
	t_animation	*active;
	int			run_frames;
	int			idle_frames;
	int			x;
	int			y;
	int			move;
	int			move_count;
}t_player;

typedef struct s_movement 
{
    int dx;
    int dy;
} t_movement;

int check_map(int **map, int row, int col);
int set_r_c(int *rc, char *path);
int **map_create(int *rc, int **map, char *path);
void    render_map(t_vars *vars);
void    nullifier(t_vars *vars);
int c_check(int c);
int *fill_row(int fd, int n);
void    handle_error(int error_code, int fd, char *line, char c);
void    free_map(int **map, int rows);
void    free_map_struct(t_map *map);
int validate_map(char *path, int index);
void    check_map_errors(int *rc, int **map);
void    free_animation(t_animation *anim, t_vars *vars);
void    free_player(t_player *p, t_vars *vars);
void	free_vars(t_vars *vars);
int	quit(t_vars *vars);
int	events(int keycode, t_vars *vars);
int	callbacks(t_vars *vars);
int	on_release(int keycode, t_vars *vars);
int	game_start(int **mat, int *rc);
void    game_checks(t_vars *vars);
t_movement  get_movement_direction(int keycode);
int can_move(t_player *p1, t_vars *vars, int new_x, int new_y);
void    update_pos(int keycode, t_player *p1, t_vars *vars);

#endif

