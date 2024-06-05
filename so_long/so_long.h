/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:55:31 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/05 17:29:44 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define MAX_ROWS 100
# define MAX_COLS 100
# define TAILLE_CASE 50


// MAIN


// MAP
void lire_carte(const char *nom_fichier, char carte[MAX_ROWS][MAX_COLS], int *largeur, int *hauteur);
void creer_fenetre(int largeur, int hauteur)
void dessiner_carte_rec(void *mlx, void *fenetre, char carte[MAX_ROWS][MAX_COLS], int x, int y, int largeur, int hauteur);
void dessiner_carte(void *mlx, void *fenetre, char carte[MAX_ROWS][MAX_COLS], int largeur, int hauteur);



// So_long



#endif