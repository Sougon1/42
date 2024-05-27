/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:42:51 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sorted(int argc, t_stack *a_list, t_stack *b_list)
{
	while (a_list)
	{
		if (is_sorted(a_list))
			break ;
		else if (argc == 3 || argc == 4 || argc == 6)
		{
			infdix(argc, a_list, b_list);
			break ;
		}
		else
		{
			ind_tab(a_list, b_list);
			break ;
		}
	}
}

void	ind_tab(t_stack *a_list, t_stack *b_list)
{
	int				*tab;
	int				i;
	t_stack_element	*current_a;

	tab = malloc(sizeof(int) * a_list->size + 1);
	if (!tab)
		return ;
	current_a = a_list->a_top;
	i = 1;
	while (current_a != NULL)
	{
		tab[i] = current_a->value;
		current_a = current_a->next;
		if (current_a == NULL)
			break ;
		i++;
	}
	bubble_sort(tab, a_list->size + 1);
	index_tab_a(a_list, tab);
	push_index_b(a_list, b_list, tab);
	free(tab);
}

void	bubble_sort(int *tab, int taille)
{
	int	i;
	int	temp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 1;
		while (i < taille - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	index_tab_a(t_stack *a_list, int *tab)
{
	int				i;
	t_stack_element	*current_a;

	i = 1;
	while (i < a_list->size + 1)
	{
		current_a = a_list->a_top;
		while (current_a)
		{
			if (tab[i] == current_a->value)
			{
				current_a->index = i;
			}
			current_a = current_a->next;
		}
		i++;
	}
}

void	push_index_b(t_stack *a_list, t_stack *b_list, int *tab)
{
	int	max_size_a;
	int	a_size;

	a_size = a_list->size;
	max_size_a = max_size(&a_size);
	while (!is_empty(a_list, 'a'))
	{
		move_elements(a_list, b_list, max_size_a, &a_size);
		a_size -= max_size_a;
		index_tab_a(a_list, tab);
	}
	sort(a_list, b_list);
}
