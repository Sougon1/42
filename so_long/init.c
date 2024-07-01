/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:57:05 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 16:57:34 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	int i;
	int j;

	(*map).largeur = 0;
	(*map).hauteur = 0;
	(*map).player_x = 0;
	(*map).player_y = 0;
	(*map).c = 0;
	(*map).graphics.mlx = NULL;
	(*map).graphics.fenetre = NULL;
	(*map).images.wall = NULL;
	(*map).images.player = NULL;
	(*map).images.collectable = NULL;
	(*map).images.exit = NULL;
	(*map).images.empty = NULL;
	i = 0;
	while (i < MAX_ROWS)
	{
		j = 0;
		while (j < MAX_COLS)
			(*map).carte[i][j++] = '\0';
		i++;
	}
}