/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:14:46 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 10:37:48 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dessiner_case_specifique(t_map *map, int x, int y)
{
	void	*image;

	if (map->carte[y][x] == '1')
	{
		image = map->images.wall;
	}
	else if (map->carte[y][x] == 'P')
	{
		image = map->images.player;
	}
	else if (map->carte[y][x] == 'C')
	{
		image = map->images.collectable;
	}
	else if (map->carte[y][x] == 'E')
	{
		image = map->images.exit;
	}
	else if (map->carte[y][x] == '0')
	{
		image = map->images.empty;
	}
	else
		image = map->images.empty;
	dessiner_case(map, x, y, image);
}

void	dessiner_carte(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->hauteur)
	{
		x = 0;
		while (x < map->largeur)
		{
			dessiner_case_specifique(map, x, y);
			x++;
		}
		y++;
	}
}

void	dessiner_case(t_map *map, int x, int y, void *image)
{
	int	px;
	int	py;

	px = x * TAILLE_CASE;
	py = y * TAILLE_CASE;
	mlx_put_image_to_window(map->graphics.mlx, map->graphics.fenetre, image, px,
		py);
}

void	creer_fenetre(t_map *map)
{
	map->graphics.mlx = mlx_init();
	if (map->graphics.mlx == NULL)
	{
		ft_printf("Erreur lors de l'initialisation de la connexion à X\n");
		exit(1);
	}
	map->graphics.fenetre = mlx_new_window(map->graphics.mlx, map->largeur
			* TAILLE_CASE, map->hauteur * TAILLE_CASE, "./so_long");
	if (map->graphics.fenetre == NULL)
	{
		ft_printf("Erreur lors de la création de la fenêtre\n");
		exit(1);
	}
}
