/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:38:56 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 15:05:58 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moov_player(t_map *map, int new_x, int new_y)
{
	static int	count_c = 0;
	static char	prev_tile = '0';

	if (map->player_x == -1 || map->player_y == -1)
		return (0);
	if (map->carte[new_y][new_x] != '1')
	{
		if (map->carte[new_y][new_x] == 'C')
			count_c++;
		if (prev_tile == 'E')
			map->carte[map->player_y][map->player_x] = 'E';
		else
			map->carte[map->player_y][map->player_x] = '0';
		prev_tile = map->carte[new_y][new_x];
		map->carte[new_y][new_x] = 'P';
		draw_case_specific(map, map->player_x, map->player_y);
		draw_case_specific(map, new_x, new_y);
		if (prev_tile == 'E' && count_c == map->c)
			close_window_t(map);
		return (1);
	}
	return (0);
}

int	check_keycode(int keycode, int i, t_map *map)
{
	if (keycode == 'w' || keycode == 'W')
	{
		if (moov_player(map, map->player_x, map->player_y - 1) == 1)
			i++;
	}
	else if (keycode == 'a' || keycode == 'A')
	{
		if (moov_player(map, map->player_x - 1, map->player_y) == 1)
			i++;
	}
	else if (keycode == 's' || keycode == 'S')
	{
		if (moov_player(map, map->player_x, map->player_y + 1) == 1)
			i++;
	}
	else if (keycode == 'd' || keycode == 'D')
	{
		if (moov_player(map, map->player_x + 1, map->player_y) == 1)
			i++;
	}
	return (i);
}

int	key_hook(int keycode, t_map *map)
{
	static int	i = 0;

	map->player_x = search_p_cols(map);
	map->player_y = search_p_line(map);
	if (keycode == 65307)
		close_window_t(map);
	else if (keycode == 'w' || keycode == 'W' || keycode == 'a'
		|| keycode == 'A' || keycode == 's' || keycode == 'S' || keycode == 'd'
		|| keycode == 'D')
	{
		i = check_keycode(keycode, i, map);
	}
	ft_printf("\rNombre de touches pressées : %d ", i);
	return (0);
}
