/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_infdix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:49:14 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/08 10:38:02 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	infdix(int argc, stack *a_list, stack *b_list)
{
	if (argc == 3)
		swap(a_list, b_list, 'a');
	else if (argc == 4)
		tree(a_list, b_list);
	else if (argc == 6)
		five(a_list, b_list);
}

void	tree(stack *a_list, stack *b_list)
{
	stack_element	*current;
	int				max_index_value_a;

	current = a_list->a_top;
	max_index_value_a = find_max_index_a(a_list);
	while (max_index_value_a++ < 2)
		rrotate(a_list, b_list, 'a');
	current = a_list->a_top;
	if (current->value > current->next->value)
		swap(a_list, b_list, 'a');
}

void	five(stack *a_list, stack *b_list)
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
