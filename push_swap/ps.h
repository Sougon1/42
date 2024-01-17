/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/17 11:42:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_H
# define PS_H

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct {
	Node* top;
} Stack

//push_swap



//security
int ft_isdigitnospace(int a);
int security(char* argv);

 //tableaua
 void processNumber(char *numberStr, Stack* myStack, int sign);
 void tableaua(char *argv, Stack *myStack);






#endif