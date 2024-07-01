/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:55:31 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 16:58:03 by ghumm            ###   ########.fr       */
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

typedef struct s_analyse
{
	int			larg_act;
	int			prem_ligne;
	int			ligne_count;
	int			largeur_max;
}				t_analyse;

typedef struct s_images
{
	void		*wall;
	void		*player;
	void		*collectable;
	void		*exit;
	void		*empty;
}				t_images;

typedef struct s_graphics
{
	void		*mlx;
	void		*fenetre;
}				t_graphics;

typedef struct s_map
{
	t_graphics	graphics;
	t_images	images;
	char		carte[MAX_ROWS][MAX_COLS];
	int			largeur;
	int			hauteur;
	int			player_x;
	int			player_y;
	int			c;
}				t_map;

typedef struct s_map_check
{
	char		carte_check[MAX_ROWS][MAX_COLS];
	int			x;
	int			y;
	int			a;
	int			e;
}				t_map_check;

// MAIN OK
int				close_window_t(t_map *map);
void			load_images(t_map *map);
void			event_handling(t_map *map);

// INIT
void			map_init(t_map *map);

// PLAYER MOVEMENT OK
int				moov_player(t_map *map, int new_x, int new_y);
int				key_hook(int keycode, t_map *map);
int				check_keycode(int keycode, int i, t_map *map);

// MAP Security OK
void			security_map(t_map *map);
void			row_cols(t_map *map);
int				count_char(t_map *map, char c);
void			number_e_p(t_map *map);

// MAP BORDER OK
void			check_borders(t_map *map);
void			check_top_bottom_borders(t_map *map);
void			check_internal_values(t_map *map, int row);
void			check_left_right_borders(t_map *map);

// MAP Utilities OK
int				ft_strlen_n(const char *str);
int				search_p_line(t_map *map);
int				search_p_cols(t_map *map);

// MAP Check OK
void			flood_fill_rec(int x, int y, t_map_check *player);
void			map_temp(t_map *map, t_map_check *player);
void			check_map(t_map *map);

// MAP OK
void			treat_buffer(const char *buffer, ssize_t bytes_read,
					t_map *map, t_analyse *analyse);
void			count_row_and_col(int fd, t_map *map);
void			read_map(const char *nom_fichier, t_map *map);

// WINDOW OK
void			draw_case_specific(t_map *map, int x, int y);
void			draw_map(t_map *map);
void			draw_case(t_map *map, int x, int y, void *image);
void			create_window(t_map *map);

#endif