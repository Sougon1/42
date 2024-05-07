/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/05/07 16:47:33 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A METTRE EN NORMES


#include "ps.h"

// Fonction pour vérifier s'il y a un doublon dans la liste
int hasDuplicates(stack *stack, int value)
{
    stack_element *current;
    
    current = stack->a_top;
    while   (current != NULL)
    {
        if  (current->value == value)
        {
            return (0);
        }
        current = current->next;
    }
    return (1);
}


//A rajouter #hasduplicates pour les doublons
void pushtab(stack *a_list, int value)
{
    if (hasDuplicates(a_list, value) == 0) 
    {
        ft_printf("Error5\n");
        exit(EXIT_FAILURE);
    }
    stack_element *newnode = (stack_element*)malloc(sizeof(stack_element));
    if (!newnode)
    {
        ft_printf("Error6\n");
        exit(EXIT_FAILURE);
    }
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (!a_list->a_top)
        a_list->a_top = newnode;
    else
    {
        stack_element *current = a_list->a_top;
        while (current->next)
            current = current->next;
        current->next = newnode;
        newnode->prev = current;
    }
    a_list->size++;
}






// Fonction pour ajouter un élément à la pile tout en vérifiant les doublons

// void pushtab(stack *a_list, int value)
// {
//     stack_element *current;
//     stack_element *newnode;
    
//     if (hasDuplicates(a_list, value) == 0) 
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
//     if (a_list->a_top == NULL)
//     {
//         a_list->a_top = newnode;
//         return;
//     }
//     current = a_list->a_top;
//     while (current->next != NULL)
//         current = current->next;
//     current->next = newnode;
//     a_list->size++;
// }

// Fonction pour creeer le Tableau A
void tableaua(char *argv, stack *a_list)
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
            while   (ft_isdigit(*argv))
                argv++;
            pushtab(a_list, neg * i);
            argv++;
            neg = 1;
        }
        else
            argv++;
    }
}
