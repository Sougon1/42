/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:39:34 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 17:13:39 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	is_on_row(int **grid, int nb, int row)
{
	int	y;

	y = 0;
	while (y < 4)
	{
		if (nb == grid[y][row])
			return (0);
		y++;
	}
	return (1);
}

int	is_on_line(int **grid, int nb, int line)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (nb == grid[line][x])
			return (0);
		x++;
	}
	return (1);
}

int	is_valid(int **grid, int pos, int *tab)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	y = pos / 4;
	x = pos % 4;
	if (pos == 4 * 4)
		return (count_parser(grid, tab));
	if (grid[y][x] != 0)
		return (is_valid(grid, pos + 1, tab));
	while (i < 5)
	{
		if (is_on_row(grid, i, x) && is_on_line(grid, i, y))
		{
			grid[y][x] = i;
			if (is_valid(grid, pos + 1, tab))
				return (1);
		}
		i++;
	}
	grid[y][x] = 0;
	return (0);
}
