/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:27 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/03 15:34:47 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signo, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bits_received = 0;

    (void)context;
    if (signo == SIGUSR1)
    {
        c |= (0 << bits_received); // Appending a 0 bit
        // printf("Received SIGUSR1 (0)\n");
    }
    else if (signo == SIGUSR2)
    {
        c |= (1 << bits_received); // Appending a 1 bit
        // printf("Received SIGUSR2 (1)\n");
    }

    bits_received++;


//a mettre dans un fichier pour tout afficher dun coup
    if (bits_received == 8)
    {
        write(1, &c, 1); // Print the accumulated character
        bits_received = 0;
        c = 0;
    }

    // Send acknowledgment signal to the client
    if (kill(info->si_pid, SIGUSR1) == -1)
    {
        perror("kill");
    }
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    ft_printf("Server running with PID: %d\n", pid);

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction SIGUSR1");
        return 1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("sigaction SIGUSR2");
        return 1;
    }

    while (1)
    {
        pause(); // Wait for signals indefinitely
    }
    return 0;
}