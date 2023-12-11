/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:31:50 by ghumm             #+#    #+#             */
/*   Updated: 2023/10/24 11:52:22 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	v;

	v = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (size - 1 > v && src[v] != 0)
	{
		dst[v] = src[v];
		v++;
	}
	dst[v] = '\0';
	v = 0;
	while (src[v] != 0)
		v++;
	return (v);
}
/*
#include <stdio.h>
int main()
{
	char dst[12];
	char *src = "Coucou c'est moi !";

	printf("%ld\n", ft_strlcpy(dst, src, 2));
	printf("%s\n", dst);
    printf("%ld\n", strlen(src));
    printf("%ld\n", strlen(dst));


}*/
