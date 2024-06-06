/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/06 17:16:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void lire_carte(const char *nom_fichier, char carte[MAX_ROWS][MAX_COLS], int *largeur, int *hauteur)
{
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    fscanf(fichier, "%d %d\n", largeur, hauteur);

    for (int i = 0; i < *hauteur; i++) {
        fgets(carte[i], MAX_COLS, fichier);
    }

    fclose(fichier);
}

void creer_fenetre(t_map *map)
{
    map->mlx = mlx_init();
    map->fenetre = mlx_new_window(map->mlx, map->largeur * TAILLE_CASE, map->hauteur * TAILLE_CASE, "Ma Carte");
}

void dessiner_carte_rec(t_map *map, int x, int y)
{
    if (x >= map->largeur) {
        x = 0;
        y++;
    }

    if (y >= map->hauteur) {
        return;
    }

    int couleur = 0xFFFFFF; // Blanc par défaut

    switch (map->carte[y][x]) {
        case '1':
            couleur = 0x000000; // Noir pour les murs
            break;
        case 'P':
            couleur = 0xFF0000; // Rouge pour le joueur
            break;
        case 'C':
            couleur = 0x00FF00; // Vert pour les collectables
            break;
        case 'E':
            couleur = 0x0000FF; // Bleu pour la sortie
            break;
        case '0':
            couleur = 0xFFFFFF; // Blanc pour les espaces vides
            break;
        // Ajoutez d'autres cas pour d'autres éléments de la carte si nécessaire
    }

    mlx_pixel_put(map->mlx, map->fenetre, x * TAILLE_CASE, y * TAILLE_CASE, couleur);
    dessiner_carte_rec(map, x + 1, y);
}

void dessiner_carte(t_map *map)
{
    dessiner_carte_rec(map, 0, 0);
}








































// void lire_ligne(FILE *fichier, char carte[MAX_ROWS][MAX_COLS], int row, int hauteur)
// {
//     if (row >= hauteur)
//         return;
    
//     fgets(carte[row], MAX_COLS, fichier);
//     lire_ligne(fichier, carte, row + 1, hauteur);
// }

// void lire_carte(const char *nom_fichier, t_map *map)
// {
//     FILE *fichier = fopen(nom_fichier, "r");
//     if (fichier == NULL) {
//         perror("Erreur lors de l'ouverture du fichier");
//         exit(1);
//     }

//     fscanf(fichier, "%d %d\n", &map->largeur, &map->hauteur);
//     lire_ligne(fichier, map->carte, 0, map->hauteur);

//     fclose(fichier);
// }

// void creer_fenetre(t_map *map)
// {
//     map->mlx = mlx_init();
//     map->fenetre = mlx_new_window(map->mlx, map->largeur * TAILLE_CASE, map->hauteur * TAILLE_CASE, "Ma Carte");

//     // Gestion des événements clavier
//     mlx_key_hook(map->fenetre, key_hook, NULL);
//     printf("Nombre de touches pressées : 0 ");
//     mlx_hook(map->fenetre, 17, 0, close_window, NULL);

//     // Boucle principale
//     mlx_loop(map->mlx);
// }


// void dessiner_carte_rec(t_map *map, int x, int y)
// {
//     if (x >= map->largeur) {
//         x = 0;
//         y++;
//     }

//     if (y >= map->hauteur) {
//         return;
//     }

//     int couleur = 0xFFFFFF; // Blanc par défaut

//     switch (map->carte[y][x]) {
//         case '1':
//             couleur = 0x000000; // Noir pour les murs
//             break;
//         case 'P':
//             couleur = 0xFF0000; // Rouge pour le joueur
//             break;
//         case 'C':
//             couleur = 0x00FF00; // Vert pour les collectables
//             break;
//         case 'E':
//             couleur = 0x0000FF; // Bleu pour la sortie
//             break;
//         case '0':
//             couleur = 0xFFFFFF; // Blanc pour les espaces vides
//             break;
//         // Ajoutez d'autres cas pour d'autres éléments de la carte si nécessaire
//     }

//     mlx_pixel_put(map->mlx, map->fenetre, x * TAILLE_CASE, y * TAILLE_CASE, couleur);
//     dessiner_carte_rec(map, x + 1, y);
// }

// void dessiner_carte(t_map *map)
// {
//     dessiner_carte_rec(map, 0, 0);
// }