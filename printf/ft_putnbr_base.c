/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:31:53 by afantune          #+#    #+#             */
/*   Updated: 2024/11/12 14:32:19 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	i;
	int	base_len;

	base_len = 0;
	i = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return (0);
	if (n >= (unsigned long)base_len)
	{
		i += ft_putnbr_base(n / base_len, base);
	}
	i += ft_putchar(base[n % base_len]);
	return (i);
}
