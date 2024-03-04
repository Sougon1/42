/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/04 16:46:04 by ghumm            ###   ########.fr       */
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
        if (strcmp(input, "exit") == 0)
        {
            break; // Quitter la boucle
        } else {
            printf("Commande inconnue. Entrez 'exit' pour quitter : ");
        }
 }



 //   push_swap(&pilea);

    return (0);
}
