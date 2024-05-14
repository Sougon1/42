/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/14 16:13:43 by ghumm            ###   ########.fr       */
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

// void	push_index_b(stack *a_list, stack *b_list, int *tab)
// {
// 	int				max_size_a;
// 	int				a_size;
// 	int				start_index;
// 	int				end_index;
// 	stack_element	*current_a;
// 	int				one_two;
// 	int				count;

// 	a_size = a_list->size;
// 	one_two = 1;
// 	current_a = a_list->a_top;
// 	max_size_a = max_size(&a_size);
// 	while (a_size > 0)
// 	{
// 		start_index = a_size - max_size_a;
// 		end_index = a_size;
// 		if (start_index < 0)
// 		{
// 			start_index = 0;
// 		}
// 		current_a = a_list->a_top;
// 		count = 0;
// 		while (start_index < end_index)
// 		{
// 			if (current_a->index > a_size - max_size_a
// 				&& current_a->index <= a_size)
// 			{
// 				push(a_list, b_list, 'b');
// 				start_index++;
// 				count--;
// 			}
// 			else if (one_two == 1)
// 			{
// 				rotate(a_list, b_list, 'a');
// 				count++;
// 			}
// 			else if (one_two == 0)
// 			{
// 				rrotate(a_list, b_list, 'a');
// 				count++;
// 			}
// 			current_a = a_list->a_top;
// 		}
// 		while (count > 0)
// 		{
// 			rotate(a_list, b_list, 'a');
// 			count--;
// 		}
// 		a_size -= max_size_a;
// 		sort(a_list, b_list);
// 		index_tab_a(a_list, tab);
// 		one_two = 0;
// 	}
// }

void	push_index_b(stack *a_list, stack *b_list, int *tab)
{
	int	max_size_a;
	int	a_size;
	int	count;

	// int	one_two;
	// int	start_index;
	a_size = a_list->size;
	// one_two = 1;
	max_size_a = max_size(&a_size);
	while (a_size > 0)
	{
		count = 0;
		count = move_elements(a_list, b_list, /*&one_two,*/ max_size_a, &a_size);
		final_rotation(a_list, b_list, count);
		a_size -= max_size_a;
		sort(a_list, b_list);
		index_tab_a(a_list, tab);
		// one_two = 0;
	}
}

int	max_size(int *a_size)
{
	int	max_size_a;

	if (*a_size < 101)
	{
		max_size_a = 30;
	}
	else
		max_size_a = 65;
	return (max_size_a);
}

int	get_start_index(int *a_size, int *max_size_a)
{
	int	start_index;

	start_index = a_size - max_size_a;
	if (start_index < 0)
		start_index = 0;
	return (start_index);
}

int	move_elements(stack *a_list, stack *b_list,
		/*int *one_two,*/ int max_size_a, int *a_size)
{
	int	end_index;
	int	start_index;
	int	count;

	// stack_element	*current_a;
	count = 0;
	// current_a = a_list->a_top;
	end_index = *a_size;
	start_index = get_start_index(a_size, &max_size_a);
	while (start_index < end_index)
	{
		if (push_or(a_list, b_list, *a_size, &max_size_a) == 1)
		{
			count--;
			start_index++;
		}
		else
			rotate_or(a_list, b_list, &count);
	}
	return (count);
}

int	push_or(stack *a_list, stack *b_list, int a_size, int *max_size_a)
{
	stack_element	*current_a;

	current_a = a_list->a_top;
	if (current_a->index > a_size - *max_size_a && current_a->index <= a_size)
	{
		push(a_list, b_list, 'b');
		return (1);
	}
	return (0);
}

int	rotate_or(stack *a_list, stack *b_list, int *count)
{
	static int	one_two;

	one_two = 1;
	if (one_two == 1)
	{
		rotate(a_list, b_list, 'a');
		(*count)++;
		// one_two = 0;
	}
	else
	{
		rrotate(a_list, b_list, 'a');
		(*count)++;
	}
	return (*count);
}

void	final_rotation(stack *a_list, stack *b_list, int count)
{
	while (count > 0)
	{
		rotate(a_list, b_list, 'a');
		count--;
	}
}
