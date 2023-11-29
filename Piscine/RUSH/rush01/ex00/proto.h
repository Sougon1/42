/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:30:19 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 17:11:49 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H
# include <unistd.h>
# include <stdlib.h>

int		*arg_to_int(char *str);
int		**init_grid(void);
int		display_grid(int **grid);
void	first_fill(int **grid, int *tab);
void	second_fill(int **grid, int *tab);
void	third_fill(int **grid, int *tab);
void	free_tabs(int **grid, int *tab);
int		view_count_xl(int **grid, int index);
int		view_count_xr(int **grid, int index);
int		view_count_yu(int **grid, int index);
int		view_count_yd(int **grid, int index);
int		view_count_chooser(int **grid, int index);
int		is_on_row(int **grid, int nb, int row);
int		is_on_line(int **grid, int nb, int line);
int		is_valid(int **grid, int pos, int *tab);
int		count_parser(int **grid, int *tab);
int		arg_validator(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		no_solutions(int **grid);

#endif
