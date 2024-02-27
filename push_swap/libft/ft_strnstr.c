/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:15:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/13 16:33:04 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	v;

	i = 0;
	v = ft_strlen(little);
	if (!big && little && len == 0)
		return (NULL);
	if (v == 0)
		return ((char *)big);
	while (*big != '\0' && len >= v)
	{
		i = 0;
		while (i < v && big[i] == little[i])
			i++;
		if (i == v)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main() {
    const char *result = ft_strnstr(NULL, "test", 0);

    if (result == NULL) {
        printf("Test passed: returned NULL as expected.\n");
    } else {
        printf("Test failed: did not return NULL as expected.\n");
    }

    return 0;
}*/
/*
int main()
{
    char *str = "Hello worldd world hello";
    char *to_find = "hello";
	size_t taille = 30;

   char *res = ft_strnstr(str, to_find, taille);
	char *res2 = strnstr(str, to_find, taille);

   if (res == NULL)
        printf("Le mot '%s' n'a pas été retrouvé dans '%s'\n", to_find, str);
    else
        printf("Le mot '%s' a été retrouvé dans '%s'\n", to_find, res);

    if (res2 == NULL)
         printf("Le mot '%s' n'a pas été retrouvé dans '%s'\n", to_find, str);
    else
        printf("Le mot '%s' a été retrouvé dans '%s'\n", to_find, res2);

return 0;
}*/
