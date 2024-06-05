/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:21 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/05 16:34:29 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(int ac, char **av)
// {
        
// }




#include <mlx.h>
#include <stdlib.h>

// Fonction de gestionnaire d'événements pour la fermeture de fenêtre en appuyant sur "Échap"
int key_hook(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307) // Touche Échap
        exit(0);
    return (0);
}

// Fonction de gestionnaire d'événements pour la fermeture de fenêtre en cliquant sur la croix
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    char *data;
    int bpp;
    int size_line;
    int endian;

    // Initialisation de la connexion à X
    mlx = mlx_init();
    if (mlx == NULL)
        return (1);

    // Création d'une nouvelle fenêtre
    win = mlx_new_window(mlx, 800, 600, "Window Title");
    if (win == NULL)
        return (1);

    // Création d'une nouvelle image
    img = mlx_new_image(mlx, 800, 600);
    data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    // Dessiner un pixel vert au centre de l'image
    int x = 400;
    int y = 300;
    int color = 0x00FF00; // Vert
    int pos = (y * size_line) + (x * (bpp / 8));
    data[pos] = color & 0xFF; // Bleu
    data[pos + 1] = (color >> 8) & 0xFF; // Vert
    data[pos + 2] = (color >> 16) & 0xFF; // Rouge

    // Afficher l'image dans la fenêtre
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Gérer les événements du clavier (pour la touche "Échap")
    mlx_key_hook(win, key_hook, NULL);

    // Gérer la fermeture de fenêtre en cliquant sur la croix
    mlx_hook(win, 17, 0, close_window, NULL);

    // Boucle principale de MiniLibX
    mlx_loop(mlx);

    return (0);
}

