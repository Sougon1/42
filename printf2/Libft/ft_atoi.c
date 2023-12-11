/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:02 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/03 14:39:07 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	valeur;

	sign = 1;
	valeur = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		valeur = (valeur * 10) + (*nptr - 48);
		nptr++;
	}
	return (valeur * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
	const char *a = "\t\n 	-123456";

	int val = ft_atoi(a);
	int val2 = atoi(a);

	printf("%d\n", val);
	printf("%d\n", val2);
}*/
