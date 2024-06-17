/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:18:04 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 16:18:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen_n(const char *str)
{
    int length;
    
    length = 0;
    while (str[length] != '\0' && str[length] != '\r')
    {
        length++;
    }
    
    return length;
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
            if (map->carte[i][j] == 'P')
            {
                return (i);
            }
            j++;
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
            if (map->carte[i][j] == 'P')
            {
                return (j);
            }
            j++;
        }
        i++;
    }
    return (0);
}
