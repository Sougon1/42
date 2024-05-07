/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/07 16:35:24 by ghumm            ###   ########.fr       */
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
    stack->size = 0;
}

int main(int argc, char *argv[])
{
    long long   i;
    // int sorting_done = 0; // Indicateur pour savoir si le tri est terminé

    i = 1;
    if (argc == 1)
    {       
        return (0);
    }
    //a enlever quand tout fini : ce qui est en commentaire ci dessus
    // else if (argc == 2)
    // {
    //     ft_printf("Error1\n");
    //     return (0);
    // }
    //jusque la
    
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
    
    // print_stack(&a_list, &b_list);

    tableaua(argv[1], &a_list); 
 
    
    // print_stack(&a_list, &b_list);

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

    // print_stack(&a_list, &b_list);



    sorted(argc, &a_list, &b_list);
    
    

    print_stack(&a_list, &b_list);
    
    free_stack(&a_list);
    free_stack(&b_list);
    
    exit(EXIT_SUCCESS);
}

void free_stack(stack *s)
{
    stack_element *current = s->a_top;
    stack_element *next;

    // Libérer la mémoire pour chaque élément de la pile A
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    // Réinitialiser les pointeurs de la pile A
    s->a_top = NULL;
    s->b_top = NULL;

    // Réinitialiser la taille de la pile à zéro
    s->size = 0;
}
