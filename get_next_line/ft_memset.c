/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:47:36 by afantune          #+#    #+#             */
/*   Updated: 2024/10/28 14:57:44 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	p = (unsigned char *)s;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = val;
		i ++;
	}
	return (s);
}
/*
#include <stdio.h>

int main() 
{
    char buffer[50];

    ft_memset(buffer, 'A', sizeof(buffer) - 1);
    buffer[49] = '\0';
    printf("%s\n", buffer);
    ft_memset(buffer, 0, sizeof(buffer));
    printf("%s\n", buffer);
    return 0;
}*/
