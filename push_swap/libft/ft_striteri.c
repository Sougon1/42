/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:09:30 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/03 14:43:07 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	n;
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = ft_strlen(s);
	n = 0;
	while (n < i)
	{
		f(n, &s[n]);
		n++;
	}
}
