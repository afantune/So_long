/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:38:11 by afantune          #+#    #+#             */
/*   Updated: 2024/11/12 14:38:19 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_conversion(va_list args)
{
	void	*p;
	int		i;

	p = va_arg(args, void *);
	i = 0;
	if (p == NULL)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_putnbr_base((unsigned long long)p, "0123456789abcdef");
	return (i);
}
