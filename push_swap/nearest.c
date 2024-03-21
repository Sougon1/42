/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:26:47 by marvin            #+#    #+#             */
/*   Updated: 2024/03/21 12:26:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int find_nearest_value_index(stack *a_list, int max_value_a)
{
    stack_element *current_a = a_list->a_top;

    int nearest_index_top = -1; // Indice de la première valeur satisfaisant la condition à partir du haut
    int nearest_index_bottom = -1; // Indice de la première valeur satisfaisant la condition à partir du bas
    int index = 0;

    while (current_a != NULL)
    {
        if (current_a->value >= max_value_a / 2)
        {
            nearest_index_top = index;
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du haut
        }
        current_a = current_a->next;
        index++;
    }

    current_a = a_list->a_bottom;
    index = 0;

    while (current_a != NULL)
    {
        if (current_a->value >= max_value_a / 2)
        {
            nearest_index_bottom = index;
            break; // Sortir de la boucle dès qu'on trouve la première valeur satisfaisant la condition à partir du bas
        }
        current_a = current_a->prev;
        index++;
    }

    // Retourner l'indice le plus proche du sommet
    if (nearest_index_top == -1)
    {
        return nearest_index_bottom; // Si aucune valeur satisfaisant la condition n'est trouvée à partir du haut, retourner l'indice du bas
    }
    if (nearest_index_bottom == -1)
    {
        return nearest_index_top; // Si aucune valeur satisfaisant la condition n'est trouvée à partir du bas, retourner l'indice du haut
    }
    if (nearest_index_top < index - nearest_index_bottom)
    {
        return nearest_index_top;
    }
    else
    {
        return nearest_index_bottom;
    }
}

