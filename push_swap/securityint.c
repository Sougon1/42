/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   securityint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:01:08 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/28 15:38:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

long long   ft_atoll(const char *str)
{
    long long result;
    int sign;
    
    sign = 1;
    result = 0;
    while (*str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        else
            sign = 1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}

int securityint(char *argv)
{
    long long   i;

    i = ft_atoll(argv);
    if (i >= INT_MAX || i <= INT_MIN)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    return (i);
}
