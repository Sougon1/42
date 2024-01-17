/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 11:38:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    pushtab(Stack *stack, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node))
    if (!newnode)
    {
        ft_printf("Erreur allocation memoire");
        exit(EXIT_FAILURE);
    }
    newnode->value = value;
    newnode->next = stack->top;
    stack->top = newnode;
    
}

void processNumber(char *numberStr, Stack* myStack, int sign)
{
    int num;

    num = 0;
    while (*numberStr >= '0' && *numberStr <= '9')
    {
        num = num * 10 + (*numberStr - '0');
        numberStr++;
    }
    pushtab(myStack, sign * num);
}

void tableaua(char *argv, Stack *myStack)
{
    int i;
    int neg;

    i = 0;
    neg = 1;
    while (argv[i])
    {
        if (argv[i] == '-')
        {
            neg = -1;
            i++;
        }
        else if (argv[i] >= '0' && argv[i] <= '9') 
        {
            processNumber(&argv[i], myStack, neg);
            neg = 1;
        }
        else
            i++;
    }
}