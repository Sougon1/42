/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:55:31 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/24 12:30:45 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define MIN_ROWS 4
# define MIN_COLS 4
# define MAX_ROWS 20
# define MAX_COLS 20
# define TAILLE_CASE 70
# define BUFFER_SIZE 1024

typedef struct {
    int largeur_actuelle;
    int prem_ligne;
    int ligne_count;
    int largeur_max;
} t_analyse;

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     *img_data;
    int     img_width;
    int     img_height;
    void    *img_mario; // Ajout pour l'image Mario
} t_data;


typedef struct s_images {
    void *wall;
    void *player;
    void *collectable;
    void *exit;
    void *empty;
} t_images;



typedef struct {
    void *mlx;
    void *fenetre;
} t_graphics;

typedef struct {
    t_graphics graphics;
    t_images images;
    char carte[MAX_ROWS][MAX_COLS];
    int largeur;
    int hauteur;
    int c;
} t_map;

typedef struct {
    char carte_check[MAX_ROWS][MAX_COLS];
    int x;
    int y;
    int a;
    int e;
} t_map_check; 



// MAIN
// int close_window(void *param);
// int key_hook(int keycode, void *param);
void dessiner_case_specifique(t_map *map, int x, int y);

// MAP
void lire_carte(const char *nom_fichier, t_map *map);
void creer_fenetre(t_map *map);
void dessiner_carte(t_map *map);

// void dessiner_case(t_map *map, int x, int y, int couleur);
void dessiner_case(t_map *map, int x, int y, void *image);



// MAP Security
void    security_map(t_map *map);
void    row_cols(t_map *map);
int count_char(t_map *map, char c);
void number_e_p(t_map *map);
void check_borders(t_map *map);

// MAP Utilities
int ft_strlen_n(const char *str);
int search_p_line(t_map *map);
int search_p_cols(t_map *map);

// MAP Check
void    check_map(t_map *map);


// So_long




// TEMP

void dessiner_carte_rec(t_map *map, int x, int y);

#endif