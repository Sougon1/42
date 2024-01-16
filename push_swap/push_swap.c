/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/16 12:36:22 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ps.h"

int tableaua(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] == '-')
        {
            while (argv[i] != 32)
            {
                Stack->pilea = argv[i];
                i++;
            }
            
        }
        
    }
    
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