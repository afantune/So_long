/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:09:37 by afantune          #+#    #+#             */
/*   Updated: 2025/03/25 15:13:17 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define SPEED 15
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define P 32
# define C 19
# define E 21

typedef struct s_map
{
	int	**map;
	int	*rc;
}	t_map;

typedef struct s_animation
{
	void				*img;
	int					width;
	int					height;
	struct s_animation	*next;
}	t_animation;

typedef struct s_player
{
	t_animation	*idle;
	t_animation	*running;
	t_animation	*active;
	int			run_frames;
	int			idle_frames;
	int			x;
	int			y;
	int			move;
	int			move_count;
}	t_player;

typedef struct s_portal
{
	t_animation	*disabled;
	t_animation	*enabled;
	t_animation	*active;
	int			exit_dis_frame;
	int			exit_en_frame;
	int			x;
	int			y;
	int			exit;
}	t_portal;

typedef struct s_box
{
	int	pv;
	int	pc;
	int	m_min;
	int	m_max;
	int	m_bd;
	int	bd;
	int	min;
	int	max;
	int	er;
}	t_box;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	int			map_width;
	int			map_height;
	t_animation	*wall;
	t_animation	*food;
	t_animation	*base;
	t_portal	*exit;
	int			end;
}	t_vars;

typedef struct s_map_errs
{
	int	w;
	int	c;
	int	p;
	int	e;
	int	xtra;
}	t_map_errs;

typedef struct s_movement
{
	int	dx;
	int	dy;
}	t_movement;

int			check_map(int **map, int row, int col);
int			set_r_c(int *rc, char *path);
int			**map_create(int *rc, int **map, char *path);
void		render_map(t_vars *vars);
void		nullifier(t_vars *vars);
int			c_check(int c);
int			*fill_row(int fd, int n);
void		handle_error(int error_code, int fd, char *line, char c);
void		free_map(int **map, int rows);
void		free_map_struct(t_map *map);
int			validate_map(char *path, int index);
void		check_map_errors(int *rc, int **map);
void		free_animation(t_animation *anim, t_vars *vars);
void		free_player(t_player *p, t_vars *vars);
void		free_vars(t_vars *vars);
int			quit(t_vars *vars);
int			events(int keycode, t_vars *vars);
int			callbacks(t_vars *vars);
int			on_release(int keycode, t_vars *vars);
void		game_checks(t_vars *vars);
t_movement	get_movement_direction(int keycode);
t_animation	*image(t_animation *sprite, int frame);
int			can_move(t_player *p1, t_vars *vars, int new_x, int new_y);
void		update_pos(int keycode, t_player *p1, t_vars *vars);
int			check_path(int **map, char *path, int *start, int *rc);
void		main_display(t_vars *vars);
void		malloc_errors(t_vars *vars, int **map, int *rc);
void		list_wall(t_vars *vars, t_animation *wall);
void		d_anim_helper(t_vars *vars, void *img, int x, int y);
int			loadplayers(t_vars *vars);
int			start_game(int **map, int *rc);
void		wall_rend(t_vars *vars, int x, int y, int index);
void		wall_set(t_vars *vars);
void		food_rend(t_vars *vars);
void		free_portal(t_portal *p, t_vars *vars);
char		*get_texture_path(char *main, int frame, char *ext, char *path);
void		add_animation_frames(t_vars *vars, char *path, t_animation *sprite);
void		load_exit0(t_vars *vars, t_animation *food);
void		load_exit1(t_vars *vars, t_animation *food);
void		load_player(t_vars *vars);
void		load_player_animations(t_vars *vars);
void		load_food(t_vars *vars, t_animation *food);

#endif