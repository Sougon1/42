/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:25:20 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 17:12:23 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	display_grid(int **grid)
{
	int	y;
	int	x;

	y = 0;
	if (no_solutions(grid))
	{
		write(2, "Error : grid has no solutions\n", 30);
		return (0);
	}
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(grid[y][x] + 48);
			if (x < 3)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	return (0);
}

int	no_solutions(int **grid)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (grid[y][x] == 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
