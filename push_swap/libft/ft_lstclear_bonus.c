/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:03:51 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 10:11:01 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	if (del == NULL)
		return ;
	if (*lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = (*lst)->next;
			del(temp->content);
			free(temp);
		}
	}
}
