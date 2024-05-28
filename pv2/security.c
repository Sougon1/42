/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:59 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/08 10:42:51 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Fonction qui verifie les arguments
int	security(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigitnospace(argv[i]) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		if ((argv[i] == '-' || argv[i] == '+') && ft_isdigit(argv[i + 1]) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_isdigitnospace(int a)
{
	if ((a >= 48 && a <= 57) || a == 32 || a == 45 || a == 43)
		return (1);
	return (0);
}
