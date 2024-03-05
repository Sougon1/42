/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/05 15:35:06 by marvin           ###   ########.fr       */
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

//utilities exit
size_t	my_strcspn(const char* str1, const char* str2);
char* 	my_fgets(char* str, int num, FILE* stream);
int		my_fileno(FILE *stream);


#endif