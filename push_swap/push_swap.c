/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/12 13:45:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ps.h"

int push_swap()
{

}

int main(int argc, char *argv[])
{
    int taille_pile;
    int pile_a[];
    int pile_b[];
    int *ptr_pile_a;
    char    **ptr_argv;

    if (argc < 2)
    {
        ft_printf("ERREUR : Pas assez d'arguments\n");
        return (1);
    }   
    taille_pile = argc - 1;
    pile_a[taille_pile];
    pile_b[taille_pile];
    ptr_pile_a = pile_a;
    ptr_argv = argv + 1;
    while (*ptr_argv)
    {
        *ptr_pile_a++ = ft_atoi(*ptr_argv++)
    }
    push_swap(int argc)
    
}