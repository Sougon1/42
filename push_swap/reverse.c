/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:41:16 by marvin            #+#    #+#             */
/*   Updated: 2024/05/07 16:02:00 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//Rotation vers la droite : Dernier element devient le premier

void rrotate_a(stack *a_list)
{
    if (a_list->a_top == NULL || a_list->a_top->next == NULL)
        return;

    stack_element *last = a_list->a_top;
    stack_element *previous_last = NULL;

    // Trouver le dernier élément
    while (last->next != NULL)
    {
        previous_last = last;
        last = last->next;
    }

    // Effectuer la rotation
    last->next = a_list->a_top; // Mettre le premier élément en tant que dernier
    last->prev = NULL; // L'ancien dernier élément devient le nouveau dernier, donc son prev doit être NULL
    a_list->a_top->prev = last; // Mettre à jour le prev du premier élément
    a_list->a_top = last; // Mettre à jour le sommet de la pile
    previous_last->next = NULL; // Mettre à jour le lien du nouvel avant-dernier élément

    // Mettre à jour a_bottom
    a_list->a_bottom = previous_last; // Mettre à jour le bas de la pile
}


void rrotate_b(stack *b_list)
{
    if (b_list->b_top == NULL || b_list->b_top->next == NULL)
        return;

    stack_element *last = b_list->b_top;
    stack_element *previous_last = NULL;

    // Trouver l'avant-dernier élément de la pile B
    while (last->next != NULL)
    {
        previous_last = last;
        last = last->next;
    }

    // Effectuer la rotation
    last->next = b_list->b_top; // Mettre le premier élément en tant que dernier
    b_list->b_top = last; // Mettre à jour le premier élément
    previous_last->next = NULL; // Mettre à jour le lien du nouvel avant-dernier élément

    // Mettre à jour b_bottom
    b_list->b_bottom = previous_last;
}


void    rrotate_ab(stack *a_list, stack *b_list)
{
    rrotate_a(a_list);
    rrotate_b(b_list);
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


void    rotate(stack *a_list, stack *b_list, char pile)
{
    if (pile == 'a')
    {
        ft_printf("rra\n");
        rotate_a(a_list)
    }
    else if (pile == 'b')
    {
        ft_printf("rrb\n");
        rotate_b(b_list);
    }
    else if (pile == 'ab')
    {
        ft_printf("rrr\n");
        rotate_ab(a_list, b_list);
    }
}
