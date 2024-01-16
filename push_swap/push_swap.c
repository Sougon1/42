/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/16 15:43:51 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ps.h"

void    tableaua(char *argv, Stack *myStack)
{
    int i = 0, num = 0, neg = 1;
    
    while (argv[i])
    {
        if (argv[i] == '-')
        {
            neg = -1;
            i++;
        }
        else if (argv[i] >= '0' && argv[i] <= '9')
        {
            while (argv[i] >= '0' && argv[i] <= '9')
            {
                num = num * 10 + (argv[i] - '0');
                i++;
            }
            push(myStack, neg * num);
            num = 0;
            neg = 1;
        }
        else
            i++;
    }
    if (num != 0)
        push(myStack, neg * num);
}


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

int push_swap()
{

}

void initializelist(Stack* stack)
{
    stack->top = NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        ft_printf("ERREUR : Arguments insuffisants\n");
        return (0);
    }
    if(security(argv[1]) == 0)
        return (0);
    Stack pilea;
    Stack pileb;
    initializelist(&pilea);
    initializelist(&pileb);
    
    tableaua(argv[1], &pilea);
    push_swap(&pilea);

    return (0);
}