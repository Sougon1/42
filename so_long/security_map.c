/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:32:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 17:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    security_map(t_map *map)
{
    row_cols(map);
    check_borders(map);
    number_e_p(map);

}

void row_cols(t_map *map)
{
    if (map->hauteur > MAX_ROWS || map->largeur > MAX_COLS)
    {
        fprintf(stderr, "Erreur : dimensions de la carte incorrectes.\n");
        exit(EXIT_FAILURE);
    }

    // Affichage de la longueur de la première ligne
    printf("Longueur de la ligne 0 : %d\n", map->largeur);

    // Vérification de la largeur de chaque ligne par rapport à la première ligne
    int j = 1; // On commence à la deuxième ligne
    while (j < map->hauteur)
    {
        printf("Longueur de la ligne %d : %d\n", j, (int)ft_strlen(map->carte[j]) - 1);
        if (j == map->hauteur)
        {
            if ((int)ft_strlen(map->carte[j]) + 1 != map->largeur)
                exit(EXIT_FAILURE);
        }
        if ((int)ft_strlen(map->carte[j]) - 1 != map->largeur)
        {
            fprintf(stderr, "Erreur : La taille d'une ligne n'est pas correcte.\n");
            exit(EXIT_FAILURE);
        }
        j++;
    }

    // Vérification de la hauteur de chaque colonne par rapport à la première colonne
    int i = 0;
    while (i < map->largeur)
    {
        j = 0;
        while (j < map->hauteur)
        {
            if (map->carte[j][i] == '\0')
            {
                fprintf(stderr, "Erreur : La taille d'une colonne n'est pas correcte.\n");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}



int count_char(t_map *map, char c)
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
    return count;
}

void    number_e_p(t_map *map)
{
    int count_e = count_char(map, 'E');
    int count_p = count_char(map, 'P');

    if (count_e > 1)
    {
        fprintf(stderr, "Erreur : plusieurs occurrences de 'E' trouvées.\n");
        exit(EXIT_FAILURE);
    }

    if (count_p > 1)
    {
        fprintf(stderr, "Erreur : plusieurs occurrences de 'P' trouvées.\n");
        exit(EXIT_FAILURE);
    }
}

void check_borders(t_map *map)
{
    // Vérifier la première et la dernière ligne
    int i = 0;
    while (i < map->largeur)
    {
        if (map->carte[0][i] != '1' || map->carte[map->hauteur - 1][i] != '1')
        {
            fprintf(stderr, "Erreur : le contour de la carte n'est pas entouré de '1'.\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    // Vérifier la première et la dernière colonne
    i = 0;
    while (i < map->hauteur)
    {
        if (map->carte[i][0] != '1' || map->carte[i][map->largeur - 1] != '1')
        {
            fprintf(stderr, "Erreur : le contour de la carte n'est pas entouré de '1'.\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}