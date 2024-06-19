/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:21 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/19 11:34:07 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//SEG FAULT A CAUSE DE MLX DESTROY DISPLAY

int close_window_t(t_map *map) {
    if (map->graphics.mlx) {
        mlx_destroy_window(map->graphics.mlx, map->graphics.fenetre);
        mlx_destroy_display(map->graphics.mlx);
    }
    exit(EXIT_SUCCESS);
}
void deplacer_joueur(t_map *map, int new_x, int new_y)
{
    int player_x = search_p_cols(map);
    int player_y = search_p_line(map);
    static int count_c = 0; // Utiliser une variable statique pour conserver la valeur entre les appels
    static char prev_tile = '0'; // Variable statique pour garder la trace de la case précédente du joueur

    if (player_x == -1 || player_y == -1) return;

    // Vérifiez si la nouvelle position est valide
    if (map->carte[new_y][new_x] != '1')
    {
        // Si la nouvelle position contient un collectable, augmentez le compteur
        if (map->carte[new_y][new_x] == 'C')
        {
            count_c++;
        }
        printf("\ncollectible a recuperer : %d\ncollectible recuperer : %d\n\n", map->c, count_c);
        // Déplacement du joueur
        if (prev_tile == 'E')
        {
            map->carte[player_y][player_x] = 'E'; // Restaurer la case 'E' si c'était la case précédente
        }
        else
        {
            map->carte[player_y][player_x] = '0'; // Sinon, restaurer la case à '0'
        }

        // Sauvegarder l'état de la nouvelle case avant de la remplacer par le joueur
        prev_tile = map->carte[new_y][new_x];

        // Placer le joueur dans la nouvelle case
        map->carte[new_y][new_x] = 'P';

        // Si le joueur atteint la sortie avec tous les collectables, fermez le jeu
        if (prev_tile == 'E' && count_c == map->c)
        {
            close_window_t(map);
        }

        mlx_clear_window(map->graphics.mlx, map->graphics.fenetre);
        dessiner_carte(map);
    }
}

// void deplacer_joueur(t_map *map, int new_x, int new_y, int c)
// {
//     int player_x = search_p_cols(map);
//     int player_y = search_p_line(map);
//     static int count_c = 0;
//     // printf("ligne player : %d\ncolonne player : %d\n\n", player_y, player_x);
//     if (player_x == -1 || player_y == -1) return;


//     if ()
//     {
//         /* code */
//     }
    
//     if (map->carte[new_y][new_x] != '1')
//     {
//         if (map->carte[new_y][new_x] == 'C')
//         {
//             count_c++;
//         }
//         else if (map->carte[new_y][new_x] == 'E' && c != count_c)
//         {
//             continue;
//         }
//         else if (map->carte[new_y][new_x] == 'E' && c == count_c)
//         {
//             close_window_t(map);
//         }
//         else
//         {
//             map->carte[player_y][player_x] = '0';
//             map->carte[new_y][new_x] = 'P';
//         }
//         mlx_clear_window(map->graphics.mlx, map->graphics.fenetre);
//         dessiner_carte(map);
//     }
// }

void load_mario_image(t_data *data)
{
    // Charger l'image Mario depuis le fichier XPM
    data->img_mario = mlx_xpm_file_to_image(data->mlx_ptr, "mario.xpm", &data->img_width, &data->img_height);
    if (!data->img_mario)
    {
        printf("Erreur lors du chargement de l'image Mario\n");
        exit(EXIT_FAILURE);
    }
}


int key_hook(int keycode, t_map *map) {
    static int i = 0;
    int player_x = search_p_cols(map);
    int player_y = search_p_line(map);
    
    if (keycode == 65307) { // Touche Échap
        close_window_t(map);
    } else if (keycode == 'w' || keycode == 'W') { // Haut
        deplacer_joueur(map, player_x, player_y - 1);
    } else if (keycode == 'a' || keycode == 'A') { // Gauche
        deplacer_joueur(map, player_x - 1, player_y);
    } else if (keycode == 's' || keycode == 'S') { // Bas
        deplacer_joueur(map, player_x, player_y + 1);
    } else if (keycode == 'd' || keycode == 'D') { // Droite
        deplacer_joueur(map, player_x + 1, player_y);
    }

    i++;
    ft_printf("\rNombre de touches pressées : %d ", i);

    return (0);
}

// Fonction de gestionnaire d'événements pour la fermeture de fenêtre en cliquant sur la croix
// int close_window(void *param)
// {
//     // t_map *map = (t_map *)param; // Cast de param en pointeur t_map

//     (void)param;
//     // mlx_destroy_display(map->graphics.mlx);
//     exit(0);
//     return (0);
// }


void event_handling(t_map *map) {
    mlx_key_hook(map->graphics.fenetre, (int (*)(int, void *))key_hook, map);
    ft_printf("Nombre de touches pressées : 0 ");
    mlx_hook(map->graphics.fenetre, 17, 0, (int (*)(void *))close_window_t, map);
}
// void event_handling(t_map *map)
// {
//     mlx_key_hook(map->graphics.fenetre, key_hook, NULL);
//     ft_printf("Nombre de touches pressées : 0 ");
//     mlx_hook(map->graphics.fenetre, 17, 0, close_window, NULL);
// }


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

    mlx_loop(map.graphics.mlx);
    printf("\n");
    mlx_destroy_display(map.graphics.mlx);

    return 0;
}

