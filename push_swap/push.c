/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:05 by marvin            #+#    #+#             */
/*   Updated: 2024/04/29 17:49:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

// Sommet B Vers Sommet A
void push_a(stack *a_list, stack *b_list)
{
    // Vérifier si la pile B n'est pas vide
    if (b_list == NULL || b_list->b_top == NULL)
        return;

    // Sauvegarder l'élément en haut de la pile B
    stack_element *current = b_list->b_top;

    // Allouer un nouvel élément pour la pile A
    stack_element *new_element = (stack_element *)malloc(sizeof(stack_element));
    if (new_element == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    new_element->value = current->value;
    new_element->next = a_list->a_top;
    new_element->prev = NULL; // Le nouveau nœud devient le premier nœud de la pile A

    if (a_list->a_top != NULL) {
        a_list->a_top->prev = new_element; // Mettre à jour le lien prev du nœud actuel en haut de la pile A
    }
    a_list->a_top = new_element;

    // Mettre à jour les pointeurs de la pile B
    b_list->b_top = current->next;
    if (current->next != NULL) {
        current->next->prev = NULL; // Mettre à jour le lien prev du nouveau sommet de la pile B
    }
    free(current);
    a_list->size++;
    b_list->size--;
}


// Sommet A Vers Sommet B
void push_b(stack *a_list, stack *b_list)
{
    // Vérifier si la pile A n'est pas vide
    if (a_list == NULL || a_list->a_top == NULL)
        return;

    // Sauvegarder l'élément en haut de la pile A
    stack_element *current;
    stack_element *new_element;

    current = a_list->a_top;
    new_element = (stack_element *)malloc(sizeof(stack_element));
    if (new_element == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    new_element->value = current->value;
    new_element->next = b_list->b_top;
    new_element->prev = NULL;    // Le nouveau nœud devient le premier nœud de la pile B

    if (b_list->b_top != NULL) {
        b_list->b_top->prev = new_element; // Mettre à jour le lien prev du nœud actuel en haut de la pile B
    }
    b_list->b_top = new_element;

    // Mettre à jour les pointeurs de la pile A
    // Mettre à jour les pointeurs de la pile A
    a_list->a_top = current->next;
    if (current->next != NULL) {
        current->next->prev = NULL; // Mettre à jour le lien prev du nouveau sommet de la pile A
    }

    free(current);
    a_list->size--;
    b_list->size++;
}




void    push(stack *stack)
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
            push_a(stack, stack);
        else if (ft_strncmp(input, "pb", 2) == 0)
            push_b(stack, stack);
        else
            ft_printf("Commande inconnue !");
    }
    return;
}
