/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:33:51 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/28 11:37:30 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_prime(int n)
{
	long long	i;

	i = 2;
	if (n < 2)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (!is_prime(nb))
		nb++;
	return (nb);
}


int main(void) 
{
    printf("%d\n", ft_find_next_prime(2147483500));
    printf("%d\n", ft_find_next_prime(-2));
    return 0;
}

