/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_infdix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:49:14 by ghumm             #+#    #+#             */
/*   Updated: 2024/04/15 14:51:24 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    infdix(int argc, stack *a_list/*, stack *b_list*/)
{
    if (argc == 3)
    {
        ft_printf("sa\n");
        swap_a(a_list);
    }    
    else if (argc == 4)
    {
        tree(a_list);
    }
    // else if (argc == 6)
    // {
    //     six(a_list, b_list);
    // }
    // else if (/* condition */)
    // {
    //     /* code */
    // }
    
    
}

void    tree(stack *a_list)
{
    stack_element *current;
    
    current = a_list->a_top;
    
    if (current->value > current->next->value)
    {
        ft_printf("sa\n");
        swap_a(a_list);
    }
    if (current->value > current->next->next->value)
    {
        ft_printf("rra\n");
        rrotate_a(a_list);
    }
    // else if (current->value < current->next->next->value)
    // {
    //     ft_printf("ra\n");
    //     rotate_a(a_list);
    // }
    return; 
}
