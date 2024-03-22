/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 17:37:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// Fonction pour vérifier s'il y a un doublon dans la liste
int hasDuplicates(stack *stack, int value) {
    stack_element *current = stack->a_top;
    while (current != NULL) {
        if (current->value == value) {
            return (0);
        }
        current = current->next;
    }
    return (1);
}

void pushtab(stack *stack, int value)
{
    stack_element *newnode = (stack_element*)malloc(sizeof(stack_element));
    if (!newnode)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    newnode->value = value;
    newnode->next = NULL;
    if (!stack->a_top)
        stack->a_top = newnode;
    else
    {
        stack_element *current = stack->a_top;
        while (current->next)
            current = current->next;
        current->next = newnode;
    }
    stack->size++;
}


// Fonction pour ajouter un élément à la pile tout en vérifiant les doublons

// void pushtab(stack *stack, int value)
// {
//     stack_element *current;
//     stack_element *newnode;
    
//     if (hasDuplicates(stack, value) == 0) 
//     {
//         ft_printf("Error\n");
//         exit(EXIT_FAILURE);
//     }
//     newnode = ((stack_element*)malloc(sizeof(stack_element)));
//     if (!newnode)
//     {
//         ft_printf("Error\n");
//         exit(EXIT_FAILURE);
//     }
//     newnode->value = value;
//     newnode->next = NULL;
//     if (stack->a_top == NULL)
//     {
//         stack->a_top = newnode;
//         return;
//     }
//     current = stack->a_top;
//     while (current->next != NULL)
//         current = current->next;
//     current->next = newnode;
//     stack->size++;
// }

// Fonction pour creeer le Tableau A
void tableaua(char *argv, stack *myStack)
{
    long long i;
    int neg;

    neg = 1;
    while (*argv)
    {
        if (*argv == '-')
        {
            neg = -1;
            argv++;
        }
        else if (ft_isdigit(*argv))
        {   
            i = securityint(argv);
            neg = 1;
            while   (ft_isdigit(*argv))
                argv++;
            pushtab(myStack, neg * (int)i);
            argv++;
        }
        else
            argv++;
    }
}
