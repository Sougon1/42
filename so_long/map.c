/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/07 18:56:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void lire_carte(const char *nom_fichier, t_map *map)
{
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    char buffer[MAX_COLS + 1];
    int row = 0;

    while (fgets(buffer, sizeof(buffer), fichier) != NULL && row < MAX_ROWS)
    {
        buffer[strcspn(buffer, "\n")] = '\0'; // Enlever le caractère de nouvelle ligne
        strcpy(map->carte[row], buffer);
        row++;
    }
    map->hauteur = row;
    map->largeur = ft_strlen(map->carte[0]) - 1;
    printf("\ntaille largeur = %ld\ntaille hauteur = %d\n", ft_strlen(map->carte[0]) - 1, map->hauteur);

    fclose(fichier);
    security_map(map);
}


void creer_fenetre(t_map *map) {
    map->mlx = mlx_init();
    int largeur_fenetre = map->largeur * TAILLE_CASE;  // Largeur de la fenêtre basée sur la carte
    int hauteur_fenetre = map->hauteur * TAILLE_CASE;  // Hauteur de la fenêtre basée sur la carte

    map->fenetre = mlx_new_window(map->mlx, largeur_fenetre, hauteur_fenetre, "Ma Carte");
}

void dessiner_case(t_map *map, int x, int y, int couleur) {
    int px = x * TAILLE_CASE;
    int py = y * TAILLE_CASE;
    int end_x = px + TAILLE_CASE;
    int end_y = py + TAILLE_CASE;

    for (int i = px; i < end_x; i++) {
        for (int j = py; j < end_y; j++) {
            mlx_pixel_put(map->mlx, map->fenetre, i, j, couleur);
        }
    }
}

void dessiner_carte_rec(t_map *map, int x, int y) {
    // if (x >= map->largeur) {
    //     x = 0;
    //     y++; // Passer à la ligne suivante
    // }

    // if (y >= map->hauteur) {
    //     return;
    // }

    int couleur = 0xFFFF90; // Blanc par défaut

    char cell = map->carte[y][x];
    // printf("Case (%d, %d): Cellule = %c\n", x, y, cell); // Instruction de débogage
    switch (cell) {
        case '1':
            couleur = 0x000100; // Noir pour les murs
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

    // printf("Case (%d, %d): Couleur = %06X\n", x, y, couleur); // Instruction de débogage
    dessiner_case(map, x, y, couleur);
       // Vérifiez si vous devez passer à la case suivante ou à la ligne suivante
    if (x < map->largeur - 1) { // Vérifiez si vous êtes à la fin de la ligne
        dessiner_carte_rec(map, x + 1, y); // Passez à la case suivante sur la même ligne
    } else if (y < map->hauteur - 1) { // Vérifiez si vous êtes à la fin de la carte
        dessiner_carte_rec(map, 0, y + 1); // Passez à la première case de la ligne suivante
    }
    
    
    
    // dessiner_carte_rec(map, x + 1, y); // Appel récursif pour passer à la case suivante sur la même ligne
    // Ajouter un appel récursif pour passer à la ligne suivante
    // dessiner_carte_rec(map, x, y + 1);
}





void dessiner_carte(t_map *map) {
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