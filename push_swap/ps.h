/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/08 12:43:13 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_H
# define PS_H

# include "libft/libft.h"

typedef struct s_stack_element
{
	int					value;
	struct s_stack_element		*next;
	struct s_stack_element		*prev;
	int					index;
}	stack_element;

typedef struct s_stack
{
	stack_element	*a_top;
	stack_element	*b_top;
	int				size;
}	stack;


//entry
void	entry();
void 	sorted();

int		is_sorted(stack *a);
int 	is_empty(stack *s, char pile);


void    ind_tab(stack *a_list, stack *b_list);
void    bubble_sort(int *tab, int taille);
void    index_tab_a(stack *a_list, int *tab);
void    push_index_b(stack *a_list, stack *b_list, int *tab);
void	sort(stack *b_list, stack *a_list);



//algo_infdix -- AU Normes
void	infdix();
void	tree();
void	five();


//push_swap --> AU Normes
void	initializelist();
void	free_stack();


//securityint -- > AU Normes
int	securityint(char *argv);
long long	ft_atoll(const char *str);


//security --> AU Normes
int	ft_isdigitnospace(int a);
int	security(char* argv);

//tableaua -- > AU Normes 
void	tableaua(char *argv, stack *myStack);
void	pushtab(stack *stack, int value);
void	duplicate(stack *a_list, int value);
int		has_duplicates(stack *myStack, int value);


////////////////
//REGLES/////////////////////////////// --> AU Normes

// Pile A = 'a'
// Pile B = 'b'
// Pile AB = 'c'

//push
void    push_a(stack *a_stack, stack *b_stack);
void    push_b(stack *a_stack, stack *b_stack);
void    push(stack *a_list, stack *b_list, char pile);

//swap
void    swap_a(stack *stack);
void    swap_b(stack *stack);
void    swap_ab(stack *a_list, stack *b_list);
void    swap(stack *a_list, stack *b_list, char pile);

//rotate
void    rotate_a(stack *stack);
void    rotate_b(stack *stack);
void    rotate_ab(stack *a_list, stack *b_list);
void    rotate(stack *a_list, stack *b_list, char pile);

//reverse rotate
void    rrotate_a(stack *stack);
void    rrotate_b(stack *stack);
void    rrotate_ab(stack *a_list, stack *b_list);
void    rrotate(stack *a_list, stack *b_list, char pile);

//FIN REGLES/////////////////////////////
/////////////////

//utilities1



//Find Value --> AU Normes
int find_max_value_a(stack *a_list);
int find_max_value_b(stack *b_list);
int find_min_value_a(stack *a_list);
int find_min_value_b(stack *b_list);


//Find Index --> AU Normes
int find_max_index_b(stack *b_list);
int find_max_index_a(stack *a_list);
int find_min_index_a(stack *stack);
int find_min_index_b(stack *stack);

//Find last value --> AU Normes
int find_last_value_a(stack *a_list);
int find_last_value_b(stack *b_list);


// Je laisse ou supprime ? 
//Nearest
void	find_nearest_value_index(stack *a_list, int max_value_a);
void    find_nearest_neg(stack *a_list);
void    find_nearest_min_value(stack *a_list, int min_value_a);







#endif