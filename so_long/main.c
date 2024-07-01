/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:21 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 16:57:30 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_images *images, void *mlx_ptr)
{
	if (images->wall)
		mlx_destroy_image(mlx_ptr, images->wall);
	if (images->player)
		mlx_destroy_image(mlx_ptr, images->player);
	if (images->collectable)
		mlx_destroy_image(mlx_ptr, images->collectable);
	if (images->exit)
		mlx_destroy_image(mlx_ptr, images->exit);
	if (images->empty)
		mlx_destroy_image(mlx_ptr, images->empty);
}

int	close_window_t(t_map *map)
{
	if (map->graphics.mlx)
	{
		destroy(&map->images, map->graphics.mlx);
		mlx_destroy_window(map->graphics.mlx, map->graphics.fenetre);
		mlx_destroy_display(map->graphics.mlx);
		free(map->graphics.mlx);
	}
	exit(EXIT_SUCCESS);
}

void	load_images(t_map *map)
{
	int	width;
	int	height;

	map->images.wall = mlx_xpm_file_to_image(map->graphics.mlx, "XPM/wall.xpm",
			&width, &height);
	map->images.player = mlx_xpm_file_to_image(map->graphics.mlx,
			"XPM/player.xpm", &width, &height);
	map->images.collectable = mlx_xpm_file_to_image(map->graphics.mlx,
			"XPM/collectable.xpm", &width, &height);
	map->images.exit = mlx_xpm_file_to_image(map->graphics.mlx, "XPM/exit.xpm",
			&width, &height);
	map->images.empty = mlx_xpm_file_to_image(map->graphics.mlx,
			"XPM/empty.xpm", &width, &height);
	if (!map->images.wall || !map->images.player || !map->images.collectable
		|| !map->images.exit || !map->images.empty)
	{
		printf("Erreur lors du chargement des images\n");
		exit(EXIT_FAILURE);
	}
}

void	event_handling(t_map *map)
{
	mlx_key_hook(map->graphics.fenetre, key_hook, map);
	ft_printf("Nombre de touches pressées : 0 ");
	mlx_hook(map->graphics.fenetre, 17, 0, close_window_t, map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Usage: %s <fichier_carte.ber>\n", argv[0]);
		return (1);
	}
	map_init(&map);
	read_map(argv[1], &map);
	create_window(&map);
	load_images(&map);
	draw_map(&map);
	event_handling(&map);
	mlx_loop(map.graphics.mlx);
	ft_printf("\n");
	close_window_t(&map);
	return (0);
}
