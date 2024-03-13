/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:01 by marvin            #+#    #+#             */
/*   Updated: 2024/03/13 12:56:17 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//Rotation vers la gauche : Premier element devient le dernier

void    rotate_a(stack *stack)
{
    stack_element *first;
    stack_element *new_top;

    first = stack->a_top;
    if (stack == NULL || first == NULL || first->next == NULL)
        return;

    while (first->next != NULL && first->next->next != NULL)
    {
        first = first->next;
    }

    new_top = stack->a_top->next;
    first->next->next = stack->a_top;
    stack->a_top->next = NULL;
    stack->a_top = new_top;
}


void    rotate_b(stack *stack)
{
    stack_element *first;
    stack_element *new_top;
    
    first = stack->b_top;
    if (stack == NULL || first == NULL || first->next == NULL)
        return;

    while (first->next != NULL && first->next->next != NULL)
    {
        first = first->next;
    }

    new_top = stack->b_top->next;
    first->next->next = stack->b_top;
    stack->b_top->next = NULL;
    stack->b_top = new_top;
}

void    rotate(stack *stack)
{
    char    input[10];

    if (my_fgets(input, sizeof(input), stdin) != NULL)// Lire l'entrée de l'utilisateur
    {
        input[my_strcspn(input, "\n")] = '\0';// Supprimer le caractère de nouvelle ligne
        if (strlen(input) != 2)
        {
            ft_printf("Commande inconnue !");
            return;
        }
        if (ft_strncmp(input, "rr", 2) == 0)
        {
            rotate_a(stack);
            rotate_b(stack);
        }
        else if (ft_strncmp(input, "ra", 2) == 0)
            rotate_a(stack);
        else if (ft_strncmp(input, "rb", 2) == 0)
            rotate_b(stack);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}