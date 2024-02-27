/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/02/27 15:37:59 by ghumm            ###   ########.fr       */
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

typedef struct {
	a_list* top;
} stack;


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

//utilities1
long long	ft_atoll(const char *str);



#endif