/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/18 12:37:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_H
# define PS_H

# ifndef LIBFT_H
#	define LIBFT_H
# endif
# ifndef FT_PRINTF_H
#	define FT_PRINTF_H
# endif

//# include "ft_printf.h"

# include <stddef.h>
# include <stdio.h>


typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct {
	t_list* top;
} stack;

//push_swap
void	initializelist(stack* stack);



//security
int	ft_isdigitnospace(int a);
int	security(char* argv);

//tableaua
void	processNumber(char *numberStr, stack* myStack, int sign);
void	tableaua(char *argv, stack *myStack);
void	pushtab(stack *stack, int value);





#endif