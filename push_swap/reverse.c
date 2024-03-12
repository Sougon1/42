/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:41:16 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 13:49:42 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//Rotation vers la droite : Dernier element devient le premier

void rrotate_a(stack *stack)
{
    if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
        return;

    stack_element *last = stack->a_top;

    // Trouver l'avant-dernier élément
    while (last->next->next != NULL)
    {
        last = last->next;
    }

    // Effectuer la rotation
    last->next->next = stack->a_top;
    stack->a_top = last->next;
    last->next = NULL;
}



void rrotate_b(stack *stack)
{
    if (stack == NULL || stack->b_top == NULL || stack->b_top->next == NULL)
        return;

    stack_element *last = stack->b_top;
    stack_element *previous_last = NULL;

    // Trouver l'avant-dernier élément de la pile B
    while (last->next != NULL)
    {
        previous_last = last;
        last = last->next;
    }

    // Effectuer la rotation
    last->next = stack->b_top; // Mettre le premier élément en tant que dernier
    stack->b_top = last; // Mettre à jour le premier élément
    previous_last->next = NULL; // Mettre à jour le lien du nouvel avant-dernier élément
}


void    rrotate(stack *stack)
{
    char    input[10];

    if (my_fgets(input, sizeof(input), stdin) != NULL)// Lire l'entrée de l'utilisateur
    {
        input[my_strcspn(input, "\n")] = '\0';// Supprimer le caractère de nouvelle ligne
        if (strlen(input) != 3)
        {
            ft_printf("Commande inconnue !");
            return;
        }
        if (ft_strncmp(input, "rrr", 2) == 0)
        {
            rrotate_a(stack);
            rrotate_b(stack);
        }
        else if (ft_strncmp(input, "rra", 2) == 0)
            rrotate_a(stack);
        else if (ft_strncmp(input, "rrb", 2) == 0)
            rrotate_b(stack);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}