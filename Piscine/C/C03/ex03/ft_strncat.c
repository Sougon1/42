/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:16:53 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/14 12:45:30 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest1;

	dest1 = dest;
	while (*dest)
	{
		dest++;
	}
	while (nb > 0 && *src)
	{
		*dest = *src;
		src++;
		dest++;
		nb--;
	}
	*dest = '\0';
	return (dest1);
}

/*
int	main(void)
{
	char dest[10] = "abc";
	char src[] = "123456789";
	unsigned int nb = 5;
	printf("%s\n", ft_strncat(dest, src, nb));
}*/