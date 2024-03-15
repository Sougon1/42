/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:08 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 14:09:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int find_last_value_a(stack *a_list) {
    if (is_empty(a_list, 'a')) {
        // La pile est vide, rien à faire
        return -1;
    }

    // Parcourir la pile A jusqu'à la dernière valeur
    stack_element *current = a_list->a_top;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Retourner la dernière valeur de la pile A
    return current->value;
}

int find_last_value_b(stack *b_list) {
    if (is_empty(b_list, 'b')) {
        // La pile est vide, rien à faire
        return -1;
    }

    // Parcourir la pile B jusqu'à la dernière valeur
    stack_element *current = b_list->b_top;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Retourner la dernière valeur de la pile B
    return current->value;
}
