/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:31:27 by afantune          #+#    #+#             */
/*   Updated: 2024/11/20 14:59:24 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buff[fd][0])
		{
			line = ft_strjoin(line, buff[fd]);
			if (!line)
				return (NULL);
			if (line[ft_strlen(line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buff[fd], BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			buff[fd][bytes_read] = '\0';
		}
	}
	return (line);
}
