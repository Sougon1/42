/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:47:39 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/21 18:26:16 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
        return (0);
    }

    int size = max - min;
    *range = malloc(size * sizeof(int));

    if (*range == NULL)
    	return (0);

    int *ptr = *range;
    int value = min;

    while (value < max)
    {
        *ptr = value;
        ptr++;
        value++;
    }
    return (size);
}

int main()
{
    int *range;
    int min = 11;
    int max = 10;

    int size = ft_ultimate_range(&range, min, max);

    if (range == NULL)
    {
        printf("Erreur : min est supérieur ou égal à max\n");
        return 0;
    }

    printf("Tableau d'entiers : ");
    int i = 0;
    while (i < size)
    {
        printf("%d ", range[i]);
        i++;
    }
    printf("\n");

    return 0;
}


