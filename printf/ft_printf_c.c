/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:10 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 13:07:19 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_c(int c)
{
	char	cha;

	cha = (char)c;
	if (write(1, &cha, 1) == -1)
		return (-1);
	return (1);
}
