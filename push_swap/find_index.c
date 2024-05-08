/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:13 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/08 12:28:14 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 5 FONCTIONS ICI

#include "ps.h"

int	find_min_index_a(stack *a_list)
{
	stack_element	*current;
	int				min_index;
	int				min_value;
	int				i;

	if (is_empty(a_list, 'a'))
	{
		return (-1);
	}
	current = a_list->a_top;
	min_index = 0;
	min_value = current->value;
	i = 0;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

int	find_min_index_b(stack *b_list)
{
	stack_element	*current;
	int				min_index;
	int				min_value;
	int				i;

	if (b_list->b_top == NULL)
	{
		return (-1);
	}
	current = b_list->b_top;
	min_index = 0;
	min_value = current->value;
	i = 0;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

int	find_max_index_b(stack *b_list)
{
	stack_element	*current;
	int				max_index;
	int				max_value;
	int				i;

	if (is_empty(b_list, 'b'))
	{
		return (-1);
	}
	current = b_list->b_top;
	max_index = 0;
	max_value = current->value;
	i = 0;
	while (current != NULL)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

int	find_max_index_a(stack *a_list)
{
	stack_element	*current;
	int				max_index;
	int				max_value;
	int				i;

	if (is_empty(a_list, 'a'))
	{
		return (-1);
	}
	current = a_list->a_top;
	max_index = 0;
	max_value = current->value;
	i = 0;
	while (current != NULL)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

int	is_empty(stack *stack, char pile)
{
	if (pile == 'a')
	{
		if (stack->a_top == NULL)
			return (1);
	}
	else if (pile == 'b')
	{
		if (stack->b_top == NULL)
			return (1);
	}
	return (0);
}
