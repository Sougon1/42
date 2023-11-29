/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:21:01 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/19 11:25:48 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	tailledest;
	unsigned int	taillesrc;
	unsigned int	i;

	tailledest = 0;
	taillesrc = 0;
	i = 0;
	while (dest[tailledest] != '\0' && tailledest < size)
		tailledest++;
	while (src[taillesrc] != '\0')
		taillesrc++;
	i = tailledest;
	while (i < size - 1 && src[i - tailledest] != '\0')
	{
		dest[i] = src[i - tailledest];
		i++;
	}
	if (tailledest < size)
		dest[i] = '\0';
	return (tailledest + taillesrc);
}


int	main(void)
{
	char src[] = "123456789";
	char dest[20] = "abcd";
	unsigned int size = 12;

    unsigned int tailledest = ft_strlcat(dest, src, size);

	printf("Contenu de dest : %s\n", dest);
	printf("Longueur de dest : %d\n", tailledest);
}