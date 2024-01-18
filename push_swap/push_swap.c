/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/18 12:18:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"



/*int push_swap()
{
    return ;
}*/

void initializelist(stack* stack)
{
    stack->top = NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
//        ft_printf("ERREUR : Arguments insuffisants\n");
        printf("ERREUR : Arguments insuffisants\n");
        return (0);
    }
    if(security(argv[1]) == 0)
        return (0);
    stack pilea;
    stack pileb;
    initializelist(&pilea);
    initializelist(&pileb);
    
    tableaua(argv[1], &pilea);   
    
stack myStack;
t_list *current = myStack.top;

  
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    
 //   push_swap(&pilea);

    return (0);
}