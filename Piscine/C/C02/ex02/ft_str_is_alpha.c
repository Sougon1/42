/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:40:15 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/13 16:43:48 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<string.h>
#include<unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	j;

	j = 0;
	while ((str[j] >= 65 && str[j] <= 90) || (str[j] >= 97 && str[j] <= 122))
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
