/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:18:33 by ghumm             #+#    #+#             */
/*   Updated: 2024/07/01 15:02:28 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	treat_buffer(const char *buffer, ssize_t bytes_read, t_map *map,
		t_analyse *analyse)
{
	ssize_t	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			map->carte[analyse->ligne_count][analyse->larg_act] = '\0';
			analyse->ligne_count++;
			if (analyse->larg_act > analyse->largeur_max)
				analyse->largeur_max = analyse->larg_act;
			analyse->larg_act = 0;
			if (analyse->prem_ligne)
			{
				map->largeur = analyse->largeur_max;
				analyse->prem_ligne = 0;
			}
		}
		else
		{
			map->carte[analyse->ligne_count][analyse->larg_act] = buffer[i];
			analyse->larg_act++;
		}
		i++;
	}
}

void	count_row_and_col(int fd, t_map *map)
{
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE];
	t_analyse	analyse;

	analyse.larg_act = 0;
	analyse.prem_ligne = 1;
	analyse.ligne_count = 0;
	analyse.largeur_max = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while ((bytes_read) > 0)
	{
		treat_buffer(buffer, bytes_read, map, &analyse);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	map->hauteur = analyse.ligne_count + 1;
	if (bytes_read == -1)
	{
		perror("Erreur lors de la lecture du fichier");
		exit(EXIT_FAILURE);
	}
}

void	read_map(const char *nom_fichier, t_map *map)
{
	int	fd;

	fd = open(nom_fichier, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	count_row_and_col(fd, map);
	if (close(fd) == -1)
	{
		perror("Erreur lors de la fermeture du fichier");
		exit(EXIT_FAILURE);
	}
	security_map(map);
}
