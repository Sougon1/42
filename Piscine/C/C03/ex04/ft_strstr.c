/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:05 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/20 16:39:28 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*recherche;
	int		j;
	int		i;

	i = 0;
	j = 0;
	recherche = NULL;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (j == 0)
				recherche = &str[i];
			j++;
			if (to_find[j] == '\0')
				return (recherche);
		}
		else
		{
			j = 0;
			recherche = NULL;
		}
		i++;
	}
	return (recherche);
}

int main(void)
{
    char *res;
    char str[] = "Hello worldd world hello";
    char to_find[] = "world";
    res = ft_strstr(str, to_find);
    if (res == NULL)
        printf("Le mot '%s' n'a pas été retrouvé dans '%s'\n", to_find, str);
    else
        printf("Le mot '%s' a été retrouvé dans '%s'\n", to_find, res);
    return 0;
}

