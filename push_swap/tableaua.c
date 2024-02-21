/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/02/21 14:49:15 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Fonction pour vérifier s'il y a un doublon dans la liste
int hasDuplicates(stack *myStack, int value) {
    t_list *current = myStack->top;
    while (current != NULL) {
        if (current->value == value) {
            return 1; // Doublon trouvé
        }
        current = current->next;
    }
    return 0; // Pas de doublon trouvé
}

// Fonction pour ajouter un élément à la pile tout en vérifiant les doublons
void pushtab(stack *stack, int value)
{
    t_list *current;
    t_list *newnode;
    
    if (hasDuplicates(stack, value)) 
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    newnode = ((t_list*)malloc(sizeof(t_list)));
    if (!newnode)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    newnode->value = value;
    newnode->next = NULL;
    if (stack->top == NULL)
    {
        stack->top = newnode;
        return;
    }
    current = stack->top;
    while (current->next != NULL)
        current = current->next;
    current->next = newnode;
}

// Creation du Tableau A
void tableaua(char *argv, stack *myStack) {
    long long i;
    int neg;

    while (*argv) {
        if (*argv == '-')
        {
            neg = -1;
            argv++;
        }
        else if (ft_isdigit(*argv))
        {
            i = securityint(argv);
            pushtab(myStack, neg * (int)i);
            neg = 1;
            while (ft_isdigit(*argv)) argv++;
            argv++;
        }
        else
        {
            argv++;
        }
    }
}
