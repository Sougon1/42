/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:41:16 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:05:08 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Rotation vers la droite : Dernier element devient le premier

void	rrotate_a(t_stack *a_list)
{
	t_stack_element	*last;
	t_stack_element	*previous_last;

	if (a_list->a_top == NULL || a_list->a_top->next == NULL)
		return ;
	last = a_list->a_top;
	previous_last = NULL;
	while (last->next != NULL)
	{
		previous_last = last;
		last = last->next;
	}
	last->next = a_list->a_top;
	last->prev = NULL;
	a_list->a_top->prev = last;
	a_list->a_top = last;
	previous_last->next = NULL;
}

void	rrotate_b(t_stack *b_list)
{
	t_stack_element	*last;
	t_stack_element	*previous_last;

	if (b_list->b_top == NULL || b_list->b_top->next == NULL)
		return ;
	last = b_list->b_top;
	previous_last = NULL;
	while (last->next != NULL)
	{
		previous_last = last;
		last = last->next;
	}
	last->next = b_list->b_top;
	last->prev = NULL;
	b_list->b_top->prev = last;
	b_list->b_top = last;
	previous_last->next = NULL;
}

void	rrotate_ab(t_stack *a_list, t_stack *b_list)
{
	rrotate_a(a_list);
	rrotate_b(b_list);
}

void	rrotate(t_stack *a_list, t_stack *b_list, char pile)
{
	if (pile == 'a')
	{
		ft_printf("rra\n");
		rrotate_a(a_list);
	}
	else if (pile == 'b')
	{
		ft_printf("rrb\n");
		rrotate_b(b_list);
	}
	else if (pile == 'c')
	{
		ft_printf("rrr\n");
		rrotate_ab(a_list, b_list);
	}
}
