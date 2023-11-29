/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:33:58 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/19 11:31:36 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_sort_int_tab(int	*tab, int size)
{
	int	debut;
	int	fin;
	int	vide;

	debut = 0;
	while (debut < size - 1)
	{
		fin = debut + 1;
		while (fin < size)
		{
			if (tab[debut] > tab[fin])
			{
				vide = tab[debut];
				tab[debut] = tab[fin];
				tab[fin] = vide;
			}
			fin++;
		}
		debut++;
	}
}

/*
int main(void)
{
	int tab[] = {5, 2, 1, 4, 3};
	int size = 5;
	ft_sort_int_tab(tab, size);
	
	int i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
}*/