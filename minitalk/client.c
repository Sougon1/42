/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:30 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/04 15:02:49 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	send_bit(int pid, char c, int bit_index)
{
	if (bit_index < 8)
	{
		if ((c >> bit_index) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "PID inexistant\n", 15);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Wrong PID\n", 10);
				exit(EXIT_FAILURE);
			}
		}
		// Attendre l'accusé de réception
		while (!g_ack_received)
			usleep(50);
		g_ack_received = 0;
		send_bit(pid, c, bit_index + 1);
	}
}

void	send_message(int pid, const char *message)
{
	while (*message)
	{
		send_bit(pid, *message, 0);
		message++;
	}
	send_bit(pid, '\0', 0);
	write(1, "Message send\n", 14);
}

void	handle_ack(int signo)
{
	(void)signo;
	g_ack_received = 1;
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	const char			*message = argv[2];
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > INT_MAX)
		exit(EXIT_FAILURE);
	server_pid = ft_atoi(argv[1]);
	sa.sa_flags = 0;
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (1);
	}
	send_message(server_pid, message);
	return (0);
}
