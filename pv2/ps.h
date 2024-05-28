/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/27 13:24:34 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft/libft.h"

typedef struct s_stack_element
{
	int						value;
	struct s_stack_element	*next;
	struct s_stack_element	*prev;
	int						index;
}							t_stack_element;

typedef struct s_stack
{
	t_stack_element			*a_top;
	t_stack_element			*b_top;
	int						size;
}							t_stack;

// entry --> OK
void						sorted(int argc, t_stack *a_list, t_stack *b_list);
void						ind_tab(t_stack *a_list, t_stack *b_list);
void						bubble_sort(int *tab, int taille);
void						index_tab_a(t_stack *a_list, int *tab);
void						push_index_b(t_stack *a_list, t_stack *b_list,
								int *tab);

// utilitiesone --> OK
int							max_size(int *a_size);
int							get_start_index(int *a_size, int *max_size_a);
void						move_elements(t_stack *a_list, t_stack *b_list,
								int max_size_a, int *a_size);
void						rotate_or(t_stack *a_list, t_stack *b_list);
int							push_or(t_stack *a_list, t_stack *b_list,
								int a_size, int *max_size_a);

// algo_infdix --> OK
void						infdix(int argc, t_stack *a_list, t_stack *b_list);
void						tree(t_stack *a_list, t_stack *b_list);
void						five(t_stack *a_list, t_stack *b_list);
int							is_sorted(t_stack *a);
void						sort(t_stack *b_list, t_stack *a_list);

// push_swap --> OK
void						initializelist(t_stack *stack);
void						free_stack(t_stack *stack);

// securityint -- > OK
int							securityint(char *argv);
long long					ft_atoll(const char *str);

//	security --> OK
int							ft_isdigitnospace(int a);
int							security(char *argv);

// tableaua -- > OK
void						tableaua(char *argv, t_stack *myStack);
void						pushtab(t_stack *stack, int value);
void						duplicate(t_stack *a_list, int value);
int							has_duplicates(t_stack *myStack, int value);

////////////////
// REGLES/////////////////////////////// --> OK

// Pile A = 'a'
// Pile B = 'b'
// Pile AB = 'c'

// push
void						push_a(t_stack *a_stack, t_stack *b_stack);
void						push_b(t_stack *a_stack, t_stack *b_stack);
void						push(t_stack *a_list, t_stack *b_list, char pile);

// swap
void						swap_a(t_stack *stack);
void						swap_b(t_stack *stack);
void						swap_ab(t_stack *a_list, t_stack *b_list);
void						swap(t_stack *a_list, t_stack *b_list, char pile);

// rotate
void						rotate_a(t_stack *stack);
void						rotate_b(t_stack *stack);
void						rotate_ab(t_stack *a_list, t_stack *b_list);
void						rotate(t_stack *a_list, t_stack *b_list, char pile);

// reverse rotate
void						rrotate_a(t_stack *stack);
void						rrotate_b(t_stack *stack);
void						rrotate_ab(t_stack *a_list, t_stack *b_list);
void						rrotate(t_stack *a_list, t_stack *b_list,
								char pile);

// FIN REGLES/////////////////////////////
/////////////////

// utilities1

// Find Value --> OK
int							find_max_value_a(t_stack *a_list);
int							find_max_value_b(t_stack *b_list);
int							find_min_value_a(t_stack *a_list);
int							find_min_value_b(t_stack *b_list);

// Find Index --> OK
int							find_max_index_b(t_stack *b_list);
int							find_max_index_a(t_stack *a_list);
int							find_min_index_a(t_stack *stack);
int							find_min_index_b(t_stack *stack);
int							is_empty(t_stack *s, char pile);

// Find last value --> OK
int							find_last_value_a(t_stack *a_list);
int							find_last_value_b(t_stack *b_list);

#endif