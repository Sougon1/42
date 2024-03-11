/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 17:20:51 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

//pas dans makefile

void    entry(stack *a_list, stack *b_list)
{
    printf("Entrer dans la fonction ENTRY\n");
    print_stack(a_list, b_list);
    // char    input[100];
    int     min_index;
    
    // my_fgets(input, sizeof(input), stdin); // Lire l'entree de l'utilisateur
    // input[my_strcspn(input, "\n")] = '\0'; // Supprimer le caractere de nouvelle ligne
    
    while (!is_sorted(a_list) /*&& !is_empty(b_list)*/)
    {
        printf("Entrer dans la boucle ALGO\n");
        min_index = find_min_index(a_list);
        printf("Min index: %d\n", min_index);      
        // if (is_empty(a_list))
        // {
        //     restore_order(a_list, b_list);
        // }
        if (min_index == 0)
        {
            push_b(a_list, b_list); // Push l'élément en haut de la pile A sur la pile B
        }
        else if (min_index <= a_list->size / 2)
        {
            rotate_a(a_list); // Rotate la pile A vers le haut
        }
        else
        {
            rrotate_a(a_list); // Rotate la pile A vers le bas
        }
        if (is_empty(a_list))
        {
            restore_order(a_list, b_list);
        }
        printf("État de la pile a_list après cette itération:\n");
        print_stack(a_list, b_list);
    }
     printf("Sortie Boucle ENTRY\n");
    //restore_order(&a_list, &b_list);

    return;
//    exit_program(input);
}

void    exit_program(char   *input)
{
       // Comparer l'entree de l'utilisateur avec le mot specifique
    if (ft_strncmp(input, "exit", 4) == 0)
    {
        // Si la longueur de l'entree est superieure a 4, cela signifie qu'il y a des caracteres supplementaires
        if (ft_strlen(input) != 4)
            ft_printf("Commande invalide. Assurez-vous de taper 'exit' correctement : ");
        else
        {
            ft_printf("Commande de sortie détectée. Sortie du programme.\n");
            exit(EXIT_SUCCESS);
        }
    }
    else
        ft_printf("Commande inconnue. Entrez 'exit' pour quitter : ");
}


// Verification si la pile est tier
int is_sorted(stack *a_list)
{
    stack_element *current = a_list->a_top;

    while (current != NULL && current->next != NULL)
    {
        if (current->data > current->next->data)
        {
            return (0); // La pile n'est pas trier
        }
        current = current->next;
    }
    return (1); // La pile est trier
}

int find_min_index(stack *a_list)
{
    // Vérifier si la pile est vide
    if (is_empty(a_list) || a_list->a_top == NULL)
    {
        return -1;
    }

    stack_element *current = a_list->a_top;
    int min_index = 0;
    int min_value = current->data;
    int i = 0;

    while (current != NULL)
    {
        if (current->data < min_value)
        {
            min_value = current->data;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    return min_index;
}

void restore_order(stack *a_list, stack *b_list)
{
    while (!is_empty(b_list)) 
    {
        push_a(a_list, b_list); // Déplace un élément de la pile B vers la pile A
    }
}

int is_empty(stack *s)
{
    if (s == NULL)
        return (1);
    return (0);
}

void print_stack(stack *s, stack*c)
{
    stack_element *current_s = s->a_top;
    stack_element *current_c = c->b_top;
    
    printf("Contenu de la pile A:\n");
    while (current_s != NULL)
    {
        printf("%d\n", current_s->value);
        current_s = current_s->next;
    }
    printf("Contenu de la pile B:\n");
    while (current_c != NULL)
    {
        printf("%d\n", current_c->value);
        current_c = current_c->next;
    }
    printf("\n");
}
