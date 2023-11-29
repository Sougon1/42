/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:06:48 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/11 17:37:57 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest1;

	dest1 = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest1);
}

/*
int main(void)
{
	char src[] = "Hello World!";
	char dest[15];

	printf("%s\n", ft_strcpy(dest, src));
}
*/