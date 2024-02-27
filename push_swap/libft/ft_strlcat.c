/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:28:50 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/13 16:03:58 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	v1;
	size_t	v2;

	v1 = 0;
	v2 = 0;
	if (!dst && src && size == 0)
		return (ft_strlen(src));
	while (v1 < size && dst[v1])
		v1++;
	while (src[v2] && v1 + 1 < size)
		dst[v1++] = src[v2++];
	if (v1 < size)
		dst[v1] = '\0';
	while (src[v2++])
		v1++;
	return (v1);
}
/*
int main()
{
	char dst[10]= "ab";
	char *src = "12345";

	printf("%ld\n", ft_strlcat(dst, src, 5));
	printf("%s\n", dst);
	printf("%s\n", src);
}*/
