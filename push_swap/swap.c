/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:13 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 12:19:40 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap_a(stack *a_list)
{
	stack_element	*first;
	stack_element	*second;
	int				temp;

	if (a_list == NULL || a_list->a_top == NULL || a_list->a_top->next == NULL)
		return ;
	first = a_list->a_top;
	second = a_list->a_top->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	swap_b(stack *b_list)
{
	stack_element	*first;
	stack_element	*second;
	int				temp;

	if (b_list == NULL || b_list->b_top == NULL || b_list->b_top->next == NULL)
		return ;
	first = b_list->b_top;
	second = b_list->b_top->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	swap_ab(stack *a_list, stack *b_list)
{
	swap_a(a_list);
	swap_b(b_list);
}

void	swap(stack *a_list, stack *b_list, char pile)
{
	if (pile == 'a')
	{
		ft_printf("sa\n");
		swap_a(a_list);
	}
	else if (pile == 'b')
	{
		ft_printf("sb\n");
		swap_b(b_list);
	}
	else if (pile == 'c')
	{
		ft_printf("ss\n");
		swap_ab(a_list, b_list);
	}
}
