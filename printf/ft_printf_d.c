/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:20 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 11:25:37 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_d(int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_printf_d(n / 10);
	digit = '0' + n % 10;
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (count + 1);
}
