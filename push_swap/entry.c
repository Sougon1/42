/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/08 13:20:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

//pas dans makefile

char    entry(char input)
{
    my_fgets(input, sizeof(input), stdin); // Lire l'entrée de l'utilisateur
    input[my_strcspn(input, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
    // if (/* condition */)
    // {
    //     /* code */
    // }





    // Comparer l'entrée de l'utilisateur avec le mot spécifique
    if (ft_strncmp(input, "exit", 4) == 0)
    {
        // Si la longueur de l'entrée est supérieure à 4, cela signifie qu'il y a des caractères supplémentaires
        if (ft_strlen(input) != 4)
            ft_printf("Commande invalide. Assurez-vous de taper 'exit' correctement : ");
        else
        {
            ft_printf("Commande de sortie détectée. Sortie du programme.\n");
            break;
        }
    }
    else
        ft_printf("Commande inconnue. Entrez 'exit' pour quitter : ");
}