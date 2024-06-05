/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/05 17:29:35 by ghumm            ###   ########.fr       */
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



void creer_fenetre(int largeur, int hauteur)
{
    void *mlx = mlx_init();
    mlx_new_window(mlx, largeur * TAILLE_CASE, hauteur * TAILLE_CASE, "Ma Carte");
}



void dessiner_carte_rec(void *mlx, void *fenetre, char carte[MAX_ROWS][MAX_COLS], int x, int y, int largeur, int hauteur)
{
    if (x >= largeur || y >= hauteur) {
        return;
    }

    int couleur = 0xFFFFFF; // Blanc par défaut

    switch (carte[y][x]) {
        case '1':
            couleur = 0x000000; // Noir pour les murs
            break;
        case 'P':
            couleur = 0xFF0000; // Rouge pour le joueur
            break;
        // Ajoutez d'autres cas pour d'autres éléments de la carte si nécessaire
    }

    mlx_pixel_put(mlx, fenetre, x * TAILLE_CASE, y * TAILLE_CASE, couleur);

    // Appel récursif pour dessiner les éléments suivants
    if (x + 1 < largeur) {
        dessiner_carte_rec(mlx, fenetre, carte, x + 1, y, largeur, hauteur);
    } else if (y + 1 < hauteur) {
        dessiner_carte_rec(mlx, fenetre, carte, 0, y + 1, largeur, hauteur);
    }
}

void dessiner_carte(void *mlx, void *fenetre, char carte[MAX_ROWS][MAX_COLS], int largeur, int hauteur)
{
    dessiner_carte_rec(mlx, fenetre, carte, 0, 0, largeur, hauteur);
}
