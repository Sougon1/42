/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/20 15:37:08 by ghumm            ###   ########.fr       */
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
    long long   i;

    i = 1;
    if (argc < 2)
    {
//        ft_printf("ERREUR : Arguments insuffisants\n");
        printf("ERREUR : Arguments insuffisants\n");
        return (0);
    }
    while(argv[i])
    {
        if(security(argv[i]) == 0)
            return (0);
        i++;
    }
    stack pilea;
    stack pileb;
    initializelist(&pilea);
    initializelist(&pileb);
    
    tableaua(argv[1], &pilea);   
    
//stack myStack = { .top = NULL }; // ou une autre valeur initiale appropriée
t_list *current = pilea.top;


  
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    
 //   push_swap(&pilea);

    return (0);
}
