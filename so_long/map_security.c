/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_security.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:43:37 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 13:43:37 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	security_map(t_map *map)
{
	row_cols(map);
	check_borders(map);
	number_e_p(map);
	check_map(map);
}

void	row_cols(t_map *map)
{
	int	j;
	int	o;

	if (map->hauteur > MAX_ROWS || map->largeur > MAX_COLS
		|| map->largeur < MIN_ROWS || map->hauteur < MIN_COLS)
	{
		ft_printf("Erreur : dimensions de la carte incorrectes.\n");
		exit(EXIT_FAILURE);
	}
	j = 0;
	o = 0;
	while (j < map->hauteur)
	{
		if (j == map->hauteur - 1)
			o = ft_strlen_n(map->carte[j]);
		else
			o = ft_strlen_n(map->carte[j]);
		if (o > map->largeur)
		{
			ft_printf("Erreur : Une ligne ou colonne n'est pas correcte.\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

int	count_char(t_map *map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->hauteur)
	{
		j = 0;
		while (j < map->largeur)
		{
			if (map->carte[i][j] == c)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	number_e_p(t_map *map)
{
	int	count_e;
	int	count_p;

	count_e = count_char(map, 'E');
	count_p = count_char(map, 'P');
	if (count_e > 1)
	{
		ft_printf("Erreur : plusieurs occurrences de 'E' trouvées.\n");
		exit(EXIT_SUCCESS);
	}
	if (count_p > 1)
	{
		ft_printf("Erreur : plusieurs occurrences de 'P' trouvées.\n");
		exit(EXIT_SUCCESS);
	}
}
