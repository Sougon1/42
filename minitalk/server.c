/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:27 by ghumm             #+#    #+#             */
/*   Updated: 2024/05/29 11:06:43 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"




int main()
{
    pid_t pid = getpid();
    ft_printf("Server running with PID: %d\n", pid);

    signal(SIGUSR1, client);
    signal(SIGUSR2, server);

    while (1)
    {
        pause();
    }

    return (0);
}