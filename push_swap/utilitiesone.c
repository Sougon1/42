/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitiesone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:01:13 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/17 17:06:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	max_size(int *a_size)
{
	int	max_size_a;

	if (*a_size < 101)
		max_size_a = 20;
	else
		max_size_a = 50;
	return (max_size_a);
}

int	get_start_index(int *a_size, int *max_size_a)
{
	int	start_index;

	start_index = *a_size - *max_size_a;
	if (start_index < 0)
		start_index = 0;
	return (start_index);
}

void	move_elements(stack *a_list, stack *b_list, int max_size_a, int *a_size)
{
	int	end_index;
	int	start_index;
	int	count;

	count = 0;
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
			rotate_or(a_list, b_list);
	}
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

void	rotate_or(stack *a_list, stack *b_list)
{
	static int	one_two;

	one_two = 1;
	if (one_two == 1)
	{
		rotate(a_list, b_list, 'a');
		one_two = 0;
	}
	else
	{
		rrotate(a_list, b_list, 'a');
	}
}
