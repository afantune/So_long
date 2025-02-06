#ifndef GAME_H

# define GAME_H

# include "../mlx/mlx.h"
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
	int	**map;
	int	*rc;
}t_map;

typedef struct s_map_errs{
	int	w;
	int	c;
	int	p;
	int	e;
	int	xtra;
}t_map_errs;


