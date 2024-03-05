/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/05 11:35:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"



/*int push_swap()
{
    return ;
}*/

void initializelist(stack* stack)
{
    stack->top = NULL;
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
    stack pilea;
    stack pileb;
    initializelist(&pilea);
    initializelist(&pileb);
    
    tableaua(argv[1], &pilea);   
    
a_list *current = pilea.top;

    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

//Quitter le programme
    char input[100];
 while (1)
 {
        fgets(input, sizeof(input), stdin); // Lire l'entrée de l'utilisateur
        input[strcspn(input, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne

        // Comparer l'entrée de l'utilisateur avec le mot spécifique
         if (ft_strncmp(input, "exit", 4) == 0)
         {
            // Si la longueur de l'entrée est supérieure à 4, cela signifie qu'il y a des caractères supplémentaires
            if (ft_strlen(input) > 4)
            {
                ft_printf("Commande invalide. Assurez-vous de taper 'exit' correctement : ");
            }
            else
            {
                ft_printf("Commande de sortie détectée. Sortie du programme.\n");
                break;
            }
        }
        else
        {
            ft_printf("Commande inconnue. Entrez 'exit' pour quitter : ");
        }
 }



 //   push_swap(&pilea);

    return (0);
}
