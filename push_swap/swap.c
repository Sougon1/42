/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:13 by marvin            #+#    #+#             */
/*   Updated: 2024/03/06 10:56:38 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

void    swap_a(stack *stack, int value)
{
    a_list  *first;
    a_list  *second;
    int     temp;
    
    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return;
    
    temp = first->value;
    first->value = second->value;
    second->value= temp;
}

void    swap_b(stack *stack, int value)
{
    b_list  *first;
    b_list  *second;
    int     temp;
    
    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return;
    
    temp = first->value;
    first->value = second->value;
    second->value= temp;
}

void    swap(stack *stack, int value)
{
    if (my_fgets(input, sizeof(input), stdin) == "ss") // Lire l'entrée de l'utilisateur
    {
        input[my_strcspn(input, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
        swap_a(stack, value);
        swap_b(stack, value);
    }
    if (my_fgets(input, sizeof(input), stdin) == "sa")
    {
        input[my_strcspn(input, "\n")] = '\0';
        swap_a(stack, value);
    }
    if (my_fgets(input, sizeof(input), stdin) == "sb")
    {
        input[my_strcspn(input, "\n")] = '\0';
        swap_b(stack, value);
    }
    return ;
}