/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:46 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 11:15:16 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned long long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_printf_p(void *ptr)
{
	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (2 + ft_putnbr_hex((unsigned long long)ptr));
}
