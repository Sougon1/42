/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/04/24 13:22:23 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    sorted(int argc, stack *a_list, stack *b_list)
{
    while (a_list)
    {
                                                // print_stack(a_list, b_list);
        if (is_sorted(a_list))
        {
            break;
        }
        else if (argc == 3 || argc == 4 || argc == 6)
        {
            infdix(argc, a_list);
            break;
        }
        else
        {
            entry(a_list, b_list);
            break;
        }
    }
    // return;
}

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


    // if(is_sorted(a_list) == 1)
    // {
    //     return;
    // }
    
    // ft_printf("A size %i\n", a_list->size);
    // ft_printf("B size %i\n", b_list->size);

    
    stack_element *current_a;
    
    stack_element *current_b;
    
    // int last_value_b;
    // int max_value_b;
    int max_value_a;
    // int min_value_a;
    
    // print_stack(a_list, b_list);

 
    int size = a_list->size / 2;
    int size2 = 0;

    while (size != 0)
    {
        ft_printf("pb\n");
        push_b(a_list, b_list);
        size2++;
        size--;
    }
    
    sort(a_list, b_list);
    
    while (size2 != 0)
    {
        ft_printf("rra\n");
        rrotate_a(a_list);
        ft_printf("pb\n");
        push_b(a_list, b_list);
        size2--;
    }
    
    sort_stack_b(a_list, b_list);

    while (!is_sorted(a_list))
    {
        ft_printf("ra\n");
        rotate_a(a_list);
    }
    


  





    while (!is_empty(a_list, 'a'))
    {

        break;
    // ft_printf("\nA size : %i\n", a_list->size);
    // ft_printf("B size : %i\n\n", b_list->size);
        // ft_printf("1\n");

        current_a = a_list->a_top;
        // current_b = b_list->b_top;

        
        // ft_printf("current-a value1 : %i\n", current_a->value);
        // current_b = b_list->b_top;
        // last_value_b = find_last_value_b(b_list);
        // max_value_b = find_max_value_b(b_list);
        max_value_a = find_max_value_a(a_list);
        // min_value_a = find_min_value_a(a_list);
        
        // print_stack(a_list, b_list);
        
        // find_nearest_value_index(a_list, max_value_a);

        // // // ft_printf("A size : %i\n", a_list->size);
        
        // ft_printf("pb\n");
        // push_b(a_list, b_list);



        while (current_a->value <= max_value_a)
        {
            // ft_printf("current-a value2 : %i\n", current_a->value);
        
            if (current_a->value >= max_value_a * 0.85 || current_a->value == max_value_a)
            {
                ft_printf("pb\n");
                push_b(a_list, b_list);
                break;
            }
            else
            {
                ft_printf("ra\n");
                rotate_a(a_list);
                // print_stack(a_list, b_list);
                current_a = a_list->a_top;
            }
            current_b = b_list->b_top;
            if (current_b != NULL && current_b->next != NULL && current_b->next->next != NULL)
            {
                if (current_b->value > current_b->next->value && current_a->next->value >= max_value_a && current_a->value <= max_value_a)
                {
                    ft_printf("ss\n");
                    swap_ab(a_list, b_list);
                }
            }
        }





        // ft_printf("pb\n");
        // push_b(a_list, b_list);

        // current_b = b_list->b_top;
      /*  if (current_b != NULL && current_b->next != NULL && current_b->next->next != NULL)
            {
                if (b_list->size == 3)
                {
                    if (current_b->value / 2 < current_b->next->next->value / 2)
                    {
                        ft_printf("rb\n");
                        rotate_b(b_list);
                    }
                    else
                        continue;
                }
                else if (current_b->value > current_b->next->value && current_b->value > current_b->next->next->value)
                {
                    if (current_b->value / 4 > current_b->next->value * 0.5)
                    {
                        continue;
                    }
                    
                    ft_printf("sb\n");
                    swap_b(b_list);
                    // if (current_a->value < last_value_b)
                    // {
                    //     ft_printf("rr\n");
                    //     rotate_ab(a_list, b_list);
                    // }                    
                    // else
                    // {
                    //     ft_printf("rb\n");
                    //     rotate_b(b_list);
                    // }
                    last_value_b = find_last_value_b(b_list);
                    current_b = b_list->b_top;
                    if (current_b->value / 2 < last_value_b)
                    {
                        
                    }
                    
                    ft_printf("rb\n");
                    rotate_b(b_list);
                    
                    ft_printf("sb\n");
                    swap_b(b_list);
                    
                    current_a = a_list->a_top;
                    ft_printf("current-a value3 : %i\n", current_a->value);
                    if (current_a != NULL && current_a->next != NULL && current_a->next->next != NULL)
                    {
                        if  (current_a->value < max_value_a / 2 && last_value_b > 0.9 * current_b->value)
                        {
                            ft_printf("rrr\n");
                            rrotate_ab(a_list, b_list);
                        }
                    }                    
                    // METTRE CONDITION POUR LE RROTATE // a remettre 
                    // ft_printf("rrb\n");
                    // rrotate_b(b_list);
                    
                    // if (current_b->value > current_b->next->value)
                    // {
                    //     ft_printf("sb\n");
                    //     swap_b(b_list);
                    // }
                    // else
                    // {
                    //     ft_printf("rb\n");
                    //     rotate_b(b_list);
                    // }
                    // if (current_b->value / 2 > last_value_b)
                    // {
                    //     ft_printf("rrb\n");
                    //     rrotate_b(b_list);
                    // }
                    // else
                    // {
                    //     ft_printf("sb\n");
                    //     swap_b(b_list);
                    // }

                    // current_b = b_list->b_top;
                    // if (current_b->value > current_b->next->value)
                    // {
                    //     ft_printf("sb\n");
                    //     swap_b(b_list);
                    // }

                }
                else if (current_b->value > current_b->next->value)
                {
                    ft_printf("sb\n");
                    swap_b(b_list);
                }
                else
                {//Condition a mettre ?
                    // if (current_b->value / 2 > current_b->next->value / 3)
                    // {// A CHANGER CE QUIL DOIS FAIRE 
                    // //continue; ?
                    //     // ft_printf("rrb\n");
                    //     // rrotate_b(b_list);
                    //     continue;
                    // }
                    // else
                    // {
                    //     ft_printf("rb\n");
                    //     rotate_b(b_list);
                    // }
                    continue;
                }
            }*/

            // // 2 lignes a suppr
            // current_a = a_list->a_top;
            // ft_printf("current-a value4 : %i\n", current_a->value);
        // ft_printf("pb\n");
        // push_b(a_list, b_list); // Déplace un élément de a_list vers b_list
    }

    // ft_printf("SORTIE\n");
// sort_half_of_a(a_list, b_list);


    // while (!is_empty(a_list, 'a'))
    // {
    // // printf("Nombre d'éléments dans la pile A : %d\n", a_list->size);
    // int max_index_a = find_max_index_a(a_list); // Trouver l'indice du plus grand élément dans a_list
    // int max_index_b = find_max_index_b(b_list);
    // if (max_index_a == 0)
    // {
    //     // L'élément maximum est déjà en haut de la pile A, pas besoin de rotation
    //     ft_printf("pb\n"); // Intervertir les 2 premiers éléments au sommet de la pile a
    //     push_b(a_list, b_list);
    //     // swap_a(a_list);
    // }
    // else if (max_index_a <= a_list->size / 2)
    // {
    //     // Effectuer une rotation dans le sens des aiguilles d'une montre pour placer l'élément maximum en bas
        
    //     while (max_index_a != 0 && (max_index_b < b_list->size / 2))
    //     {
            
    //     }
        
    //     if (max_index_b <= b_list->size / 2)
    //     {
    //         while (max_index_a != 0)
    //         {
    //             ft_printf("rr\n");
    //             rotate_ab(a_list, b_list);
    //             // ft_printf("sb\n");
    //             // swap_b(b_list);
    //             max_index_b--;
    //         }
    //     }   
    //     while (max_index_a != 0)
    //     {
    //         ft_printf("ra\n");
    //         rotate_a(a_list);
    //         max_index_a--;
    //     }

    // }
    // else
    // {
    //     // Effectuer une rotation dans le sens inverse des aiguilles d'une montre pour placer l'élément maximum en haut
    //     int rotation_a = a_list->size - max_index_a;
    //     int rotation_b = b_list->size - max_index_b;
    //     while (rotation_a > 0)
    //     {
    //         if (rotation_b > 0)
    //         {
    //             ft_printf("rrr\n");
    //             rrotate_ab(a_list, b_list);
    //             rotation_b--;
    //         }
    //         // else
    //         // {
    //             ft_printf("rra\n");
    //             rrotate_a(a_list);
    //         // }
    //         rotation_a--;
    //     }
    // }
    // // Supprimer l'élément maximum de la pile A
    // ft_printf("pb\n");
    // push_b(a_list, b_list); // Déplacer l'élément maximum de la pile A vers la pile B
    // // printf("Nombre d'éléments dans la pile A : %d\n", a_list->size);
    // // print_stack(a_list, b_list);
    // }


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
    
    // current_a = a_list->a_top;

    // size_a = a_list->size - size;
    
    // max_value_a = find_max_value_a(a_list);

    // while (size_a != 0)
    // {
        
    //     ft_printf("rra\n");
    //     rrotate_a(a_list);
    //     ft_printf("pb\n");
    //     push_b(a_list, b_list);
    //     size_a--;
    // }
    


    
    
    // sort(a_list, b_list);
    






    // print_stack(a_list, b_list);
    

    // printf("Sortie Boucle ENTRY\n");
    //restore_order(&a_list, &b_list);

    return;
}


// Verification si la pile est trier
int is_sorted(stack *stack)
{
    stack_element *current;
    
    current = stack->a_top;

    while (current != NULL && current->next != NULL)
    {
        if (current->value > current->next->value)
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
// va partir
void print_stack(stack *a_list, stack*b_list)
{
    stack_element *current_a = a_list->a_top;
    stack_element *current_b = b_list->b_top;
    
    printf("Contenu de la pile A:\n");
    while (current_a != NULL)
    {
        printf(" | %d |\n", current_a->value);
        current_a = current_a->next;
    }
    printf("\nContenu de la pile B:\n");
    while (current_b != NULL)
    {
        printf(" | %d |\n", current_b->value);
        current_b = current_b->next;
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
        if (max_index <= b_list->size / 2)
        {
            // printf("ici\n");
            while (max_index != 0)
            {
                ft_printf("rb\n");
                rotate_b(b_list);
                max_index--;
            }
        }
        else
        {
            rotation = b_list->size - max_index;
            while (rotation > 0) // Tant que l'élément le plus grand n'est pas au sommet de la pile
            {
                ft_printf("rrb\n");
                // printf("BOUCLE ROTATE : %d\n", i++);
                rrotate_b(b_list); // Tourner la pile b_list vers le bas jusqu'à ce que le plus grand élément soit en haut
                // print_stack(a_list, b_list);
                rotation--;
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
        // push_b(a_list, b_list);
    }
    
    // Tri de la pile B
    // sort(b_list, a_list);
    
    // Ramener les éléments de la pile B vers la pile A dans l'ordre trié
    // while (!is_empty(b_list)) {
    //     push_a(a_list, b_list);
    // }
}


int average_a(stack *a_list)
{
    int sum;
    int count;
    stack_element *current;
    current = a_list->a_top;

    if (current == NULL && current->next == NULL && current->next->next == NULL)
    {
        return (0);
    }
    
    current = a_list->a_top;
    sum = 0;
    count = 0;
    
    while (current != NULL)
    {
        sum += current->value;
        count++;
        current = current->next;
    }
    
    if (count == 0)
    {
        return (0);
    }

    return (sum / count);
}

int average_b(stack *b_list)
{
    int sum;
    int count;
    stack_element *current;
    current = b_list->b_top;

    if (current == NULL && current->next == NULL && current->next->next == NULL)
    {
        return (0);
    }
    

    current = b_list->b_top;
    sum = 0;
    count = 0;
    
    while (current != NULL)
    {
        sum += current->value;
        count++;
        current = current->next;
    }
    
    if (count == 0)
    {
        return (0);
    }

    return (sum / count);
}




void sort_stack_b(stack *a_list, stack *b_list)
{
     // printf("Commencer le tri...\n");
    int rotation;
    while (!is_empty(b_list, 'b'))
    {
        // print_stack(a_list, b_list);
        int min_index = find_min_index_b(b_list); // Trouver l'indice du plus grand élément dans b_list
        if (min_index <= b_list->size / 2)
        {
            // printf("ici\n");
            while (min_index-- != 0)
            {
                ft_printf("rb\n");
                rotate_b(b_list);
            }
        }
        else
        {
            rotation = b_list->size - min_index;
            while (rotation-- > 0) // Tant que l'élément le plus grand n'est pas au sommet de la pile
            {
                ft_printf("rrb\n");
                // printf("BOUCLE ROTATE : %d\n", i++);
                rrotate_b(b_list); // Tourner la pile b_list vers le bas jusqu'à ce que le plus grand élément soit en haut
                // print_stack(a_list, b_list);
            }
        }
        
        stack_element   *current_a = a_list->a_top;
        stack_element   *current_b = b_list->b_top;
        
        while (current_b->value > current_a->value)
        {         
            ft_printf("ra\n");
            rotate_a(a_list);
            current_a = a_list->a_top;            

        }
        
        ft_printf("pa\n");
        push_a(a_list, b_list);
    }

}



