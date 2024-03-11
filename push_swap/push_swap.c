/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/11 13:47:03 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"



/*int push_swap()
{
    return ;
}*/

void initializelist(stack* stack)
{
    stack->a_top = NULL;
    stack->b_top = NULL;
}

int main(int argc, char *argv[])
{
    long long   i;

    i = 1;
    if (argc < 2)
    {
        ft_printf("Error\n");
        return (0);
    }
    while(argv[i])
    {
        if(security(argv[i]) == 0)
            return (0);
        i++;
    }
    stack a_list;
    stack b_list;
    initializelist(&a_list);
    initializelist(&b_list);
    
    tableaua(argv[1], &a_list);   
    
    stack_element *current = a_list.a_top;
//b_list *currentb = b_list.b_top;

    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

//Quitter le programme

    while (1)
    {
        entry();
    }

    return (0);
}
