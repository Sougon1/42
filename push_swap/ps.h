/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/16 10:35:37 by ghumm            ###   ########.fr       */
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

int ft_isdigitnospace(int a);
int security(char* argv);




#endif