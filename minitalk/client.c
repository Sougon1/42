/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:30 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/03 15:16:11 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



volatile sig_atomic_t g_ack_received = 0;

void send_bit(int pid, char c, int bit_index)
{
    if (bit_index < 8)
    {
        if ((c >> bit_index) & 1)
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                perror("kill");
                exit(EXIT_FAILURE);
            }
            // printf("Sent SIGUSR2 (1)\n");
        }
        else
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                perror("kill");
                exit(EXIT_FAILURE);
            }
            // printf("Sent SIGUSR1 (0)\n");
        }

        // Attendre l'accusé de réception
        while (!g_ack_received)
            usleep(50);

        g_ack_received = 0;
        send_bit(pid, c, bit_index + 1); // Envoyer le bit suivant
    }
}

void send_message(int pid, const char *message)
{
    while (*message)
    {
        send_bit(pid, *message, 0);
        message++;
    }

    // Envoyer un caractère nul pour indiquer la fin du message
    send_bit(pid, '\0', 0);
    send_bit(pid, '\n', 0);
}

void handle_ack(int signo)
{
    (void)signo;
    g_ack_received = 1;
    // printf("Received acknowledgment\n");
}

int ft_atoi(const char *nptr)
{
    int sign = 1;
    int valeur = 0;

    while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
        nptr++;
    if (*nptr == 45 || *nptr == 43)
    {
        if (*nptr == 45)
            sign *= -1;
        nptr++;
    }
    while (*nptr >= 48 && *nptr <= 57)
    {
        valeur = (valeur * 10) + (*nptr - 48);
        nptr++;
    }
    return (valeur * sign);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }
    if (ft_atoi(arg[1]) < 0 || > INT_MAX)
    {
        return (EXIT_FAILURE, 0);
    }
    

    pid_t server_pid = ft_atoi(argv[1]);
    const char *message = argv[2];

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handle_ack;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    send_message(server_pid, message);
    exit(EXIT_FAILURE);
    return 0;
}