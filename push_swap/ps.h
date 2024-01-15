/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:04 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/15 14:17:22 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PS_H
# define PS_H

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;


int ft_isdigitnospace(int a);
int security(char* argv);




#endif