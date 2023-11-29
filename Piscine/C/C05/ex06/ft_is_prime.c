/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:22:54 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/28 11:37:12 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	long long	i;

	i = 2;
	if (nb < 2)
		return (0);
	while ((i * i) <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
int main(void)
{
	printf("%d\n", ft_is_prime(22091));//oui
	printf("%d\n", ft_is_prime(13)); 
}
*/
