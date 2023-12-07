/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:49 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 11:34:54 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_u(unsigned int n)
{
	int		count;
	char	digit;
	char	buffer[20];
	int		i;

	i = 0;
	count = 0;
	if (n == 0)
	{
		digit = '0';
		return (write(1, &digit, 1));
	}
	while (n > 0)
	{
		buffer[i++] = '0' + n % 10;
		n /= 10;
	}
	while (i-- > 0)
	{
		digit = buffer[i];
		if (write(1, &digit, 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}
