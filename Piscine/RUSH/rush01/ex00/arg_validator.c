/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:56:42 by adenord           #+#    #+#             */
/*   Updated: 2023/06/17 17:48:05 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	arg_validator(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (i <= 30)
	{
		if (str[i] < 49 || str[i] > 52)
			return (0);
		i += 2;
	}
	i = 1;
	while (i <= 29)
	{
		if (str[i] != ' ')
			return (0);
		i += 2;
	}
	return (1);
}
