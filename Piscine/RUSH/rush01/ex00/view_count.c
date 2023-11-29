/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:56:05 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 17:17:02 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	view_count_chooser(int **grid, int index)
{
	if (index < 4)
		return (view_count_yu(grid, index));
	if (index > 3 && index < 8)
		return (view_count_yd(grid, index - 4));
	if (index > 7 && index < 12)
		return (view_count_xl(grid, index - 8));
	if (index > 11)
		return (view_count_xr(grid, index - 12));
	return (0);
}

int	view_count_yu(int **grid, int index)
{
	int	i;
	int	count;
	int	bigger;

	i = 0;
	bigger = 1;
	count = 1;
	while (i < 3)
	{
		if (grid[i][index] > bigger)
			bigger = grid[i][index];
		if (grid[i][index] == 4)
			return (count);
		if (grid[i + 1][index] > grid[i][index] && grid[i + 1][index] > bigger)
			count++;
		i++;
	}
	return (count);
}

int	view_count_yd(int **grid, int index)
{
	int	i;
	int	count;
	int	bigger;

	i = 3;
	bigger = 1;
	count = 1;
	while (i > 0)
	{
		if (grid[i][index] > bigger)
			bigger = grid[i][index];
		if (grid[i][index] == 4)
			return (count);
		if (grid[i - 1][index] > grid[i][index] && grid[i - 1][index] > bigger)
			count++;
		i--;
	}
	return (count);
}

int	view_count_xl(int **grid, int index)
{
	int	i;
	int	count;
	int	bigger;

	i = 0;
	bigger = 1;
	count = 1;
	while (i < 3)
	{
		if (grid[index][i] > bigger)
			bigger = grid[index][i];
		if (grid[index][i] == 4)
			return (count);
		if (grid[index][i + 1] > grid[index][i] && grid[index][i + 1] > bigger)
			count++;
		i++;
	}
	return (count);
}

int	view_count_xr(int **grid, int index)
{
	int	i;
	int	count;
	int	bigger;

	i = 3;
	bigger = 1;
	count = 1;
	while (i > 0)
	{
		if (grid[index][i] > bigger)
			bigger = grid[index][i];
		if (grid[index][i] == 4)
			return (count);
		if (grid[index][i - 1] > grid[index][i] && grid[index][i - 1] > bigger)
			count++;
		i--;
	}
	return (count);
}
