/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:01:17 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 14:59:29 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_rec(int x, int y, t_map_check *player)
{
	if (player->carte_check[x][y] == '1' || player->carte_check[x][y] == 'X')
		return ;
	if (player->carte_check[x][y] == 'C')
		player->a++;
	if (player->carte_check[x][y] == 'E')
		player->e++;
	player->carte_check[x][y] = 'X';
	flood_fill_rec(x - 1, y, player);
	flood_fill_rec(x + 1, y, player);
	flood_fill_rec(x, y + 1, player);
	flood_fill_rec(x, y - 1, player);
}

void	map_temp(t_map *map, t_map_check *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->hauteur)
	{
		j = 0;
		while (j < map->largeur)
		{
			player->carte_check[i][j] = map->carte[i][j];
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	t_map_check	player;

	player.x = search_p_line(map);
	player.y = search_p_cols(map);
	player.a = 0;
	player.e = 0;
	map->c = count_char(map, 'C');
	map_temp(map, &player);
	flood_fill_rec(player.x, player.y, &player);
	if (map->c == 0)
	{
		printf("Collectible manquant\n");
		exit(EXIT_SUCCESS);
	}
	if (player.a != map->c || player.e != 1)
	{
		printf("Chemin impossible\n");
		exit(EXIT_SUCCESS);
	}
}
