/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:57:00 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/13 16:45:39 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	j;

	j = 0;
	while (str[j] >= 48 && str[j] <= 57)
	{
		j++;
	}
	if (str[j] == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
