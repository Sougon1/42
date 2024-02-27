/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:55:30 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 16:05:10 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*original_lst;
	void	*new_content;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	original_lst = lst;
	while (original_lst && new_content)
	{
		new_content = f(original_lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			free(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		original_lst = original_lst->next;
	}
	return (new_lst);
}
