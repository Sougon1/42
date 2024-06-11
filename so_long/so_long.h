/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:55:31 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/11 17:42:01 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define MIN_ROWS 4
# define MIN_COLS 4
# define MAX_ROWS 18
# define MAX_COLS 18
# define TAILLE_CASE 80
# define BUFFER_SIZE 1024

typedef struct {
    int largeur_actuelle;
    int prem_ligne;
    int ligne_count;
    int largeur_max;
} t_analyse;

typedef struct {
    void *mlx;
    void *fenetre;
} t_graphics;

typedef struct {
    t_graphics graphics;
    char carte[MAX_ROWS][MAX_COLS];
    int largeur;
    int hauteur;
} t_map;

typedef struct {
    int x;
    int y;
} t_player; 



// MAIN
// int close_window(void *param);
// int key_hook(int keycode, void *param);


// MAP
void lire_carte(const char *nom_fichier, t_map *map);
void creer_fenetre(t_map *map);
void dessiner_carte(t_map *map);

// MAP Security
void    security_map(t_map *map);
void    row_cols(t_map *map);
int count_char(t_map *map, char c);
void number_e_p(t_map *map);
void check_borders(t_map *map);

// MAP Utilities
int ft_strlen_n(const char *str);

// MAP Check
void    check_map(t_map *map);


// So_long




// TEMP


#endif