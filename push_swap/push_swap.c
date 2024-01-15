/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/15 15:57:35 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ps.h"

int tableaua(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        while (argv[i] == 32 )
            i++;
        
    }
    
}

int push_swap()
{

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
    
    tableaua(argv[1]);
    push_swap(argv[1]);

    return (0);
}