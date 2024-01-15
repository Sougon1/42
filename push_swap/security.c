/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:59 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/15 14:11:48 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int security(char* argv)
{
    int i;

    i = 0;
    while(argv[i] != '\0')
    {
        if(ft_isdigitnospace(argv[i]) == 0)
        {
            ft_printf("Erreur, uniquement des nombres  autorisés.\n")
            return (0);
        }
        i++;
    }
    
    return (1);
}

int ft_isdigitnospace(int a)
{
    if  ((a >= 48 && a <= 57) || a == 32)
		return (1);
	return (0);
}