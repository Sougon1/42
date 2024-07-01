/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:38:56 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 12:47:42 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deplacer_joueur(t_map *map, int new_x, int new_y)
{
	int			player_x;
	int			player_y;
	static int	count_c = 0;
	static char	prev_tile = '0';

	player_x = search_p_cols(map);
	player_y = search_p_line(map);
	if (player_x == -1 || player_y == -1)
		return ;
	if (map->carte[new_y][new_x] != '1')
	{
		if (map->carte[new_y][new_x] == 'C')
			count_c++;
		if (prev_tile == 'E')
			map->carte[player_y][player_x] = 'E';
		else
			map->carte[player_y][player_x] = '0';
		prev_tile = map->carte[new_y][new_x];
		map->carte[new_y][new_x] = 'P';
		dessiner_case_specifique(map, player_x, player_y);
		dessiner_case_specifique(map, new_x, new_y);
		if (prev_tile == 'E' && count_c == map->c)
			close_window_t(map);
	}
}

// int	key_hook(int keycode, t_map *map)
// {
// 	static int	i = 0;
// 	int			player_x;
// 	int			player_y;

// 	player_x = search_p_cols(map);
// 	player_y = search_p_line(map);
// 	if (keycode == 65307)
// 	{
// 		close_window_t(map);
// 	}
// 	else if (keycode == 'w' || keycode == 'W')
// 		deplacer_joueur(map, player_x, player_y - 1);
// 	else if (keycode == 'a' || keycode == 'A')
// 		deplacer_joueur(map, player_x - 1, player_y);
// 	else if (keycode == 's' || keycode == 'S')
// 		deplacer_joueur(map, player_x, player_y + 1);
// 	else if (keycode == 'd' || keycode == 'D')
// 		deplacer_joueur(map, player_x + 1, player_y);
// 	i++;
// 	ft_printf("\rNombre de touches pressées : %d ", i);
// 	return (0);
// }

int	key_hook(int keycode, t_map *map)
{
	static int	i = 0;
	int			player_x;
	int			player_y;

	player_x = search_p_cols(map);
	player_y = search_p_line(map);
	if (keycode == 65307)
		close_window_t(map);
	else if (keycode == 'w' || keycode == 'W' || keycode == 'a'
		|| keycode == 'A' || keycode == 's' || keycode == 'S' || keycode == 'd'
		|| keycode == 'D')
	{
		i++;
		if (keycode == 'w' || keycode == 'W')
			deplacer_joueur(map, player_x, player_y - 1);
		else if (keycode == 'a' || keycode == 'A')
			deplacer_joueur(map, player_x - 1, player_y);
		else if (keycode == 's' || keycode == 'S')
			deplacer_joueur(map, player_x, player_y + 1);
		else if (keycode == 'd' || keycode == 'D')
			deplacer_joueur(map, player_x + 1, player_y);
	}
	ft_printf("\rNombre de touches pressées : %d ", i);
	return (0);
}

