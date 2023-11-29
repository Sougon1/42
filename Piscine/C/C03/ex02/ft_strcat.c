/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:50:40 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/19 11:24:59 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*dest1;

	dest1 = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest1);
}

/*
int	main(void)
{
	char src[] = "def";
	char dest[10] = "abc";
	printf("%s\n", ft_strcat(dest, src));
}*/
