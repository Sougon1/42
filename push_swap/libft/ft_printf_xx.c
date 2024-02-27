/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:39:59 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/27 15:25:08 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (count);
	}
	if (n >= 16)
		count += ft_putnbr_hexxx(n / 16);
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
