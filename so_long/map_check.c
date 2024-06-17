/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:01:17 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/17 10:52:58 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map_check(t_map_check *map_check, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->hauteur)
    {
        j = 0;
        while (j < map->largeur)
        {
            printf("%c", map_check->carte_check[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

void print_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->hauteur)
    {
        j = 0;
        while (j < map->largeur)
        {
            printf("%c", map->carte[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

void flood_fill_rec(int x, int y, t_map_check *player)
{
    if (player->carte_check[x][y] == '1' || player->carte_check[x][y] == 'X')
        return;
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

void carte_temp(t_map *map, t_map_check *player)
{
    int i;
    int j;

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

void check_map(t_map *map)
{
    t_map_check player;
    
    player.x = search_p_line(map);
    player.y = search_p_cols(map);
    player.a = 0;
    player.e = 0;
    printf("\nligne = %d \ncolonne = %d\n\n", player.x, player.y);
    
    map->c = count_char(map, 'C');
    
    print_map(map);

    carte_temp(map, &player);
    flood_fill_rec(player.x, player.y, &player);

    if (player.a != map->c || player.e != 1)
    {
        printf("Erreur : Chemin impossible\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("A = C\n");
    }

    printf("\n");
    print_map_check(&player, map);
    printf("\n");
    print_map(map);
    printf("\n");
}
