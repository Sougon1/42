/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:13:27 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/22 14:09:55 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	lon;
	int	*tab;
	int	*p;

	lon = max - min;
	if (lon <= 0)
		return (NULL);
	tab = malloc(lon * sizeof(int));
	if (tab != NULL)
	{
		p = tab;
		while (min < max)
			*p++ = min++;
		*p = '\0';
	}
	return (tab);
}

/*
int	main(void)
{
	int	min = -10;
	int max = 10;

	int *val = ft_range(min, max);

	if (val == NULL)
	{
		printf("Min est superieur ou egale a Max\n");
		return (1);
	}
	int *a = val;
	int lon = max - min;
	while (a < val + lon)
		{
			printf("%d ", *a);
			a++;
		}
	printf("\n");
}*/
