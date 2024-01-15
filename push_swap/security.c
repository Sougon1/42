/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:59 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/15 10:54:41 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int security(char* argv)
{
    while(argv++)
    {
        if(ft_isdigitnospace(argv)==1)
            break;
        else
            ft_printf("Erreur, uniquement des nombres autoriser")
    }
    
    
}

int ft_isdigitnospace(int a)
{
    if (a >= 48 && a <= 57 || a == 32)
		return (1);
	return (0);
}