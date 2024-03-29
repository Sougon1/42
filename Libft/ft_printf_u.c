/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:49 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/27 15:25:19 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_rec(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n == 0)
		return (0);
	digit = '0' + n % 10;
	count += ft_putnbr_rec(n / 10);
	count += ft_putchar(digit);
	return (count);
}

int	ft_printf_u(unsigned int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	return (ft_putnbr_rec(n));
}
