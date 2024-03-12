/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:13 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 10:03:04 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    swap_a(stack *stack)
{
    stack_element  *first;
    stack_element  *second;
    int     temp;
    
    if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
        return;
    first = stack->a_top;//Stock l'adresse des deux premiers elements de la pile
    second = stack->a_top->next;
    temp = first->value; // Échange des valeurs
    first->value = second->value;
    second->value = temp;
}

void    swap_b(stack *stack)
{
    stack_element  *first;
    stack_element  *second;
    int     temp;

    if (stack == NULL || stack->b_top == NULL || stack->b_top->next == NULL)
        return;
    first = stack->b_top;
    second = stack->b_top->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void    swap(stack *stack)
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
        if (ft_strncmp(input, "ss", 2) == 0)
        {
            swap_a(stack);
            swap_b(stack);
        }
        else if (ft_strncmp(input, "sa", 2) == 0)
            swap_a(stack);
        else if (ft_strncmp(input, "sb", 2) == 0)
            swap_b(stack);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}
