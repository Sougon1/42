/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 13:09:16 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

// B Vers A
void    push_a(stack *a_stack, stack *b_stack)
{
    stack_element  *new_element;
    stack_element  *btop;

    if (b_stack == NULL || b_stack->b_top == NULL)
        return;
    btop = b_stack->b_top;
    new_element = (stack_element*)malloc(sizeof(stack_element));
    if (new_element == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    new_element->value = btop->value;//Copie element top B vers top A
    new_element->next = a_stack->a_top;//Met a jour la pile A
    a_stack->a_top = new_element;
    b_stack->b_top = btop->next;
    free(btop);
}

// A Vers B
void    push_b(stack *a_stack, stack *b_stack)
{
    stack_element  *new_element;
    stack_element  *atop;

    if (a_stack == NULL || a_stack->a_top == NULL)
        return;
    atop = a_stack->a_top;
    new_element = (stack_element*)malloc(sizeof(stack_element));
    if (new_element == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    new_element->value = atop->value;//Copie element top A vers top B
    new_element->next = b_stack->b_top;//Met a jour la pile B
    b_stack->b_top = new_element;
    a_stack->a_top = atop->next;
    free(atop);
}

void    push(stack *stack)
{
    char    input[10];

    if (my_fgets(input, sizeof(input), stdin) != NULL) // Lire l'entrée de l'utilisateur
    {
        input[my_strcspn(input, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
        if (ft_strlen(input) != 2)
        {
            ft_printf("Commande inconnue !");
            return;
        }
        else if (ft_strncmp(input, "pa", 2) == 0)
            push_a(stack, stack);
        else if (ft_strncmp(input, "pb", 2) == 0)
            push_b(stack, stack);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}
