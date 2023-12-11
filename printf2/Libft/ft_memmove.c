/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:43:00 by ghumm             #+#    #+#             */
/*   Updated: 2023/10/25 12:23:11 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	dest1 = dest;
	src1 = src;
	if (src1 < dest1)
	{
		src1 += n;
		dest1 += n;
		while (n--)
			*(--dest1) = *(--src1);
	}
	else
	{
		while (n--)
			*dest1++ = *src1++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main() {
    char *source = "12345678987654321 !";
    char destination[21];
	
	printf("Source: %s\n", source);

    ft_memmove(destination, source + 4, 12);
    
    printf("Destination: %s\n", destination);

    return 0;
}*/
