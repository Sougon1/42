/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:38 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/27 15:25:27 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_recursive(long long n)
{
	int		count;
	char	digit;

	count = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_recursive(n / 10);
	digit = '0' + n % 10;
	if (ft_putchar(digit) == -1)
		return (-1);
	return (count + 1);
}

int	ft_printf_i(int n)
{
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	return (ft_putnbr_recursive(n));
}
