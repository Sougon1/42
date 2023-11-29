/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:14:20 by adenord           #+#    #+#             */
/*   Updated: 2023/06/17 19:37:40 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	first_fill(int **grid, int *tab)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 4 && tab[i] == 1)
			grid[0][i] = 4;
		if ((i > 3 && i < 8) && tab[i] == 1)
			grid[3][i - 4] = 4;
		if ((i > 7 && i < 12) && tab[i] == 1)
			grid[i - 8][0] = 4;
		if (i > 11 && tab[i] == 1)
			grid[i - 12][3] = 4;
		i++;
	}
}

void	second_fill(int **grid, int *tab)
{
	int	i;
	int	j;
	int	filler;
	int	reverse;

	i = 0;
	while (i < 16)
	{
		j = 0;
		filler = 1;
		reverse = 4;
		if (tab[i] == 4 && i < 4)
		{
			while (j < 4)
				grid[j++][i] = filler++;
		}
		if (tab[i] == 4 && (i > 3 && i < 8))
		{
			while (j < 4)
				grid[j++][i - 4] = reverse--;
		}
		i++;
	}
}

void	third_fill(int **grid, int *tab)
{
	int	i;
	int	j;
	int	filler;
	int	reverse;

	i = 0;
	while (i < 16)
	{
		j = 0;
		filler = 1;
		reverse = 4;
		if (tab[i] == 4 && (i > 7 && i < 12))
		{
			while (j < 4)
				grid[i - 8][j++] = filler++;
		}
		if (tab[i] == 4 && i > 11)
		{
			while (j < 4)
				grid[i - 12][j++] = reverse--;
		}
		i++;
	}
}
