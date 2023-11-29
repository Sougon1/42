/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:04:43 by adenord           #+#    #+#             */
/*   Updated: 2023/06/17 19:38:22 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	**init_grid(void)
{
	int	**grid;
	int	x;
	int	y;

	x = 0;
	y = 0;
	grid = (int **)malloc(sizeof(int *) * 4);
	while (x < 4)
	{
		grid[x] = (int *)malloc(sizeof(int) * 4);
		x++;
	}
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
	}
	return (grid);
}
