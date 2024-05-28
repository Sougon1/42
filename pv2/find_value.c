/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:46:10 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:02:56 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_max_value_a(t_stack *a_list)
{
	int				max_value;
	t_stack_element	*current;

	if (is_empty(a_list, 'a'))
	{
		return (-1);
	}
	max_value = a_list->a_top->value;
	current = a_list->a_top->next;
	while (current != NULL)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
		}
		current = current->next;
	}
	return (max_value);
}

int	find_min_value_a(t_stack *a_list)
{
	int				min_value;
	t_stack_element	*current;

	if (is_empty(a_list, 'a'))
	{
		return (-1);
	}
	min_value = a_list->a_top->value;
	current = a_list->a_top->next;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
		}
		current = current->next;
	}
	return (min_value);
}

int	find_max_value_b(t_stack *b_list)
{
	int				max_value;
	t_stack_element	*current;

	if (is_empty(b_list, 'b'))
	{
		return (-1);
	}
	max_value = b_list->b_top->value;
	current = b_list->b_top->next;
	while (current != NULL)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
		}
		current = current->next;
	}
	return (max_value);
}

int	find_min_value_b(t_stack *b_list)
{
	int				min_value;
	t_stack_element	*current;

	if (is_empty(b_list, 'b'))
	{
		return (-1);
	}
	min_value = b_list->b_top->value;
	current = b_list->b_top->next;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
		}
		current = current->next;
	}
	return (min_value);
}
