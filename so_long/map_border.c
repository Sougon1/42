/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:08:11 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 14:18:00 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_top_bottom_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->largeur)
	{
		if (map->carte[0][i] != '1' || map->carte[map->hauteur - 1][i] != '1')
		{
			ft_printf("Erreur : Contour n'est pas entouré de '1'.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_internal_values(t_map *map, int row)
{
	int		j;
	char	current_char;

	j = 1;
	while (j < map->largeur - 1)
	{
		current_char = map->carte[row][j];
		if (current_char != '0' && current_char != '1' && current_char != 'C'
			&& current_char != 'P' && current_char != 'E')
		{
			ft_printf("Erreur : Variable inconnue.\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_left_right_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->hauteur)
	{
		if (map->carte[i][0] != '1' || map->carte[i][map->largeur - 1] != '1')
		{
			ft_printf("Erreur : Contour n'est pas entouré de '1'.\n");
			exit(EXIT_FAILURE);
		}
		check_internal_values(map, i);
		i++;
	}
}

void	check_borders(t_map *map)
{
	check_top_bottom_borders(map);
	check_left_right_borders(map);
}
