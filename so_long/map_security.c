/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/06/07 17:32:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 17:32:48 by marvin           ###   ########.fr       */
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
	int j;
	int o;
	if (map->hauteur > MAX_ROWS || map->largeur > MAX_COLS
		|| map->largeur < MIN_ROWS || map->hauteur < MIN_COLS)
	{
		ft_printf("Erreur : dimensions de la carte incorrectes.\n");
		exit(EXIT_SUCCESS);
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
			exit(EXIT_SUCCESS);
		}
		j++;
	}
}

int	count_char(t_map *map, char c)
{
	int count = 0;
	int i = 0;
	while (i < map->hauteur)
	{
		int j = 0;
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
	int count_e = count_char(map, 'E');
	int count_p = count_char(map, 'P');

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

void	check_borders(t_map *map)
{
	int i;
	i = 0;
	while (i < map->largeur)
	{
		if (map->carte[0][i] != '1' || map->carte[map->hauteur - 1][i] != '1')
		{
			ft_printf("Erreur : le contour de la carte n'est pas entouré de '1'.\n");
			exit(EXIT_SUCCESS);
		}
		i++;
	}

	i = 0;
	int j;
	while (i < map->hauteur)
	{
		j = 1;
		if (map->carte[i][0] != '1' || map->carte[i][map->largeur - 1] != '1')
		{
			ft_printf("Erreur : le contour de la carte n'est pas entouré de '1'.\n");
			exit(EXIT_SUCCESS);
		}
		while (j < map->largeur - 1)
		{
			if (map->carte[i][j] != '0' && map->carte[i][j] != '1'
				&& map->carte[i][j] != 'C' && map->carte[i][j] != 'P'
				&& map->carte[i][j] != 'E')
			{
				ft_printf("Erreur : Variable inconnu.\n");
				exit(EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
}
