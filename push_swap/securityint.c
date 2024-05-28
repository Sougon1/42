/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   securityint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:01:08 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/28 14:42:48 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

long long	ft_atoll(const char *str)
{
	long long	result;

	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	securityint(char *argv)
{
	long long	i;

	i = ft_atoll(argv);
	if (i > INT_MAX || i < INT_MIN)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (i);
}
