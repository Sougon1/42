/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/02/21 16:18:05 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Fonction pour vérifier s'il y a un doublon dans la liste
int hasDuplicates(stack *myStack, int value) {
    t_list *current = myStack->top;
    while (current != NULL) {
        if (current->value == value) {
            return (0);
        }
        current = current->next;
    }
    return (1);
}

// Fonction pour ajouter un élément à la pile tout en vérifiant les doublons
void pushtab(stack *stack, int value)
{
    t_list *current;
    t_list *newnode;
    
    if (hasDuplicates(stack, value) == 0) 
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

// Fonction pour creeer le Tableau A
void tableaua(char *argv, stack *myStack)
{
    long long i;
    int neg;

    while (*argv)
    {
        if (*argv == '-')
        {
            neg = -1;
            argv++;
        }
        else if (ft_isdigit(*argv))
        {   
            printf("A: %s\n", argv);
            i = securityint(argv);
            // printf(" TAB 0 : %s\n", argv);
            pushtab(myStack, neg * (int)i);
            neg = 1;
            // printf(" TAB 1 : %lld\n", i);
            while   (ft_isdigit(*argv))
                argv++;
            // printf(" TAB 2 : %lld\n", i);
            argv++;
            // printf(" TAB 3 : %lld\n", i);
        }
        else
            argv++;
        printf(" TAB 4 : %lld\n", i);
    }
}
