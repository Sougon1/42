/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/17 11:25:02 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void print_visible_whitespace(const char str) {
    switch (str) {
        case '\n': printf("\\n\n"); break;
        case '\t': printf("\\t"); break;
        case '\r': printf("\\r"); break;
        case '\f': printf("\\f"); break;
        case '\v': printf("\\v"); break;
        case ' ': printf("\\s"); break;
        case '\0': printf("\\0"); break;
        default: putchar(str); break;
    }
}

void traiter_buffer(const char *buffer, ssize_t bytes_read, t_map *map, t_analyse *analyse) {
    ssize_t i = 0;

    while (i < bytes_read) {
        if (buffer[i] == '\n') {
            map->carte[analyse->ligne_count][analyse->largeur_actuelle] = '\0';
            analyse->ligne_count++;
            if (analyse->largeur_actuelle > analyse->largeur_max)
                analyse->largeur_max = analyse->largeur_actuelle;
            analyse->largeur_actuelle = 0;
            if (analyse->prem_ligne) {
                map->largeur = analyse->largeur_max;
                analyse->prem_ligne = 0;
            }
        } else {
            map->carte[analyse->ligne_count][analyse->largeur_actuelle] = buffer[i];
            analyse->largeur_actuelle++;
        }
        print_visible_whitespace(buffer[i]);
        i++;
    }
    map->carte[analyse->ligne_count][analyse->largeur_actuelle] = '\0';
}

void compter_lignes_et_colonnes(int fd, t_map *map) {
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];
    t_analyse analyse = {0, 1, 0, 0};

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        traiter_buffer(buffer, bytes_read, map, &analyse);
    }

    printf("\n");
    map->hauteur = analyse.ligne_count + 1;

    int o = 0;
    int j = 0;
    printf("\n");
    while (j < map->hauteur) {
        o = 0;
        while (o < map->largeur + 1) {
            print_visible_whitespace(map->carte[j][o++]);
        }
        printf("\n");
        j++;
    }
    printf("\n");

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
    security_map(map); // Assurez-vous d'appeler cette fonction si nécessaire
}

void creer_fenetre(t_map *map) {
    map->graphics.mlx = mlx_init();
    if (map->graphics.mlx == NULL) {
        ft_printf("Erreur lors de l'initialisation de la connexion à X\n");
        exit(1);
    }
    map->graphics.fenetre = mlx_new_window(map->graphics.mlx, map->largeur * TAILLE_CASE, map->hauteur * TAILLE_CASE, "Ma Carte");
    if (map->graphics.fenetre == NULL) {
        ft_printf("Erreur lors de la création de la fenêtre\n");
        exit(1);
    }
}

void dessiner_case(t_map *map, int x, int y, int couleur) {
    int px = x * TAILLE_CASE;
    int py = y * TAILLE_CASE;
    int end_x = px + TAILLE_CASE;
    int end_y = py + TAILLE_CASE;

    for (int i = px; i < end_x; i++) {
        for (int j = py; j < end_y; j++) {
            mlx_pixel_put(map->graphics.mlx, map->graphics.fenetre, i, j, couleur);
        }
    }
}

void dessiner_carte_rec(t_map *map, int x, int y) {
    int couleur = 0xFFFF90;

    char cell = map->carte[y][x];
    switch (cell) {
        case '1': couleur = 0x009FF0; break;
        case 'P': couleur = 0xFF0000; break;
        case 'C': couleur = 0x00FF00; break;
        case 'E': couleur = 0x0000FF; break;
        case '0': couleur = 0xFFFFFF; break;
    }

    dessiner_case(map, x, y, couleur);

    if (x < map->largeur - 1) {
        dessiner_carte_rec(map, x + 1, y);
    } else if (y < map->hauteur - 1) {
        dessiner_carte_rec(map, 0, y + 1);
    }
}

void dessiner_carte(t_map *map) {
    dessiner_carte_rec(map, 0, 0);
}
