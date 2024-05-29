/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:30 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/29 13:23:54 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"




void send_bit(int pid, char c, int bit_index)
{
    if (bit_index < 8)
    {
        if ((c >> bit_index) & 1)
            kill(pid, SIGUSR2); // Envoyer 1
        else
            kill(pid, SIGUSR1); // Envoyer 0
        usleep(100); // Attendre un peu pour éviter les collisions
        send_bit(pid, c, bit_index + 1); // Envoyer le bit suivant
    }
}

void send_message(int pid, const char *message)
{
    if (*message)
    {
        send_bit(pid, *message, 0);
        send_message(pid, message + 1); // Envoyer le caractère suivant
    }
    else
    {
        // Envoyer un caractère nul pour indiquer la fin du message
        send_bit(pid, '\0', 0);
    }
}

void handle_ack(int signo)
{
    (void)signo;
    // Accusé de réception reçu
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    const char *message = argv[2];

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handle_ack;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    send_message(server_pid, message);

    return 0;
}