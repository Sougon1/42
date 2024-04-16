/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:26:47 by marvin            #+#    #+#             */
/*   Updated: 2024/04/16 16:40:59 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void find_nearest_value_index(stack *a_list, int max_value_a)
{
    stack_element *current_a_top;
    stack_element *previous;


    int nearest_index_top = -1; // Indice de la première valeur satisfaisant la condition à partir du haut
    int nearest_index_bottom = -1; // Indice de la première valeur satisfaisant la condition à partir du bas
    int index_top = 0;
    int index_bottom = 0;

    current_a_top = a_list->a_top;
    
    
    if  (max_value_a <= 0)
    {
        find_nearest_neg(a_list, max_value_a);
        return ;
    }


    
    // ft_printf("A size : %i\n", a_list->size -1);
    
    // ft_printf("5\n");
    while (current_a_top != NULL)
    {
        // ft_printf("Valeur TOP A: %i\n", current_a_top->value);
        // ft_printf("6\n");
        if (current_a_top->value >= max_value_a * 0.85 || current_a_top->value == max_value_a)
        {
            nearest_index_top = index_top;
            // ft_printf("7\n");
            // ft_printf("INDEX TOP A: %i\n", index_top);
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du haut
        }
        current_a_top = current_a_top->next;
        index_top++;
    }

    previous = NULL;
    current_a_top = a_list->a_top;
    while (current_a_top != NULL)
    {
        previous = current_a_top;
        current_a_top = current_a_top->next;
        // ft_printf("A: %i\n", previous->value);
    }
    
    while (previous != NULL)
    {
        // ft_printf("Valeur BOTTOM A: %i\n", previous->value);

        if (previous->value >= max_value_a * 0.85 || previous->value == max_value_a)
        {
            nearest_index_bottom = index_bottom;
            // ft_printf("INDEX BOT A: %i\n", index_bottom);
            break; 
        }
        previous = previous->prev;
        index_bottom++;
        // ft_printf("Valeur BOTTOM A 2 : %i\n", previous->value);
    }
    
    // nearest_index_bottom = a_list->size - nearest_index_bottom + 1;
    // ft_printf("INDEX BOT 2 A: %i\n", nearest_index_bottom);


    // Retourner l'indice le plus proche du sommet
    if (nearest_index_top <= nearest_index_bottom)
    {
        while (nearest_index_top > 0)
        {
            ft_printf("ra\n");
            rotate_a(a_list);
            nearest_index_top--;
        }
    }
    else if (nearest_index_bottom < nearest_index_top)
    {
        nearest_index_bottom = a_list->size - nearest_index_bottom;
        while (nearest_index_bottom /*> -1*/ < a_list->size + 1)
        {
            ft_printf("rra\n");
            rrotate_a(a_list);
            nearest_index_bottom++;
        }
    }
    
    if  (max_value_a <= 0)
    {
        while (current_a_top != NULL)
        {
            current_a_top->value *= -1;
            current_a_top = current_a_top->next;
        }
        max_value_a *= -1;
    }
}

void    find_nearest_neg(stack *a_list, int max_value_a)
{
    stack_element *current_a_top;
    stack_element *previous;


    int nearest_index_top = -1; // Indice de la première valeur satisfaisant la condition à partir du haut
    int nearest_index_bottom = -1; // Indice de la première valeur satisfaisant la condition à partir du bas
    int index_top = 0;
    int index_bottom = 0;

    current_a_top = a_list->a_top;
    
    
    if  (max_value_a <= 0)
    {
        while (current_a_top != NULL)
        {
            current_a_top->value *= -1;
            current_a_top = current_a_top->next;
        }
        max_value_a *= -1;
    }


    
    // ft_printf("A size : %i\n", a_list->size -1);
    
    // ft_printf("5\n");
    while (current_a_top != NULL)
    {
        // ft_printf("Valeur TOP A: %i\n", current_a_top->value);
        // ft_printf("6\n");
        if (current_a_top->value >= max_value_a * 0.85 || current_a_top->value == max_value_a)
        {
            nearest_index_top = index_top;
            // ft_printf("7\n");
            // ft_printf("INDEX TOP A: %i\n", index_top);
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du haut
        }
        current_a_top = current_a_top->next;
        index_top++;
    }

    previous = NULL;
    current_a_top = a_list->a_top;
    while (current_a_top != NULL)
    {
        previous = current_a_top;
        current_a_top = current_a_top->next;
        // ft_printf("A: %i\n", previous->value);
    }
    
    while (previous != NULL)
    {
        // ft_printf("Valeur BOTTOM A: %i\n", previous->value);

        if (previous->value >= max_value_a * 0.85 || previous->value == max_value_a)
        {
            nearest_index_bottom = index_bottom;
            // ft_printf("INDEX BOT A: %i\n", index_bottom);
            break; 
        }
        previous = previous->prev;
        index_bottom++;
        // ft_printf("Valeur BOTTOM A 2 : %i\n", previous->value);
    }
    
    // nearest_index_bottom = a_list->size - nearest_index_bottom + 1;
    // ft_printf("INDEX BOT 2 A: %i\n", nearest_index_bottom);


    // Retourner l'indice le plus proche du sommet
    if (nearest_index_top <= nearest_index_bottom)
    {
        while (nearest_index_top > 0)
        {
            ft_printf("ra\n");
            rotate_a(a_list);
            nearest_index_top--;
        }
    }
    else if (nearest_index_bottom < nearest_index_top)
    {
        nearest_index_bottom = a_list->size - nearest_index_bottom;
        while (nearest_index_bottom /*> -1*/ < a_list->size + 1)
        {
            ft_printf("rra\n");
            rrotate_a(a_list);
            nearest_index_bottom++;
        }
    }
    
    while (current_a_top != NULL)
    {
        current_a_top->value *= -1;
        current_a_top = current_a_top->next;
    }
    max_value_a *= -1;
}