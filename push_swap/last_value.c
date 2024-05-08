/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:08 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 12:32:50 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_last_value_a(stack *a_list)
{
	stack_element	*current;

	if (is_empty(a_list, 'a'))
	{
		return (-1);
	}
	current = a_list->a_top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current->value);
}

int	find_last_value_b(stack *b_list)
{
	stack_element	*current;

	if (is_empty(b_list, 'b'))
	{
		return (-1);
	}
	current = b_list->b_top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current->value);
}
