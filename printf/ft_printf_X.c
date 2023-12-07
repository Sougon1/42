/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:39:59 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 13:02:46 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnbr_hexxx(unsigned long long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		count++;
	}
	if (n >= 16)
		ft_putnbr_hexxx(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_printf_xx(unsigned int n)
{
	int		count;

	count = 0;
	count += ft_putnbr_hexxx((unsigned long long)n);
	return (count);
}
