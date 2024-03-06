/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:41:16 by marvin            #+#    #+#             */
/*   Updated: 2024/03/06 16:26:01 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//Rotation vers la droite : Dernier element devient le premier

void    rrotate_a(stack *stack)
{
    a_list  *last;
    a_list  *previouslast;
    a_list  *new_top;
    
    if (stack == NULL || stack->a_top == NULL || stack->a_top->next== NULL)
        return;

    last = stack->a_top;//Stock l'adresse des deux premiers elements de la pile
    previouslast = NULL;
    while (last->next != NULL)//trouver l avant dernier element
    {
        previouslast = last;
        last = last->next;
    }

    last->next = stack->a_top;//Echange des valeurs
    stack->a_top= stack->a_top->next;
    previouslast->next = NULL;
}

void    rrotate_b(stack *stack)
{
    b_list  *last;
    b_list  *previouslast;
    b_list  *new_top;
    
    if (stack == NULL || stack->b_top == NULL || stack->b_top->next== NULL)
        return;

    last = stack->b_top;//Stock l'adresse des deux premiers elements de la pile
    previouslast = NULL;
    while (last->next != NULL)//trouver l avant dernier element
    {
        previouslast = last;
        last = last->next;
    }

    last->next = stack->b_top;//Echange des valeurs
    stack->b_top= stack->b_top->next;
    previouslast->next = NULL;
}
void    rrotate(stack *stack, int value)
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
            rrotate_a(stack, value);
            rrotate_b(stack, value);
        }
        else if (ft_strncmp(input, "rra", 2) == 0)
            rrotate_a(stack, value);
        else if (ft_strncmp(input, "rrb", 2) == 0)
            rrotate_b(stack, value);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}