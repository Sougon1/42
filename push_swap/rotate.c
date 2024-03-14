/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:01 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 18:15:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//Rotation vers la gauche : Premier element devient le dernier

void    rotate_a(stack *a_list)
{
    stack_element *first;
    stack_element *new_top;

    first = a_list->a_top;
    if (a_list == NULL || first == NULL || first->next == NULL)
        return;

    while (first->next != NULL && first->next->next != NULL)
    {
        first = first->next;
    }

    new_top = a_list->a_top->next;
    first->next->next = a_list->a_top;
    a_list->a_top->next = NULL;
    a_list->a_top = new_top;
}


void    rotate_b(stack *b_list)
{
    stack_element *first;
    stack_element *new_top;
    
    first = b_list->b_top;
    if (b_list == NULL || first == NULL || first->next == NULL)
        return;

    while (first->next != NULL && first->next->next != NULL)
    {
        first = first->next;
    }

    new_top = b_list->b_top->next;
    first->next->next = b_list->b_top;
    b_list->b_top->next = NULL;
    b_list->b_top = new_top;
}

void    rotate_ab(stack *a_list, stack *b_list)
{
    rotate_a(a_list);
    rotate_b(b_list);
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