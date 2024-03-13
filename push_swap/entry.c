/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/13 16:49:05 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

//pas dans makefile

void    entry(stack *a_list, stack *b_list)
{
    // printf("Entrer dans la fonction ENTRY\n");
    // print_stack(a_list, b_list);
    // char    input[100];
    // int     min_index;
    
    // my_fgets(input, sizeof(input), stdin); // Lire l'entree de l'utilisateur
    // input[my_strcspn(input, "\n")] = '\0'; // Supprimer le caractere de nouvelle ligne
    // int i = 1;
    
// int half_size = a_list->size / 2;
// printf("Nombre d'éléments dans la pile A : %d\n", a_list->size);
// printf("Nombre d'éléments dans la pile B : %d\n", b_list->size);

    int half_size = a_list->size / 2;
    while (b_list->size < half_size)
    {
        ft_printf("pb\n");
        push_b(a_list, b_list); // Déplace un élément de a_list vers b_list
    }

sort_half_of_a(a_list, b_list);
    // int rotation;
    
    // while (!is_sorted(a_list) /*is_sorted(a_list) == 0 && !is_empty(b_list)*/)
    // {
    //     // printf("Entrer dans la boucle ALGO N* %d\n", i++);
    //     // min_index = find_min_index_a(a_list);
    //     // printf("Min index: %d\n", min_index);


        

    //     int max_index = find_max_index_b(a_list); // Trouver l'indice du plus grand élément dans b_list
    //     if (max_index > a_list->size / 2)
    //     {
    //         // printf("ici\n");
    //         rotation = a_list->size - max_index;
    //         while (rotation > 0)
    //         {
    //             ft_printf("rra\n");
    //             rrotate_a(a_list);
    //             rotation--;
    //         }
    //     }
    //     else
    //     {
    //         while (max_index != 0) // Tant que l'élément le plus grand n'est pas au sommet de la pile
    //         {
    //             ft_printf("ra\n");
    //             // printf("BOUCLE ROTATE : %d\n", i++);
    //             rotate_a(a_list); // Tourner la pile b_list vers le bas jusqu'à ce que le plus grand élément soit en haut
    //             // print_stack(a_list, b_list);
    //             max_index--;
    //         }
    //     }
        
    //     // Une fois que l'élément le plus grand est au sommet, pousser dans la pile a_list
    //     ft_printf("pa\n");
        // print_stack(a_list, b_list);













        
        // ft_printf("pb\n");
        
        // push_b(a_list, b_list);
        // b_list->size++;
        // a_list->size--;


        
        // if (min_index == 0)
        // {
        //     push_b(a_list, b_list); // Push l'élément en haut de la pile A sur la pile B
        // }
        // else if (min_index <= a_list->size / 2)
        // {
        //     rotate_a(a_list); // Rotate la pile A vers le haut
        // }
        // else
        // {
        //     rrotate_a(a_list); // Rotate la pile A vers le bas
        // }
        // if (!is_empty(a_list))
        // {
        //     restore_order(a_list, b_list);
        // }
        
        // printf("État de la pile a_list après cette itération: ------------------\n");
        // print_stack(a_list, b_list);
    // }

    // sort(a_list, b_list);
    
    // print_stack(a_list, b_list);
    // printf("Sortie Boucle ENTRY\n");
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


// Verification si la pile est trier
int is_sorted(stack *a_list)
{
    stack_element *current = a_list->a_top;

    while (current != NULL && current->next != NULL)
    {
        if (current->value < current->next->value)
        {
            return (0); // La pile n'est pas trier
        }
        current = current->next;
    }
    return (1); // La pile est trier
}

void restore_order(stack *a_list, stack *b_list)
{
    while (!is_empty(b_list, 'b')) 
    {
        push_a(a_list, b_list); // Déplace un élément de la pile B vers la pile A
    }
    return;
}

void print_stack(stack *s, stack*c)
{
    stack_element *current_s = s->a_top;
    stack_element *current_c = c->b_top;
    
    printf("Contenu de la pile A:\n");
    while (current_s != NULL)
    {
        printf(" | %d |\n", current_s->value);
        current_s = current_s->next;
    }
    printf("Contenu de la pile B:\n");
    while (current_c != NULL)
    {
        printf(" | %d |\n", current_c->value);
        current_c = current_c->next;
    }
    printf("\n");
}




void sort(stack *a_list, stack *b_list)
{
    // printf("Commencer le tri...\n");
    int rotation;
    while (!is_empty(b_list, 'b'))
    {
        // print_stack(a_list, b_list);
        int max_index = find_max_index_b(b_list); // Trouver l'indice du plus grand élément dans b_list
        if (max_index > b_list->size / 2)
        {
            // printf("ici\n");
            rotation = b_list->size - max_index;
            while (rotation > 0)
            {
                ft_printf("rrb\n");
                rrotate_b(b_list);
                rotation--;
            }
        }
        else
        {
            while (max_index != 0) // Tant que l'élément le plus grand n'est pas au sommet de la pile
            {
                ft_printf("rb\n");
                // printf("BOUCLE ROTATE : %d\n", i++);
                rotate_b(b_list); // Tourner la pile b_list vers le bas jusqu'à ce que le plus grand élément soit en haut
                // print_stack(a_list, b_list);
                max_index--;
            }
        }
        
        // Une fois que l'élément le plus grand est au sommet, pousser dans la pile a_list
        ft_printf("pa\n");
        push_a(a_list, b_list);
        // print_stack(a_list, b_list);
    }

    // printf("Tri terminé.\n");
}



void sort_half_of_a(stack *a_list, stack *b_list)
{
    int half_size = a_list->size / 2;
    
    while (b_list->size < half_size)
    {
        int max_index = find_max_index_a(a_list);
        if (max_index > a_list->size / 2)
        {
            while (max_index != 0)
            {
                rrotate_a(a_list);
                max_index--;
            }
        } else {
            while (max_index != 0)
            {
                rotate_a(a_list);
                max_index--;
            }
        }
        push_b(a_list, b_list);
    }
    
    // Tri de la pile B
    sort(b_list, a_list);
    
    // Ramener les éléments de la pile B vers la pile A dans l'ordre trié
    // while (!is_empty(b_list)) {
    //     push_a(a_list, b_list);
    // }
}
