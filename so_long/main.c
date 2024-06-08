/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:21 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/08 16:08:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void event_handling(t_map *map)
{
    mlx_key_hook(map->fenetre, key_hook, NULL);
    ft_printf("Nombre de touches pressées : 0 ");
    mlx_hook(map->fenetre, 17, 0, close_window, NULL);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier_carte.ber>\n", argv[0]);
        return 1;
    }

    t_map map;
    lire_carte(argv[1], &map);

    creer_fenetre(&map);
    dessiner_carte(&map);
    event_handling(&map); // Gestion des événements

    // mlx_key_hook(map.fenetre, key_hook, NULL);
    // ft_printf("Nombre de touches pressées : 0 ");
    // mlx_hook(map.fenetre, 17, 0, close_window, NULL);
    printf("\ntaille largeur = %d\ntaille hauteur = %d\n", map.largeur, map.hauteur);

    mlx_loop(map.mlx);
    printf("\n");

    return 0;
}

