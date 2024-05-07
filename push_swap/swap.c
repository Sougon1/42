/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:13 by marvin            #+#    #+#             */
/*   Updated: 2024/05/07 16:03:11 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    swap_a(stack *a_list)
{
    stack_element  *first;
    stack_element  *second;
    int     temp;
    
    if (a_list == NULL || a_list->a_top == NULL || a_list->a_top->next == NULL)
        return;
    first = a_list->a_top;//Stock l'adresse des deux premiers elements de la pile
    second = a_list->a_top->next;
    temp = first->value; // Échange des valeurs
    first->value = second->value;
    second->value = temp;
}

void    swap_b(stack *b_list)
{
    stack_element  *first;
    stack_element  *second;
    int     temp;

    if (b_list == NULL || b_list->b_top == NULL ||b_list->b_top->next == NULL)
        return;
    first = b_list->b_top;
    second = b_list->b_top->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void    swap_ab(stack *a_list, stack *b_list)
{
    swap_a(a_list);
    swap_b(b_list);
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

void    swap(stack *a_list, stack *b_list, char pile)
{
    if (pile == 'a')
    {
        ft_printf("sa\n");
        rotate_a(a_list)
    }
    else if (pile == 'b')
    {
        ft_printf("sb\n");
        rotate_b(b_list);
    }
    else if (pile == 'ab')
    {
        ft_printf("ss\n");
        rotate_ab(a_list, b_list);
    }
}