/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:32:53 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 17:12:05 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	count_parser(int **grid, int *tab)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!(view_count_chooser(grid, i) == tab[i]))
			return (0);
		i++;
	}
	return (1);
}
