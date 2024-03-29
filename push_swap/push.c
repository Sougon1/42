/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/29 16:22:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pas dans le makefile

#include "ps.h"

// Sommet B Vers Sommet A
void    push_a(stack *a_list, stack *b_list)
{
    stack_element  *new_element;
    stack_element  *btop;

    if (b_list == NULL || b_list->b_top == NULL)
        return;
    btop = b_list->b_top;
    new_element = (stack_element*)malloc(sizeof(stack_element));
    if (new_element == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    new_element->value = btop->value;//Copie element top B vers top A
    new_element->next = a_list->a_top;//Met a jour la pile A
    a_list->a_top = new_element;
    if (a_list->a_bottom == NULL)
        a_list->a_bottom = new_element;
    if (b_list->b_bottom == btop)
        b_list->b_bottom = btop->next;
    b_list->b_top = btop->next;
    free(btop);
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
    stack_element *atop = a_list->a_top;

    // Allouer un nouvel élément pour la pile B
    stack_element *new_element = (stack_element *)malloc(sizeof(stack_element));
    if (new_element == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }

    // Copier la valeur de l'élément en haut de la pile A dans le nouvel élément de la pile B
    new_element->value = atop->value;

    // Mettre à jour les pointeurs de la pile B
    new_element->next = b_list->b_top;
    b_list->b_top = new_element;
    if (b_list->b_bottom == NULL)
        b_list->b_bottom = new_element;

    // Mettre à jour les pointeurs de la pile A
    if (a_list->a_bottom == atop)
        a_list->a_bottom = atop->next;
    a_list->a_top = atop->next;

    // Libérer la mémoire de l'élément déplacé de la pile A
    free(atop);

    // Mettre à jour les tailles des piles
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
