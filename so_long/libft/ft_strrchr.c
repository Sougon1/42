/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:17:12 by ghumm             #+#    #+#             */
/*   Updated: 2023/10/25 10:55:37 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char *)(s + a));
		a--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char *str = "Hello World !";

	char *res = ft_strrchr(str, 'o');
	
	if (res != NULL)
		printf("caractere o est trouvee a la %s position\n", res);
	else
		printf("caratere non trouvee\n");
}*/
