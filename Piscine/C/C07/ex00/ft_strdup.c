/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:59:07 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/22 14:08:17 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{	
	int		lon;
	char	*dup;
	char	*p;

	lon = ft_strlen(src) + 1;
	dup = malloc(lon * sizeof(char));
	if (dup != NULL)
	{
		p = dup;
		while (*src != '\0')
			*p++ = *src++;
		*p = '\0';
	}
	return (dup);
}

/*
int	main(void)
{
	char	*src;
	char	*duplication;
   
	src = "Hello World";
	duplication = ft_strdup(src);

	if (duplication != NULL)
	{
		printf("str = %s\n", src);
		printf("duplucation = %s\n", duplication);
	}
}*/
