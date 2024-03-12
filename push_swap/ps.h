/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/12 13:56:08 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_H
# define PS_H

# include "libft/libft.h"

typedef struct s_stack_element
{
	int					value;
	struct s_stack_element	*next;
}	stack_element;

// typedef struct a_list
// {
// 	int				value;
// 	struct a_list	*next;
// }	a_list;

// typedef struct b_list
// {
// 	int				value;
// 	struct b_list	*next;
// }	b_list;

typedef struct s_stack
{
	stack_element	*a_top;
	stack_element	*b_top;
	int				size;
}	stack;

// typedef struct {
// 	a_list	*a_top;
// 	b_list	*b_top;
// } stack;

//entry
void		entry();
void	exit_program(char *input);


int		is_sorted(stack *a);
void	restore_order(stack *a, stack *b);
int is_empty(stack *s, char pile);



//push_swap
void	initializelist(stack* stack);


//securityint
int	securityint(char *argv);
int hasDuplicates(stack *myStack, int value);


//security
int	ft_isdigitnospace(int a);
int	security(char* argv);

//tableaua
void	processNumber(char *numberStr, stack* myStack, int sign);
void	tableaua(char *argv, stack *myStack);
void	pushtab(stack *stack, int value);

////////////////
//REGLES///////////////////////////////

//swap
void    swap_a(stack *stack);
void    swap_b(stack *stack);
void    swap(stack *stack);

//push
void    push_a(stack *a_stack, stack *b_stack);
void    push_b(stack *a_stack, stack *b_stack);
void    push(stack *stack);

//rotate
void    rotate_a(stack *stack);
void    rotate_b(stack *stack);
void    rotate(stack *stack);

//reverse rotate
void    rrotate_a(stack *stack);
void    rrotate_b(stack *stack);
void    rrotate(stack *stack);

//FIN REGLES/////////////////////////////
/////////////////

//utilities1
long long	ft_atoll(const char *str);

//utilities exit
size_t	my_strcspn(const char* str1, const char* str2);
char* 	my_fgets(char* str, int num, FILE* stream);
int		my_fileno(FILE *stream);



//TEMP 
void print_stack(stack *s, stack *c);
void sort(stack *b_list, stack *a_list);


int find_max_index_b(stack *b_list);
int find_min_index_a(stack *stack);
int find_min_index_b(stack *stack);

#endif