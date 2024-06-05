/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:21 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/05 17:33:12 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(int ac, char **av)
// {
        
// }


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

int main() {
    char carte[MAX_ROWS][MAX_COLS];
    int largeur, hauteur;

    lire_carte("map1.ber", carte, &largeur, &hauteur);
    void *mlx = mlx_init();
    void *fenetre = mlx_new_window(mlx, largeur * TAILLE_CASE, hauteur * TAILLE_CASE, "Ma Carte");
    dessiner_carte(mlx, fenetre, carte, largeur, hauteur);

    // Gestion des événements clavier
    mlx_key_hook(fenetre, key_hook, NULL);
    ft_printf("Nombre de touches pressées : 0 ");
    mlx_hook(fenetre, 17, 0, close_window, NULL);

    // Boucle principale
    mlx_loop(mlx);

    return 0;
}

// int main(void)
// {
//     void *mlx;
//     void *win;
//     void *img;
//     char *data;
//     int bpp;
//     int size_line;
//     int endian;

//     // Initialisation de la connexion à X
//     mlx = mlx_init();
//     if (mlx == NULL)
//         return (1);

//     // Création d'une nouvelle fenêtre
//     win = mlx_new_window(mlx, 800, 600, "./so_long");
//     if (win == NULL)
//         return (1);

//     // Création d'une nouvelle image
//     img = mlx_new_image(mlx, 800, 600);
//     data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

//     // Dessiner un pixel vert au centre de l'image
//     int x = 400;
//     int y = 300;
//     int color = 0x00FF00; // Vert
//     int pos = (y * size_line) + (x * (bpp / 8));
//     data[pos] = color & 0xFF; // Bleu
//     data[pos + 1] = (color >> 8) & 0xFF; // Vert
//     data[pos + 2] = (color >> 16) & 0xFF; // Rouge

//     // Afficher l'image dans la fenêtre
//     mlx_put_image_to_window(mlx, win, img, 0, 0);
    
//     ft_printf("Nombre de touches pressées : 0 ");
//     // Gérer les événements du clavier (pour la touche "Échap")
//     mlx_key_hook(win, key_hook, NULL);

//     // Gérer la fermeture de fenêtre en cliquant sur la croix
//     mlx_hook(win, 17, 0, close_window, NULL);

//     // Boucle principale de MiniLibX
//     mlx_loop(mlx);

//     return (0);
// }

