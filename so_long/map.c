/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/24 12:31:17 by ghumm            ###   ########.fr       */
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
    // map->carte[analyse->ligne_count][analyse->largeur_actuelle] = '\0';
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
    
    printf("\ntaille largeur = %d\ntaille hauteur = %d\n", map->largeur, map->hauteur);


    // int o = 0;
    // int j = 0;
    // printf("AFFICHE 1 : \n");
    // while (j < map->hauteur) {
    //     o = 0;
    //     while (o < map->largeur + 1) {
    //         print_visible_whitespace(map->carte[j][o++]);
    //     }
    //     printf("\n");
    //     j++;
    // }
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
    map->graphics.fenetre = mlx_new_window(map->graphics.mlx, map->largeur * TAILLE_CASE, map->hauteur * TAILLE_CASE, "./so_long");

    if (map->graphics.fenetre == NULL) {
        ft_printf("Erreur lors de la création de la fenêtre\n");
        exit(1);
    }
}


void dessiner_case_specifique(t_map *map, int x, int y) {
    void *image;

    if (map->carte[y][x] == '1') {
        image = map->images.wall;
    } else if (map->carte[y][x] == 'P') {
        image = map->images.player;
    } else if (map->carte[y][x] == 'C') {
        image = map->images.collectable;
    } else if (map->carte[y][x] == 'E') {
        image = map->images.exit;
    } else if (map->carte[y][x] == '0') {
        image = map->images.empty;
    } else {
        image = map->images.empty; // Default image
    }

    dessiner_case(map, x, y, image);
}


void dessiner_carte(t_map *map) {
    int x = 0;
    int y = 0;

    while (y < map->hauteur) {
        x = 0;
        while (x < map->largeur) {
            dessiner_case_specifique(map, x, y);
            x++;
        }
        y++;
    }
}


void dessiner_case(t_map *map, int x, int y, void *image) {
    int px = x * TAILLE_CASE;
    int py = y * TAILLE_CASE;
    mlx_put_image_to_window(map->graphics.mlx, map->graphics.fenetre, image, px, py);
}

