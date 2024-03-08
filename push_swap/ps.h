/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/08 13:22:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_H
# define PS_H

# include "libft/libft.h"


typedef struct a_list
{
	int				value;
	struct a_list	*next;
}	a_list;

typedef struct b_list
{
	int				value;
	struct b_list	*next;
}	b_list;

typedef struct {
	a_list	*a_top;
	b_list	*b_top;
} stack;

//entry
char    entry(char input);

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
void    swap(stack *stack, int value);

//push
void    push_a(stack *stack);
void    push_b(stack *stack);
void    push(stack *stack, int value);

//rotate
void    rotate_a(stack *stack);
void    rotate_b(stack *stack);
void    rotate(stack *stack, int value);

//reverse rotate
void    rrotate_a(stack *stack);
void    rrotate_b(stack *stack);
void    rrotate(stack *stack, int value);

//FIN REGLES/////////////////////////////
/////////////////

//utilities1
long long	ft_atoll(const char *str);

//utilities exit
size_t	my_strcspn(const char* str1, const char* str2);
char* 	my_fgets(char* str, int num, FILE* stream);
int		my_fileno(FILE *stream);


#endif