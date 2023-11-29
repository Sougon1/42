/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:30:49 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/26 17:31:26 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	a;

	a = nb - 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (a > 0)
	{
		nb *= a;
		a--;
	}
	return (nb);
}
/*
int	main(void)
{
	int nb = 5;

	printf("%d \n", ft_iterative_factorial(nb));
}*/
