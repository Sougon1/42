/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:01 by marvin            #+#    #+#             */
/*   Updated: 2024/04/01 17:06:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//Rotation vers la gauche : Premier element devient le dernier

void rotate_a(stack *a_list)
{
    if (a_list->a_top == NULL || a_list->a_top->next == NULL)
        return;

    stack_element *first = a_list->a_top;
    stack_element *new_top;

    // Trouver l'avant-dernier élément
    while (first->next != NULL && first->next->next != NULL)
    {
        first = first->next;
    }

    new_top = a_list->a_top->next;

    // Mettre à jour les pointeurs next et prev
    first->next->next = a_list->a_top;
    a_list->a_top->next->prev = first->next; // Mettre à jour le prev du nouvel sommet
    a_list->a_top->next = NULL; // Mettre à jour le next de l'ancien sommet
    a_list->a_top->prev = first; // Mettre à jour le prev du nouvel sommet
    a_list->a_top = new_top;

    // Mettre à jour a_bottom pour pointer vers le dernier élément
    a_list->a_bottom = first->next;
}



void rotate_b(stack *b_list)
{
    if (b_list->b_top == NULL || b_list->b_top->next == NULL)
        return;

    stack_element *first = b_list->b_top;
    stack_element *new_top;

    // Trouver l'avant-dernier élément
    while (first->next != NULL && first->next->next != NULL)
    {
        first = first->next;
    }

    new_top = b_list->b_top->next;
    first->next->next = b_list->b_top;
    b_list->b_top->next = NULL;
    b_list->b_top = new_top;

    // Mettre à jour b_bottom pour pointer vers le dernier élément
    b_list->b_bottom = first->next;
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