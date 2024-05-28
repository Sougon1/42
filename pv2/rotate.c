/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:01 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:09:30 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Rotation vers la gauche : Premier element devient le dernier

void	rotate_a(t_stack *a_list)
{
	t_stack_element	*first;
	t_stack_element	*new_top;

	if (a_list->a_top == NULL || a_list->a_top->next == NULL)
		return ;
	first = a_list->a_top;
	while (first->next != NULL && first->next->next != NULL)
	{
		first = first->next;
	}
	new_top = a_list->a_top->next;
	first->next->next = a_list->a_top;
	a_list->a_top->next->prev = first->next;
	a_list->a_top->next = NULL;
	a_list->a_top->prev = first;
	a_list->a_top = new_top;
}

void	rotate_b(t_stack *b_list)
{
	t_stack_element	*first;
	t_stack_element	*new_top;

	if (b_list->b_top == NULL || b_list->b_top->next == NULL)
		return ;
	first = b_list->b_top;
	while (first->next != NULL && first->next->next != NULL)
	{
		first = first->next;
	}
	new_top = b_list->b_top->next;
	first->next->next = b_list->b_top;
	b_list->b_top->next->prev = first->next;
	b_list->b_top->next = NULL;
	b_list->b_top->prev = first;
	b_list->b_top = new_top;
}

void	rotate_ab(t_stack *a_list, t_stack *b_list)
{
	rotate_a(a_list);
	rotate_b(b_list);
}

void	rotate(t_stack *a_list, t_stack *b_list, char pile)
{
	if (pile == 'a')
	{
		ft_printf("ra\n");
		rotate_a(a_list);
	}
	else if (pile == 'b')
	{
		ft_printf("rb\n");
		rotate_b(b_list);
	}
	else if (pile == 'c')
	{
		ft_printf("rr\n");
		rotate_ab(a_list, b_list);
	}
}
