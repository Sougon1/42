/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:06:28 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Fonction pour vérifier s'il y a un doublon dans la liste
int	has_duplicates(t_stack *stack, int value)
{
	t_stack_element	*current;

	current = stack->a_top;
	while (current != NULL)
	{
		if (current->value == value)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

void	duplicate(t_stack *a_list, int value)
{
	if (has_duplicates(a_list, value) == 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

// Fonction pour ajouter un élément à la pile tout en vérifiant les doublons
void	pushtab(t_stack *a_list, int value)
{
	t_stack_element	*newnode;
	t_stack_element	*current;

	duplicate(a_list, value);
	newnode = (t_stack_element *)malloc(sizeof(t_stack_element));
	if (!newnode)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!a_list->a_top)
		a_list->a_top = newnode;
	else
	{
		current = a_list->a_top;
		while (current->next)
			current = current->next;
		current->next = newnode;
		newnode->prev = current;
	}
	a_list->size++;
}

// Fonction pour creeer le Tableau A
void	tableaua(char *argv, t_stack *a_list)
{
	long long	i;
	int			neg;

	neg = 1;
	while (*argv)
	{
		if (*argv == '-')
		{
			neg = -1;
			argv++;
		}
		else if (ft_isdigit(*argv))
		{
			i = securityint(argv);
			while (ft_isdigit(*argv))
				argv++;
			pushtab(a_list, neg * i);
			argv++;
			neg = 1;
		}
		else
			argv++;
	}
}
