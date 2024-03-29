/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:26:47 by marvin            #+#    #+#             */
/*   Updated: 2024/03/29 16:11:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// void find_nearest_value_index(stack *a_list, int max_value_a)
// {
//     // Initialisation des index les plus proches
//     int nearest_from_top = 0; // Index le plus proche à partir du haut
//     int nearest_from_bottom = a_list->size - 1; // Index le plus proche à partir du bas
    
//     stack_element *current = a_list->a_top;
    
//     // Parcours de la pile à partir du haut
//     while (current != NULL)
//     {
//         ft_printf("Valeur TOP A: %i\n", current->value);
//         // Si la valeur actuelle est proche de max_value_a, met à jour l'index le plus proche à partir du haut
//         if (current->value >= max_value_a * 0.86 || current->value == max_value_a)
//         {
//             nearest_from_top = current->index;
//             break;
//         }
//         current = current->next;
//     }
    
//     current = a_list->a_bottom;
    
//     // Parcours de la pile à partir du bas
//     while (current != NULL)
//     {
//         ft_printf("Valeur BOTTOM A: %i\n", current->value);
//         // Si la valeur actuelle est proche de max_value_a, met à jour l'index le plus proche à partir du bas
//         // if (current->value >= max_value_a * 0.86 || current->value == max_value_a)
//         // {
//         //     nearest_from_bottom = current->index;
//         //     break;
//         // }
//         current = current->prev;
//     }
    
//     // Compare les index les plus proches et retourne celui qui minimise la rotation
//     if (nearest_from_top <= a_list->size - 1 - nearest_from_bottom)
//     {
//         while (nearest_from_top > 0)
//         {
//             ft_printf("ra\n");
//             rotate_a(a_list);
//             nearest_from_top--;
//         }
//     } 
//     else
//     {
//         while (a_list->size - 1 - nearest_from_bottom < a_list->size + 1)
//         {
//             ft_printf("rra\n");
//             rrotate_a(a_list);
//             nearest_from_bottom++;
//         }
//     }
// }

void find_nearest_value_index(stack *a_list, int max_value_a)
{
    stack_element *current_a_top;
    stack_element *current_a_bottom;

    int nearest_index_top = 0; // Indice de la première valeur satisfaisant la condition à partir du haut
    int nearest_index_bottom = -1; // Indice de la première valeur satisfaisant la condition à partir du bas
    int index_top = 0;
    int index_bottom = a_list->size - 1;


    current_a_top = a_list->a_top;
    
    
    // ft_printf("5\n");
    while (current_a_top != NULL)
    {
        ft_printf("Valeur TOP A: %i\n", current_a_top->value);
        // ft_printf("6\n");
        if (current_a_top->value >= max_value_a * 0.86 || current_a_top->value == max_value_a)
        {
            nearest_index_top = index_top ;
            // ft_printf("7\n");
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du haut
        }
        current_a_top = current_a_top->next;
        index_top++;
    }

    current_a_bottom = a_list->a_bottom;
    while (current_a_bottom != NULL)
    {
        ft_printf("Valeur BOTTOM A: %i\n", current_a_bottom->value);
        // ft_printf("8\n");
        if (current_a_bottom->value >= max_value_a * 0.86 || current_a_bottom->value == max_value_a)
        {
            nearest_index_bottom = index_bottom;
            // ft_printf("9\n");
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du bas
        }
        // ft_printf("10\n");
        if (current_a_bottom->prev == NULL) // Vérifier si l'élément précédent existe
            break; // Sortir de la boucle si on atteint le début de la liste
        current_a_bottom = current_a_bottom->prev;
        // ft_printf("11\n");
        index_bottom--; // Décrémenter index_bottom pour suivre l'indice à partir du bas
        // ft_printf("12\n");
    }


    // ft_printf("13\n");
    // Retourner l'indice le plus proche du sommet
    if (nearest_index_top <= a_list->size - 1 - nearest_index_bottom)
    {
        while (nearest_index_top > 0)
        {
            ft_printf("ra\n");
            rotate_a(a_list);
            nearest_index_top--;
        }
    } 
    else
    {
        while (nearest_index_bottom < a_list->size - 1)
        {
            ft_printf("rra\n");
            rrotate_a(a_list);
            nearest_index_bottom++;
        }
    }
}

