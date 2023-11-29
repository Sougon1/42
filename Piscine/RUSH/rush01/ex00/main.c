/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:35:02 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 16:13:10 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	main(int argc, char **argv)
{
	int	*tab;
	int	**grid;

	if (argc != 2)
	{
		write(2, "Error : number of parameter must be 1\n", 38);
		return (0);
	}
	if (!(arg_validator(argv[1])))
	{
		write(2, "Error : parameter is invalid\n", 29);
		return (0);
	}
	tab = arg_to_int(argv[1]);
	grid = init_grid();
	first_fill(grid, tab);
	second_fill(grid, tab);
	third_fill(grid, tab);
	is_valid(grid, 0, tab);
	display_grid(grid);
	free_tabs(grid, tab);
}
