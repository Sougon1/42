/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:55:32 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/21 18:14:36 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_swap(char **a, char **b)
{
	char	*vide;

	vide = *a;
	*a = *b;
	*b = vide;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_sort_params(int ac, char **av)
{
	int	i;
	int	j;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			j = i + 1;
			while (j < ac)
			{
				if (ft_strcmp(av[i], av[j]) > 0)
					ft_swap(&av[i], &av[j]);
				j++;
			}
			i++;
		}
		i = 1;
		while (i < ac)
		{
			ft_putstr(av[i]);
			i++;
		}
	}
	return (ac);
}

int	main(int ac, char **av)
{
	ft_sort_params(ac, av);
}
