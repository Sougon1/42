/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:05 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 13:04:43 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Sommet B Vers Sommet A
void	push_a(t_stack *a_list, t_stack *b_list)
{
	t_stack_element	*current;
	t_stack_element	*new_element;

	if (b_list == NULL || b_list->b_top == NULL)
		return ;
	current = b_list->b_top;
	new_element = (t_stack_element *)malloc(sizeof(t_stack_element));
	if (new_element == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	new_element->value = current->value;
	new_element->next = a_list->a_top;
	new_element->prev = NULL;
	if (a_list->a_top != NULL)
		a_list->a_top->prev = new_element;
	a_list->a_top = new_element;
	b_list->b_top = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
	a_list->size++;
	b_list->size--;
}

// Sommet A Vers Sommet B
void	push_b(t_stack *a_list, t_stack *b_list)
{
	t_stack_element	*current;
	t_stack_element	*new_element;

	if (a_list == NULL || a_list->a_top == NULL)
		return ;
	current = a_list->a_top;
	new_element = (t_stack_element *)malloc(sizeof(t_stack_element));
	if (new_element == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	new_element->value = current->value;
	new_element->next = b_list->b_top;
	new_element->prev = NULL;
	if (b_list->b_top != NULL)
		b_list->b_top->prev = new_element;
	b_list->b_top = new_element;
	a_list->a_top = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
	a_list->size--;
	b_list->size++;
}

void	push(t_stack *a_list, t_stack *b_list, char pile)
{
	if (pile == 'a')
	{
		ft_printf("pa\n");
		push_a(a_list, b_list);
	}
	else if (pile == 'b')
	{
		ft_printf("pb\n");
		push_b(a_list, b_list);
	}
}
