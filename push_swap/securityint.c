/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   securityint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:01:08 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/03 10:15:34 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// long long	ft_atoll(const char *str)
// {
// 	long long	result;

// 	result = 0;
// 	while (ft_isdigit(*str))
// 	{
// 		result = result * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (result);
// }

long long	ft_atoll(const char *str)
{
	int				i;
	long long int	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	securityint(char *argv)
{
	long long	i;

	argv--;
	if (*argv != '-')
	{
		argv++;
	}
	i = ft_atoll(argv);
	if (i < INT_MIN || i > INT_MAX)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (i);
}
