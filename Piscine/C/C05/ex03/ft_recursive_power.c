/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:27:23 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/28 12:50:17 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb *= ft_recursive_power(nb, power - 1));
}

/*
int	main(void)
{
	printf("-3 -3 = %d\n", ft_recursive_power(-3, -3));
	printf("-3 0 = %d\n", ft_recursive_power(-3, 0));
	printf("-3 3 = %d\n", ft_recursive_power(-3, 3));
	printf("0 0 = %d\n", ft_recursive_power(0, 0));
	printf("0 -3 = %d\n", ft_recursive_power(0, -3));
	printf("3 0 = %d\n", ft_recursive_power(3, 0));
	printf("3 3 = %d\n", ft_recursive_power(3, 3));
	printf("3 -3 = %d\n", ft_recursive_power(3, -3));
}
*/
