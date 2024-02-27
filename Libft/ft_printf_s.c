/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:52 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/27 15:25:22 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char *str)
{
	int	count;

	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	count = 0;
	while (*str != '\0')
	{
		if (write(1, str, 1) == -1)
			return (-1);
		count++;
		str++;
	}
	return (count);
}
