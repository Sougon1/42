/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:31:22 by adenord           #+#    #+#             */
/*   Updated: 2023/06/17 19:38:02 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	free_tabs(int **grid, int *tab)
{
	int	x;

	x = 0;
	free(tab);
	while (x < 4)
	{
		free(grid[x]);
		x++;
	}
	free(grid);
}
