/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/08 18:31:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void lire_carte(const char *nom_fichier, t_map *map)
// {
//     int fd = open(nom_fichier, O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         exit(1);
//     }

//     char buffer[MAX_COLS + 1]; // +1 pour le caractère nul
//     int row = 0;

//     ssize_t read_result;
//     while ((read_result = read(fd, buffer, MAX_COLS)) > 0 && row < MAX_ROWS)
//     {
//         buffer[read_result] = '\0'; // Ajout du caractère nul à la fin
//         strcpy(map->carte[row], buffer); // Copie des données dans la carte
//         row++;
//         // Ignorer les caractères de nouvelle ligne
//         lseek(fd, 1, SEEK_CUR);
//     }

//     if (read_result < 0)
//     {
//         perror("Erreur lors de la lecture du fichier");
//         close(fd);
//         exit(1);
//     }

//     map->hauteur = row;
//     map->largeur = strlen(map->carte[0]); // Utilisation de strlen pour déterminer la largeur
//     close(fd);
//     // security_map(map);
// }
void traiter_buffer(const char *buffer, ssize_t bytes_read, t_map *map, t_analyse *analyse)
{
    ssize_t i;

    i = 0;
    while (i < bytes_read)
    {
        if (buffer[i] == '\n')
        {
            analyse->ligne_count++;
            if (analyse->largeur_actuelle > analyse->largeur_max)
                analyse->largeur_max = analyse->largeur_actuelle;
            analyse->largeur_actuelle = 0;
            if (analyse->prem_ligne)
            {
                map->largeur = analyse->largeur_max -1;
                analyse->prem_ligne = 0;
            }
        }
        else
        {
            map->carte[analyse->ligne_count][analyse->largeur_actuelle] = buffer[i];
            analyse->largeur_actuelle++;
        }
        ft_putchar(buffer[i]);        // Afficher le caractère lu
        i++;
    }
}

void compter_lignes_et_colonnes(int fd, t_map *map) {
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];
    t_analyse analyse = {0, 1, 0, 0};  // Initialiser les variables d'analyse

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        traiter_buffer(buffer, bytes_read, map, &analyse);
    }

    printf("\n");
    map->hauteur = analyse.ligne_count + 1;

    printf("\ntaille largeur = %d\ntaille hauteur = %d\n", map->largeur, map->hauteur);

    if (bytes_read == -1) {
        perror("Erreur lors de la lecture du fichier");
        exit(EXIT_FAILURE);
    }
}


void lire_carte(const char *nom_fichier, t_map *map) {
    int fd;

    fd = open(nom_fichier, O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    compter_lignes_et_colonnes(fd, map);

    if (close(fd) == -1) {
        perror("Erreur lors de la fermeture du fichier");
        exit(EXIT_FAILURE);
    }
    security_map(map);
}






void creer_fenetre(t_map *map)
{
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