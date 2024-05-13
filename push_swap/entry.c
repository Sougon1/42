/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 16:39:59 by ghumm            ###   ########.fr       */
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
	if (a_size < 101)
		max_size = 30;
	else
		max_size = 65;
	while (a_size > 0)
	{
		start_index = a_size - max_size;
		end_index = a_size;
		if (start_index < 0)
		{
			start_index = 0;
		}
		current_a = a_list->a_top;
		count = 0;
		while (start_index < end_index)
		{
			if (current_a->index > a_size - max_size
				&& current_a->index <= a_size)
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
		a_size -= max_size;
		sort(a_list, b_list);
		index_tab_a(a_list, tab);
		one_two = 0;
	}
}

void	push_index_b(stack *a_list, stack *b_list, int *tab)
{
	int	a_size;
	int	max_chunk;
	int	one_two;

	a_size = a_list->size;
	max_chunk = max_size(&a_size);
	one_two = 1;
	while (a_size > 0)
	{
		// se_index(a_list, b_list, a_size, max_chunk);
		push_chunk(a_list, b_list, max_chunk, &a_size, &one_two);
		a_size -= max_chunk;
		sort(a_list, b_list);
		index_tab_a(a_list, tab);
		one_two = 0;
	}
}

void	push_chunk(stack *a_list, stack *b_list, int max_chunk, int *a_size, int *one_two)
{
	int	start_index;
	int	end_index;
	int	count;
	
	count = 0;
	start_index = s_index(&a_size, max_chunk);
	end_index = *a_size;
	while (start_index < end_index)
	{
		if (push_element_if_needed(a_list, b_list, &start_index, &end_index) == 1)
		{
			count--;
			start_index++;
		}
		else
			rotate_if_needed(a_list, b_list, one_two);
		count++;
	}
	while (count-- > 0)
		rotate(a_list, b_list, 'a');

}

int	s_index(int *a_size, int max_chunk)
{
	int	start_index;
	
	if (*a_size - max_chunk < 0)
		start_index = 0;
	else
		start_index = *a_size - max_chunk;
	return (start_index);
}

int	push_element_if_needed(stack *a_list, stack *b_list, int *start_index,
		int *end_index)
{
	stack_element	*current_a;

	current_a = a_list->a_top;
	if (current_a->index > *start_index && current_a->index <= *end_index)
	{
		push(a_list, b_list, 'b');
		return (1);
	}
	else
		return (0);
}

void	rotate_if_needed(stack *a_list, stack *b_list, int *one_two)
{
	if (*one_two == 1)
	{
		rotate(a_list, b_list, 'a');
	}
	else if (*one_two == 0)
	{
		rrotate(a_list, b_list, 'a');
	}
}

int	max_size(int *a_size)
{
	int	max_size_a;

	if (*a_size < 101)
		max_size_a = 30;
	else
		max_size_a = 65;
	return (max_size_a);
}