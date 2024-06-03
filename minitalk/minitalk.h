/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:37:46 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/03 15:01:40 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

# include "../printf/ft_printf.h"




//main 



//SERVER
void	handle_signal(int signo, siginfo_t *info, void *context);



//CLIENT
void send_bit(int pid, char c, int bit_index);
void send_message(int pid, const char *message);
void handle_ack(int signo);
int	ft_atoi(const char *nptr);



#endif