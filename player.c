#include "game.h"

void	load_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->player = malloc(sizeof(t_player));
	if (vars->player == NULL)
		malloc_error(vars, NULL, NULL);
	vars->player->move_count = 0;
	while (i < vars->map->rows)
	{
		while (j < vars->map->cols)
		{
			if (vars->map->matrix[i][j] == PLAYER)
			{
				vars->player->x = j * vars->wall->width;
				vars->player->y = i * vars->wall->height;
			}
			j++;
		}
		j = 0;
		i++;
	}
	vars->player->idle = NULL;
	vars->player->running = NULL;
}

void	load_idle_animation(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = get_texture_path("./textures/player/idle/idle", i, ".xpm", path);
		if (path == NULL)
		{
			vars->player->idle_frames = i;
			break ;
		}
		else
		{
			add_animation_frames(vars, path, sprite);
			i++;
		}
	}
}

void	load_run_animation(t_vars *vars, t_animation *sprite)
{
	static int	i;
	char		*path;

	path = NULL;
	while (1)
	{
		path = get_texture_path("./textures/player/run/run", i, ".xpm", path);
		if (path == NULL)
		{
			vars->player->run_frames = i;
			break ;
		}
		else
		{
			add_animation_frames(vars, path, sprite);
			i++;
		}
	}
}

t_animation	*get_player_sprite(t_vars *vars)
{
	if (vars->player->move == 0)
		return (get_animation_frame(vars->player->idle, vars->player->idle_frames));
	else
		return (get_animation_frame(vars->player->running, vars->player->run_frames));
}

void	load_player_animations(t_vars *vars)
{
	vars->player->idle = malloc(sizeof(t_animation));
	if (vars->player->idle == NULL)
		malloc_error(vars, NULL, NULL);
	vars->player->idle->img = NULL;
	vars->player->idle->next = NULL;
	load_idle_animation(vars, vars->player->idle);
	
	vars->player->running = malloc(sizeof(t_animation));
	if (vars->player->running == NULL)
		malloc_error(vars, NULL, NULL);
	vars->player->running->img = NULL;
	vars->player->running->next = NULL;
	load_run_animation(vars, vars->player->running);
}