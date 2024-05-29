/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:27 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/29 13:23:07 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int signo, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits_received;

    c = 0;
    bits_received = 0;
	(void)context;
	if (signo == SIGUSR1)
		c |= (0 << bits_received);
	else if (signo == SIGUSR2)
		c |= (1 << bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		write(1, &c, 1);
		bits_received = 0;
		c = 0;
	}
	// Envoyer un signal d'accusé de réception au client
	kill(info->si_pid, SIGUSR1);
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
