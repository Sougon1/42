/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:55:31 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/07 17:44:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define MAX_ROWS 16
# define MAX_COLS 16
# define TAILLE_CASE 80

typedef struct {
    void *mlx;
    void *fenetre;
    char carte[MAX_ROWS][MAX_COLS];
    int largeur;
    int hauteur;
    int taille_case; // Taille des cases calculée dynamiquement
} t_map;




// MAIN
// int close_window(void *param);
// int key_hook(int keycode, void *param);


// MAP
void lire_carte(const char *nom_fichier, t_map *map);
void creer_fenetre(t_map *map);
void dessiner_carte(t_map *map);

// Security_MAP
void    security_map(t_map *map);
void    row_cols(t_map *map);
int count_char(t_map *map, char c);
void number_e_p(t_map *map);
void check_borders(t_map *map);


// So_long



#endif