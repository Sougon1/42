/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_infdix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:49:14 by ghumm             #+#    #+#             */
/*   Updated: 2024/04/16 16:15:37 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    infdix(int argc, stack *a_list, stack *b_list)
{
    if  (argc == 3)
    {
        ft_printf("sa\n");
        swap_a(a_list);
    }
    else if (argc == 4)
    {
        tree(a_list);
    }
    else if (argc == 6)
    {
        five(a_list, b_list);
    }
    // else if (/* condition */)
    // {
    //     /* code */
    // }
}

void    tree(stack *a_list)
{
    stack_element *current;
    int max_index_value_a;

    current = a_list->a_top;
    max_index_value_a = find_max_index_a(a_list);

    while   (max_index_value_a++ < 2)
    {
        ft_printf("rra\n");
        rrotate_a(a_list);
    }
    current = a_list->a_top;
    if  (current->value > current->next->value)
    {
        ft_printf("sa\n");
        swap_a(a_list);
    }
}

void    five(stack *a_list, stack *b_list)
{
    int index_min_value_a;
    int i;

    i = 2;

    while (i-- > 0)
    {
        index_min_value_a = find_min_index_a(a_list);

        while (index_min_value_a-- > 0)
        {
            ft_printf("ra\n");
            rotate_a(a_list);
        }
        ft_printf("pb\n");
        push_b(a_list, b_list);
    }
    tree(a_list);
    while (!is_empty(b_list, 'b'))
    {
        ft_printf("pa\n");
        push_a(a_list, b_list);
    }
}
