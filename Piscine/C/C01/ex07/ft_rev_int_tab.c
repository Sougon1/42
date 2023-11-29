/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:41:38 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/19 11:30:21 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	debut;
	int	fin;
	int	vide;

	debut = 0;
	fin = size - 1;
	while (debut < fin)
	{
		vide = tab[debut];
		tab[debut] = tab[fin];
		tab[fin] = vide;
		debut++;
		fin--;
	}
}

/*
int main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	int size = 5;
	ft_rev_int_tab(tab, size);
	
	int i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}*/
