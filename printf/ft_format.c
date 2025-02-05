/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:09:57 by afantune          #+#    #+#             */
/*   Updated: 2024/11/14 12:53:01 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_char_conversion(args));
	else if (specifier == 's')
		return (ft_string_conversion(args));
	else if (specifier == 'p')
		return (ft_pointer_conversion(args));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_int_conversion(args));
	else if (specifier == 'u')
		return (ft_unsigned_conversion(args));
	else if (specifier == 'x')
		return (ft_lowerhex_conversion(args));
	else if (specifier == 'X')
		return (ft_upperhex_conversion(args));
	else if (specifier == '%')
		return (ft_percent_conversion());
	return (1);
}
