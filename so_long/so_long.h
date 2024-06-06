/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:55:31 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/06 17:15:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define MAX_ROWS 100
# define MAX_COLS 100
# define TAILLE_CASE 50

typedef struct {
    void *mlx;
    void *fenetre;
    char carte[MAX_ROWS][MAX_COLS];
    int largeur;
    int hauteur;
} t_map;

void lire_carte(const char *nom_fichier, char carte[MAX_ROWS][MAX_COLS], int *largeur, int *hauteur);
void creer_fenetre(t_map *map);
void dessiner_carte_rec(t_map *map, int x, int y);
void dessiner_carte(t_map *map);


// // MAIN
// int close_window(void *param);
// int key_hook(int keycode, void *param);


// // MAP
// void lire_ligne(FILE *fichier, char carte[MAX_ROWS][MAX_COLS], int row, int hauteur);
// void lire_carte(const char *nom_fichier, t_map *map);
// void creer_fenetre(t_map *map);
// void dessiner_carte_rec(t_map *map, int x, int y);
// void dessiner_carte(t_map *map);



// So_long



#endif