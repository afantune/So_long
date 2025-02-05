/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:39 by afantune          #+#    #+#             */
/*   Updated: 2024/11/12 14:43:42 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_conversion(va_list args)
{
	char	*s;
	int		i;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	i = ft_putstr(s);
	return (i);
}
