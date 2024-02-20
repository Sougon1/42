/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:38:23 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 11:30:57 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    pushtab(stack *stack, int value)
{
    t_list* newnode = (t_list*)malloc(sizeof(t_list));
    if (!newnode)
    {
        ft_printf("Erreur allocation memoire");
        exit(EXIT_FAILURE);
    }
    newnode->value = value;
    newnode->next = stack->top;
    stack->top = newnode;

}

void processNumber(char *numberStr, stack *myStack, int sign)
{
    int num;

    num = 0;
    while (*numberStr >= '0' && *numberStr <= '9')
    {
        num = num * 10 + (*numberStr - '0');
        numberStr++;
    }
    pushtab(myStack, sign * num);
}

// void tableaua(char *argv, stack *myStack)
// {
//     int i;
//     int neg;

//     i = 0;
//     neg = 1;
//     while (argv[i])
//     {
        
//         printf("ici %c\n", argv[i]);
//         if (argv[i] == '-')
//         {
//             neg = -1;
//             i++;
//         }        
//         else if (argv[i] >= '0' && argv[i] <= '9') 
//         {
//             processNumber(&argv[i], myStack, neg);
//             neg = 1;
//             while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
//                 i++;
//         }
//         else
//             i++;
//     }
// }

void tableaua(char *argv, stack *myStack)
{
    char *token = strtok(argv, " \""); // Diviser la chaîne en jetons en utilisant les espaces et les guillemets comme délimiteurs

    while (token != NULL)
    {
        int neg = 1; // Réinitialiser le signe pour chaque nouvel argument

        for (int i = 0; token[i]; i++)
        {
            if (token[i] == '-')
            {
                neg = -1;
                i++; // Avancez l'indice ici pour passer au caractère suivant après le signe négatif
            }
            else if (token[i] >= '0' && token[i] <= '9') 
            {
                processNumber(&token[i], myStack, neg);
                neg = 1;
                // Avancez jusqu'à la fin du nombre
                while (token[i] && (token[i] >= '0' && token[i] <= '9'))
                {
                    i++;
                }
            }
        }

        token = strtok(NULL, " \""); // Passer au prochain jeton
    }
}





