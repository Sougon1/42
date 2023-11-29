/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:00:14 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/11 17:33:22 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*dest1;

	dest1 = dest;
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (dest1);
}

/*
int main(void)
{
	char *src = "Hello World!";
	char dest[20];

	unsigned int n = 8;

	printf("%s\n", ft_strncpy(dest, src, n));
}*/