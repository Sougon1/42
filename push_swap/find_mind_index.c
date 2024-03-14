/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mind_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:13 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/14 11:46:48 by marvin           ###   ########.fr       */
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

int find_max_index_a(stack *a_list)
{
    // Vérifier si la pile B est vide
    if (is_empty(a_list, 'a'))
    {
        return -1;
    }

    stack_element *current = a_list->a_top;
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
