/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:21 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/06 18:51:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(int ac, char **av)
// {
        
// }


#include "so_long.h"

// Fonction de gestionnaire d'événements pour la fermeture de fenêtre en appuyant sur "Échap"
int key_hook(int keycode, void *param)
{
    static int i = 0; // Déclarer i en dehors de la fonction pour qu'elle conserve sa valeur

    (void)param;

    if (keycode == 65307) // Touche Échap
    {
        exit(0);
    }
    else if (keycode == 'w' || keycode == 'W' ||
             keycode == 'a' || keycode == 'A' ||
             keycode == 's' || keycode == 'S' ||
             keycode == 'd' || keycode == 'D') // Touche WASD
    {
        i++;
        ft_printf("\rNombre de touches pressées : %d ", i); // Utiliser \r pour revenir au début de la ligne
    }

    return (0);
}

// Fonction de gestionnaire d'événements pour la fermeture de fenêtre en cliquant sur la croix
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <path_to_map>\n", argv[0]);
//         return 1;
//     }

//     t_map map;
//     int largeur, hauteur;

//     printf("Trying to open file: %s\n", argv[1]);
//     lire_carte(argv[1], map.carte, &largeur, &hauteur);
//     map.largeur = largeur;
//     map.hauteur = hauteur;
//     map.mlx = mlx_init();
//     if (map.mlx == NULL) {
//         ft_printf("Erreur lors de l'initialisation de la connexion à X\n");
//         return 1;
//     }
//     map.fenetre = mlx_new_window(map.mlx, largeur * TAILLE_CASE, hauteur * TAILLE_CASE, "Ma Carte");
//     if (map.fenetre == NULL) {
//         ft_printf("Erreur lors de la création de la fenêtre\n");
//         return 1;
//     }
//     dessiner_carte(&map);

//     // Gestion des événements clavier
//     mlx_key_hook(map.fenetre, key_hook, NULL);
//     ft_printf("Nombre de touches pressées : 0 ");
//     mlx_hook(map.fenetre, 17, 0, close_window, NULL);

//     // Boucle principale
//     mlx_loop(map.mlx);
// }



#include "mlx.h"

void draw_square(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color)
{
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
        }
    }
}

void fill_window(void *mlx_ptr, void *win_ptr, int width, int height, int color)
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
        }
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    int win_width = 800;
    int win_height = 600;

    // Initialisation de la connexion avec le serveur graphique
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return 1;

    // Création de la fenêtre
    win_ptr = mlx_new_window(mlx_ptr, win_width, win_height, "Fenêtre avec un point plus gros");
    if (!win_ptr)
        return 1;

    // Remplissage de la fenêtre avec une couleur noire pour simuler l'opacité
    fill_window(mlx_ptr, win_ptr, win_width, win_height, 0x000000);

    // Affichage du point au centre de la fenêtre
    int point_size = 21; // Taille du point (un carré 21x21)
    int point_x = (win_width - point_size) / 2; // Coordonnée X du point
    int point_y = (win_height - point_size) / 2; // Coordonnée Y du point
    draw_square(mlx_ptr, win_ptr, point_x, point_y, point_size, 0xFF0000); // Couleur rouge

    // Boucle événementielle pour conserver la fenêtre ouverte
    mlx_loop(mlx_ptr);

    // Libérer les ressources
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);

    return 0;
}















// // Fonction de gestionnaire d'événements pour la fermeture de fenêtre en appuyant sur "Échap"
// int key_hook(int keycode, void *param)
// {
//     static int i = 0; // Déclarer i en dehors de la fonction pour qu'elle conserve sa valeur

//     (void)param;

//     if (keycode == 65307) // Touche Échap
//     {
//         exit(0);
//     }
//     else if (keycode == 'w' || keycode == 'W' ||
//              keycode == 'a' || keycode == 'A' ||
//              keycode == 's' || keycode == 'S' ||
//              keycode == 'd' || keycode == 'D') // Touche WASD
//     {
//         i++;
//         ft_printf("\rNombre de touches pressées : %d ", i); // Utiliser \r pour revenir au début de la ligne
//     }

//     return (0);
// }


// // Fonction de gestionnaire d'événements pour la fermeture de fenêtre en cliquant sur la croix
// int close_window(void *param)
// {
//     (void)param;
//     exit(0);
//     return (0);
// }

// // int main() {
// //     char carte[MAX_ROWS][MAX_COLS];
// //     int largeur, hauteur;

// //     lire_carte("map1.ber", carte, &largeur, &hauteur);
// //     void *mlx = mlx_init();
// //     void *fenetre = mlx_new_window(mlx, largeur * TAILLE_CASE, hauteur * TAILLE_CASE, "Ma Carte");
// //     dessiner_carte(mlx, fenetre, carte, largeur, hauteur);

// //     // Gestion des événements clavier
// //     mlx_key_hook(fenetre, key_hook, NULL);
// //     ft_printf("Nombre de touches pressées : 0 ");
// //     mlx_hook(fenetre, 17, 0, close_window, NULL);

// //     // Boucle principale
// //     mlx_loop(mlx);

// //     return 0;
// // }
// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Usage: %s <map_file>\n", argv[0]);
//         return 1;
//     }

//     t_map map;

//     lire_carte(argv[1], &map);
//     creer_fenetre(&map);
//     dessiner_carte(&map);
//     ft_printf("\n");
//     return 0;
// }
