/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/13 13:04:23 by ghumm            ###   ########.fr       */
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
    // int sorting_done = 0; // Indicateur pour savoir si le tri est terminé
   
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
    
    // stack_element *current_a = a_list.a_top;
    // stack_element *current_b = b_list.b_top;

    // while (current_a != NULL)
    // {
    //     printf("%d\n", current_a->value);
    //     current_a = current_a->next;
    // }

    // while (current_b != NULL)
    // {
    //     printf("%d\n", current_b->value);
    //     current_b = current_b->next;
    // }


//Quitter le programme

    // while (sorting_done == 0)
    // {
    //     printf("Etree MAIN Loop\n");
    //     entry(&a_list, &b_list);
    //     if (is_sorted(&a_list))
    //     {
    //         printf("Pile trier is sorted\n");
    //         sorting_done = 1;
    //     }
        
    // }
    
    entry(&a_list, &b_list);
    
    // while (current_a != NULL)
    // {
    //     printf("%d\n", current_a->value);
    //     current_a = current_a->next;
    // }
    // ft_printf("FIN\n");
    exit(EXIT_SUCCESS);
}
