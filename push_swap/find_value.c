/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:46:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/16 17:10:32 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int find_max_value_a(stack *a_list)
{
    if (is_empty(a_list, 'a'))
    {
        return -1;
    }

    int max_value = a_list->a_top->value; // Initialise la valeur maximale avec la valeur du sommet de la pile A
    stack_element *current = a_list->a_top->next; // Commence à partir du deuxième élément

    // Parcours la pile A pour trouver la valeur maximale
    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value; // Met à jour la valeur maximale si on trouve une valeur plus grande
        }
        current = current->next;
    }

    return max_value; // Retourne la valeur maximale trouvée
}

int find_min_value_a(stack *a_list)
{
    if (is_empty(a_list, 'a'))
    {
        // La pile est vide, rien à faire
        return -1;
    }

    int min_value = a_list->a_top->value; // Initialise la valeur minimale avec la valeur du sommet de la pile A
    stack_element *current = a_list->a_top->next; // Commence à partir du deuxième élément

    // Parcours la pile A pour trouver la valeur minimale
    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value; // Met à jour la valeur minimale si on trouve une valeur plus petite
        }
        current = current->next;
    }

    return min_value; // Retourne la valeur minimale trouvée
}

int find_max_value_b(stack *b_list)
{
    if (is_empty(b_list, 'b'))
    {
        return -1;
    }

    int max_value = b_list->b_top->value; // Initialise la valeur maximale avec la valeur du sommet de la pile B
    stack_element *current = b_list->b_top->next; // Commence à partir du deuxième élément

    // Parcours la pile B pour trouver la valeur maximale
    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value; // Met à jour la valeur maximale si on trouve une valeur plus grande
        }
        current = current->next;
    }

    return max_value; // Retourne la valeur maximale trouvée
}

int find_min_value_b(stack *b_list)
{
    if (is_empty(b_list, 'b'))
    {
        return -1;
    }

    int min_value = b_list->b_top->value; // Initialise la valeur minimale avec la valeur du sommet de la pile B
    stack_element *current = b_list->b_top->next; // Commence à partir du deuxième élément

    // Parcours la pile B pour trouver la valeur minimale
    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value; // Met à jour la valeur minimale si on trouve une valeur plus petite
        }
        current = current->next;
    }

    return min_value; // Retourne la valeur minimale trouvée
}
