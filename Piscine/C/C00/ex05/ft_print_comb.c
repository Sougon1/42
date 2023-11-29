/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:52:15 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/10 15:33:29 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(int a, int b, int c)
{
	ft_putchar('0' + a);
	ft_putchar('0' + b);
	ft_putchar('0' + c);
	if (a != 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

a = 0;
	while (a < 10)
	{
	b = a + 1;
		while (b < 10)
		{
			c = b + 1;
			while (c < 10)
			{
				ft_display(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
