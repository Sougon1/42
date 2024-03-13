/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mind_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:13 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/13 11:52:34 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int find_min_index_a(stack *a_list)
{
    // Vérifier si la pile A est vide
    if (is_empty(a_list, 'a') || a_list->a_top == NULL)
    {
        return (-1);
    }

    stack_element *current = a_list->a_top;
    int min_index = 0;
    int min_value = current->value;
    int i = 0;

    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    return min_index;
}

int find_min_index_b(stack *b_list)
{
    // Vérifier si la pile B est vide
    if (b_list->b_top == NULL)
    {
        return -1;
    }

    stack_element *current = b_list->b_top;
    int min_index = 0;
    int min_value = current->value;
    int i = 0;

    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    return min_index;
}

int find_max_index_b(stack *b_list)
{
    // Vérifier si la pile B est vide
    if (is_empty(b_list, 'b'))
    {
        return -1;
    }

    stack_element *current = b_list->b_top;
    int max_index = 0;
    int max_value = current->value;
    int i = 0;

    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
            max_index = i;
        }
        current = current->next;
        i++;
    }
    return max_index;
}

int is_max_at_top(stack *s)
{
    if (is_empty(s, 'b'))
    {
        // Si la pile est vide, alors il n'y a pas d'élément au sommet
        return 0;
    }

    stack_element *current = s->b_top;

    // Parcourir les éléments de la pile
    while (current != NULL && current->next != NULL)
    {
        // Comparer l'élément actuel avec celui qui le suit
        if (current->value > current->next->value)
        {
            // Si l'élément actuel est plus grand que celui qui le suit, retourner faux
            return 0;
        }
        current = current->next;
    }

    // Si aucun élément plus grand n'a été trouvé, alors l'élément le plus grand est au sommet
    return 1;
}


int max_index_at_top(stack *b_list)
{
    int max_index = find_max_index_b(b_list);

    // Si l'index du maximum est 0, cela signifie que le maximum est au sommet
    if (max_index == 0 && is_max_at_top(b_list)) {
        return 1; // L'index du maximum est au sommet de la pile
    } else {
        return 0; // L'index du maximum n'est pas au sommet de la pile
    }
}


int is_empty(stack *s, char pile)
{
    if (pile == 'a')
    {
        if (s->a_top == NULL)
            return 1;
    }
    else if (pile == 'b')
    {
        if (s->b_top == NULL)
            return 1;
    }
    
    return 0;
}
