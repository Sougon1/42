/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:51 by ghumm             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/28 16:00:41 by ghumm            ###   ########.fr       */
=======
/*   Updated: 2024/05/28 15:49:11 by ghumm            ###   ########.fr       */
>>>>>>> 2ece995 (maj)
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	initializelist(t_stack *stack)
{
	stack->a_top = NULL;
	stack->b_top = NULL;
	stack->size = 0;
}

int	main(int argc, char *argv[])
{
	long long	i;
	t_stack		a_list;
	t_stack		b_list;

	i = 1;
	if (argc == 1)
	{
		return (0);
	}
	while (argv[i])
	{
		if (security(argv[i]) == 0)
			return (0);
		i++;
	}
	initializelist(&a_list);
	initializelist(&b_list);
	tableaua(argv[1], &a_list);
	sorted(argc, &a_list, &b_list);
	free_stack(&a_list);
	free_stack(&b_list);
	exit(EXIT_SUCCESS);
}

void	free_stack(t_stack *stack)
{
	t_stack_element	*current;
	t_stack_element	*next;

	current = stack->a_top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->a_top = NULL;
	stack->b_top = NULL;
	stack->size = 0;
}
