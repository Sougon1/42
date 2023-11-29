/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:39:51 by jalbiser          #+#    #+#             */
/*   Updated: 2023/06/10 12:03:22 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char param);

/* h = horizontal et v = vertical */
void	rush(int x, int y)
{
	int	h;
	int	v;

	h = x;
	v = y;
	while (v != 0)
	{
		while (h != 0)
		{
			if ((h == 1 && v == y) || (h == x && v == y))
				ft_putchar('A');
			else if ((h == 1 && v == 1) || (h == x && v == 1))
				ft_putchar('C');
			else if (v == y || h == x || h == 1 || v == 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			h--;
		}
		ft_putchar('\n');
		h = x;
		v--;
	}
	ft_putchar('\n');
}
