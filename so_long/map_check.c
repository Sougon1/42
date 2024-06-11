/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:01:17 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/11 17:58:25 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_map(t_map *map)
{
    int i = 0;
    int j = 0;

    while (i < map->hauteur)
    {
        j = 0;
        while (j < map->largeur)
        {
            printf("%c", map->carte[i][j++]);
        }
        i++;
        printf("\n");   
    }
    
    
}






int search_p_line(t_map *map)
{
    int i;
    int j;
    
    i = 0;
    while (i < map->hauteur)
    {
        j = 0;
        while (j < map->largeur)
        {
            if (map->carte[i][j++] == 'P')
            {
                return (i);
            }
        }
        i++;
    }
    return (0);
}

int search_p_cols(t_map *map)
{
    int i;
    int j;
    
    i = 0;
    while (i < map->hauteur)
    {
        j = 0;
        while (j < map->largeur)
        {
            if (map->carte[i][j++] == 'P')
            {
                return (j);
            }
        }
        i++;
    }
    return (0);
}

void    flood_fill_rec(int x, int y, int *a, t_map **map)
{
    if ((*map)->carte[x][y] == '1' || (*map)->carte[x][y] == 'X')
    {
        return;
    }
    if ((*map)->carte[x][y] == 'C')
    {
        (*a)++;
    }
    
    (*map)->carte[x][y] = 'X';
    flood_fill_rec(x - 1, y, a ,map);
    flood_fill_rec(x + 1, y, a, map);
    flood_fill_rec(x, y - 1, a, map);
    flood_fill_rec(x, y + 1, a, map);
    
    
    
}

// char    *carte_temp(t_map *map);
// {
    

    
// }

void    check_map(t_map *map)
{
    int x;
    int y;
    int c;
    int a;
    // char    **carte_tmp;
    
    // t_player *player;
    
    // player->x = search_p_line(map);
    // player->y = search_p_cols(map);
    
    a = 0;
    x = search_p_line(map);
    y = search_p_cols(map);
    c = count_char(map, 'C');
    

    print_map(map);

    // *carte_tmp = carte_temp(map);
    flood_fill_rec(x, y, &a, &map);
    
    if (a == c)
    {
        printf("A est egale a C\n");
    }
    else
        printf("TG\n");
    
    printf("\n");
    print_map(map);
    printf("\n");

    
}