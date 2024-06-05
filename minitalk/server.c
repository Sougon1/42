/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:27 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/05 11:50:35 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	resize_tab(char **ptr, size_t *size, size_t *capacity)
{
	char	*new_ptr;

	*capacity += 1;
	new_ptr = (char *)malloc((*capacity) * sizeof(char));
	if (!new_ptr)
	{
		free(*ptr);
		exit(EXIT_FAILURE);
	} 
	ft_memcpy(new_ptr, *ptr, (*size) * sizeof(char));
	free(*ptr);
	*ptr = new_ptr;
}

void	ft_tab(char c)
{
	static size_t	capacity = 1;
	static char		*ptr = NULL;
	static size_t	size;

	// Capacité initiale du tableau// Initialisation de la mémoire si c'est la première fois
	if (ptr == NULL)
	{
		ptr = (char *)malloc(capacity * sizeof(char));
		if (!ptr)
		{
			exit(EXIT_FAILURE);
		}
	}
	if (size >= capacity)
		resize_tab(&ptr, &size, &capacity);
	ptr[size++] = c;
	if (c == '\0')
	{
		write(1, ptr, size - 1);
		write(1, "\n", 1);
		free(ptr);
		ptr = NULL;
		size = 0;
		capacity = 1;
	}
}

void	handle_signal(int signo, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits_received = 0;

	(void)context;
	if (signo == SIGUSR1)
	{
		c |= (0 << bits_received);
	}
	else if (signo == SIGUSR2)
	{
		c |= (1 << bits_received);
	}
	bits_received++;
	if (bits_received == 8)
	{
		ft_tab(c);
		// write(1, &c, 1);
		bits_received = 0;
		c = 0;
	} // envoi signal de confirmation au client
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		write(1, "Error\n", 6);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server running with PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction SIGUSR1");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction SIGUSR2");
		return (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
