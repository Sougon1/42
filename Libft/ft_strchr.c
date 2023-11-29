/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:25:03 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 15:19:18 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = " ";
	char	*result = ft_strchr(str, ' ');

	if (result != NULL) {
		printf("Le caractère 'k' trouvé à l'index %s .\n", result);
	} else {
		printf("Le caractère 'k' n'a pas été trouvé dans la chaîne.\n");
		}
}*/
