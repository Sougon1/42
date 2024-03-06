/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:42:13 by marvin            #+#    #+#             */
/*   Updated: 2024/03/06 12:39:18 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    swap_a(stack *stack)
{
    a_list  *first;
    a_list  *second;
    int     temp;
    
    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return;
    //Stock l'adresse des deux premiers elements de la pile
    first = stack->top;
    second = stack->top->next;

    //Echange des valeurs
    temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void    swap_b(stack *stack)
{
    b_list  *first;
    b_list  *second;
    int     temp;
    
    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return;
    
    temp = first->value;
    first->value = second->value;
    second->value= temp;
}

void    swap(stack *stack, int value)
{
    char    input[10];
    
    if (my_fgets(input, sizeof(input), stdin) != NULL) // Lire l'entrée de l'utilisateur
    {
        input[my_strcspn(input, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
        if (strlen(input) != 2)
        {
            // Afficher un message d'erreur ou gérer la saisie incorrecte de l'utilisateur
            // Dans cet exemple, je vais simplement retourner pour ignorer la saisie incorrecte
            return;
        }
        if (ft_strncmp(input, "ss", 2) == 0)
        {
            swap_a(stack, value);
            swap_b(stack, value);
        }
        else if (ft_strncmp(input, "sa", 2) == 0)
        {
            swap_a(stack, value);
        }
        else if (ft_strncmp(input, "sb", 2) == 0)
        {
            swap_b(stack, value);
        }
    }
    return ;
}
