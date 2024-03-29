/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:26:47 by marvin            #+#    #+#             */
/*   Updated: 2024/03/25 14:57:04 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int find_nearest_value_index(stack *a_list, int max_value_a)
{
    stack_element *current_a_top;
    stack_element *current_a_bottom;

    int nearest_index_top = -1; // Indice de la première valeur satisfaisant la condition à partir du haut
    int nearest_index_bottom = -1; // Indice de la première valeur satisfaisant la condition à partir du bas
    int index_top = 0;
    int index_bottom = a_list->size - 1;


    current_a_top = a_list->a_top;
    current_a_bottom = a_list->a_bottom;
    
    ft_printf("5\n");
    while (current_a_top != NULL)
    {
        ft_printf("6\n");
        if (current_a_top->value >= max_value_a / 2)
        {
            nearest_index_top = index_top ;
            ft_printf("7\n");
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du haut
        }
        current_a_top = current_a_top->next;
        index_top++;
    }

    while (current_a_bottom != NULL)
    {
        
        ft_printf("8\n");
        if (current_a_bottom->value >= max_value_a / 2)
        {
            nearest_index_bottom = index_bottom;
            ft_printf("9\n");
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du bas
        }
        ft_printf("10\n");
        if (current_a_bottom->prev == NULL) // Vérifier si l'élément précédent existe
            break; // Sortir de la boucle si on atteint le début de la liste
        current_a_bottom = current_a_bottom->prev;
        ft_printf("11\n");
        index_bottom--; // Décrémenter index_bottom pour suivre l'indice à partir du bas
        ft_printf("12\n");
    }


    ft_printf("11\n");
    // Retourner l'indice le plus proche du sommet
    if (nearest_index_top == -1)
    {
        return nearest_index_bottom; // Si aucune valeur satisfaisant la condition n'est trouvée à partir du haut, retourner l'indice du bas
    }
    if (nearest_index_bottom == -1)
    {
        return nearest_index_top; // Si aucune valeur satisfaisant la condition n'est trouvée à partir du bas, retourner l'indice du haut
    }
    if (nearest_index_top < a_list->size - 1 - nearest_index_bottom)
    {
        return nearest_index_top;
    }
    else
    {
        return nearest_index_bottom;
    }
}

