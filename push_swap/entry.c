/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 14:56:16 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sorted(int argc, stack *a_list, stack *b_list)
{
	while (a_list)
	{
		if (is_sorted(a_list))
			break ;
		else if (argc == 3 || argc == 4 || argc == 6)
		{
			infdix(argc, a_list);
			break ;
		}
		else
		{
			ind_tab(a_list, b_list);
			break ;
		}
	}
}


void	ind_tab(stack *a_list, stack *b_list)
{
	int				*tab;
	int				i;
	stack_element	*current_a;

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

void	index_tab_a(stack *a_list, int *tab)
{
	int				i;
	stack_element	*current_a;

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

void	push_index_b(stack *a_list, stack *b_list, int *tab)
{
	int				index_count;
	int				max_size;
	int				a_size;
	int				start_index;
	int				end_index;
	stack_element	*current_a;
	int				one_two;
	int				count;

	a_size = a_list->size;
	one_two = 1;
	current_a = a_list->a_top;
	index_count = a_size;
	if (a_size < 101)
		max_size = 30;
	else
		max_size = 65;
	while (index_count > 0)
	{
		start_index = index_count - max_size;
		end_index = index_count;
		if (start_index < 0)
		{
			start_index = 0;
		}
		current_a = a_list->a_top;
		count = 0;
		while (start_index < end_index)
		{
			if (current_a->index > index_count - max_size
				&& current_a->index <= index_count)
			{
				push(a_list, b_list, 'b');
				start_index++;
				count--;
			}
			else if (one_two == 1)
			{
				rotate(a_list, b_list, 'a');
				count++;
			}
			else if (one_two == 0)
			{
				rrotate(a_list, b_list, 'a');
				count++;
			}
			current_a = a_list->a_top;
		}
		while (count > 0)
		{
			rotate(a_list, b_list, 'a');
			count--;
		}
		index_count -= max_size;
		sort(a_list, b_list);
		index_tab_a(a_list, tab);
		one_two = 0;
	}
}

// A FAIRE :
// MAX SIZE 30 POUR 100
// MAX SIZE 60 POUR 500



