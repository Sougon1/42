/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:37:46 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/10 12:29:28 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Utilities_server
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Utilities_client
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);

// SERVER
void	handle_signal(int signo, siginfo_t *info, void *context);
void	ft_tab(char c);
void	resize_tab(char **ptr, size_t *size, size_t *capacity);

// CLIENT
void	send_bit(int pid, char c, int bit_index);
void	send_message(int pid, const char *message);
void	handle_ack(int signo);

#endif