/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/06 13:40:19 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

//MODIFIER PUSH_A/B 

void    push_a(stack *stack)
{
    a_list  *new_element;
    b_list  *btop;
    int     temp;

    if (b_list stack == NULL || b_list stack->top == NULL)
        return;
    btop = stack->b_top;
    new_element = (a_list*)malloc(sizeof(a_list));
    if (new_element == NULL)
    {
        ft_printf("Error\n")
        exit(EXIT_FAILURE);
    }
    new_element->value = btop->value;//Copie element top B vers top A
    new_element->next = stack->a_top;//Met a jour la pile A
    stack->a_top = new_element;
    stack->b_top = btop->next;
    free(btop);
}

void    push_b(stack *stack)
{
    b_list  *new_element;
    a_list  *atop;
    int     temp;

    if (a_list stack == NULL || a_list stack->top == NULL)
        return;
    atop = stack->a_top;
    new_element = (b_list*)malloc(sizeof(b_list));
    if (new_element == NULL)
    {
        ft_printf("Error\n")
        exit(EXIT_FAILURE);
    }
    new_element->value = atop->value;//Copie element top A vers top B
    new_element->next = stack->b_top;//Met a jour la pile B
    stack->b_top = new_element;
    stack->a_top = atop->next;
    free(atop);
}

void    push(stack *stack, int value)
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
            push_a(stack, value);
        else if (ft_strncmp(input, "pb", 2) == 0)
            push_b(stack, value);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}
