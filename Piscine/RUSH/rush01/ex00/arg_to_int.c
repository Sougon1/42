/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:47:34 by adenord           #+#    #+#             */
/*   Updated: 2023/06/18 09:56:10 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	*arg_to_int(char *str)
{
	int	i;
	int	j;
	int	integer;
	int	*tab;

	i = 0;
	j = 0;
	integer = 0;
	tab = (int *)malloc(sizeof(int) * 16);
	while (str[i])
	{
		tab[j] = ft_atoi(&str[i]);
		j++;
		i += 2;
	}
	return (tab);
}
