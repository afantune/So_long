/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:10:57 by afantune          #+#    #+#             */
/*   Updated: 2025/03/25 15:10:59 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char	*get_texture_path(char *main, int frame, char *ext, char *path)
{
	int	index0;
	int	index1;
	int	fd;

	path = malloc(ft_strlen(main) + ft_strlen(ext) + 2);
	index0 = 0;
	index1 = 0;
	while (main[index0] != '\0')
		path[index1++] = main[index0++];
	index0 = 0;
	path[index1++] = frame + '0';
	while (ext[index0] != '\0')
		path[index1++] = ext[index0++];
	path[index1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0 && path != NULL)
	{
		free(path);
		return (NULL);
	}
	else
	{
		close(fd);
		return (path);
	}
}

void	add_frame_helper(t_vars *vars, char *path, t_animation *sprite)
{
	t_animation	*temp;

	temp = malloc(sizeof(t_animation));
	if (temp == NULL)
		malloc_errors(vars, NULL, NULL);
	temp->img = mlx_xpm_file_to_image(vars->mlx, path, &temp->width,
			&temp->height);
	temp->next = NULL;
	while (sprite->next)
		sprite = sprite->next;
	sprite->next = temp;
}

void	add_animation_frames(t_vars *vars, char *path, t_animation *sprite)
{
	if (!sprite->img)
		sprite->img = mlx_xpm_file_to_image(vars->mlx, path, &sprite->width,
				&sprite->height);
	else
		add_frame_helper(vars, path, sprite);
	free(path);
}
