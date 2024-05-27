/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_infdix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:49:14 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/29 10:33:04 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	infdix(int argc, t_stack *a_list, t_stack *b_list)
{
	(void) argc;
	if (a_list->size == 2)
		swap(a_list, b_list, 'a');
	else if (a_list->size == 3)
		tree(a_list, b_list);
	else if (a_list->size == 5)
		five(a_list, b_list);
}

void	tree(t_stack *a_list, t_stack *b_list)
{
	t_stack_element	*current;
	int				max_index_value_a;

	current = a_list->a_top;
	max_index_value_a = find_max_index_a(a_list);
	while (max_index_value_a++ < 2)
		rrotate(a_list, b_list, 'a');
	current = a_list->a_top;
	if (current->value > current->next->value)
		swap(a_list, b_list, 'a');
}

void	five(t_stack *a_list, t_stack *b_list)
{
	int	index_min_value_a;
	int	i;

	i = 2;
	while (i-- > 0)
	{
		index_min_value_a = find_min_index_a(a_list);
		while (index_min_value_a-- > 0)
			rotate(a_list, b_list, 'a');
		push(a_list, b_list, 'b');
	}
	tree(a_list, b_list);
	while (!is_empty(b_list, 'b'))
		push(a_list, b_list, 'a');
}

// Verification si la pile est trier
int	is_sorted(t_stack *stack)
{
	t_stack_element	*current;

	current = stack->a_top;
	while (current != NULL && current->next != NULL)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}
// 0 = Pas trier
// 1 = Trier

void	sort(t_stack *a_list, t_stack *b_list)
{
	int	rotation;
	int	max_index;

	while (!is_empty(b_list, 'b'))
	{
		max_index = find_max_index_b(b_list);
		if (max_index <= b_list->size / 2)
		{
			while (max_index != 0)
			{
				rotate(a_list, b_list, 'b');
				max_index--;
			}
		}
		else
		{
			rotation = b_list->size - max_index;
			while (rotation > 0)
			{
				rrotate(a_list, b_list, 'b');
				rotation--;
			}
		}
		push(a_list, b_list, 'a');
	}
}
