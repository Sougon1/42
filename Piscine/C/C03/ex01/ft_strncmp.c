/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:35:10 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/14 11:49:55 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*s1 - *s2);
}

/*
int main(int argc, char const *argv[])
{
	char s1[] = "ABCDEFG";
	char s2[] = "ABCDefG";

	printf("%d\n", ft_strncmp(s1, s2, 5));
	return 0;
}
*/