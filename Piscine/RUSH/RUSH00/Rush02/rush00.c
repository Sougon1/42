/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:39:51 by jalbiser          #+#    #+#             */
/*   Updated: 2023/06/10 13:59:36 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char param);

void	ft_printline(int h, int v, int x, int y)
{
	if ((h == 1 && v == y) || (h == x && v == y))
		ft_putchar('o');
	else if ((h == 1 && v == 1) || (h == x && v == 1))
		ft_putchar('o');
	else if (v == y || v == 1)
		ft_putchar('-');
	else if ((v <= y && h == x) || (v <= y && h == 1))
		ft_putchar('|');
	else
		ft_putchar(' ');
}

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
			ft_printline(h, v, x, y);
			h--;
		}
		ft_putchar('\n');
		h = x;
		v--;
	}
	ft_putchar('\n');
}
