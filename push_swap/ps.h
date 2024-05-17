/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/17 17:04:35 by marvin           ###   ########.fr       */
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
void 	sorted();



void    ind_tab(stack *a_list, stack *b_list);
void    bubble_sort(int *tab, int taille);
void    index_tab_a(stack *a_list, int *tab);
void    push_index_b(stack *a_list, stack *b_list, int *tab);

int	max_size(int *a_size);



int	get_start_index(int *a_size, int *max_size_a);

void	move_elements(stack *a_list, stack *b_list, int max_size_a, int *a_size);

void	update_and_sort(stack *a_list, stack *b_list, int *tab, int *one_two, int *a_size, int max_size_a);

void	rotate_or(stack *a_list, stack *b_list);
int	push_or(stack *a_list, stack *b_list, int a_size, int *max_size_a);



//algo_infdix --> OK
void	infdix();
void	tree();
void	five();
int		is_sorted(stack *a);
void	sort(stack *b_list, stack *a_list);



//push_swap --> OK
void	initializelist();
void	free_stack();


//securityint -- > OK
int	securityint(char *argv);
long long	ft_atoll(const char *str);


//security --> OK
int	ft_isdigitnospace(int a);
int	security(char* argv);

//tableaua -- > OK
void	tableaua(char *argv, stack *myStack);
void	pushtab(stack *stack, int value);
void	duplicate(stack *a_list, int value);
int		has_duplicates(stack *myStack, int value);


////////////////
//REGLES/////////////////////////////// --> OK

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



//Find Value --> OK
int find_max_value_a(stack *a_list);
int find_max_value_b(stack *b_list);
int find_min_value_a(stack *a_list);
int find_min_value_b(stack *b_list);


//Find Index --> OK
int find_max_index_b(stack *b_list);
int find_max_index_a(stack *a_list);
int find_min_index_a(stack *stack);
int find_min_index_b(stack *stack);
int is_empty(stack *s, char pile);

//Find last value --> OK
int find_last_value_a(stack *a_list);
int find_last_value_b(stack *b_list);






#endif