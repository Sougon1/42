/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:29:13 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 11:28:15 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "Libft/libft.h"

# include <stdarg.h>

int	ft_printf(const char *, ...);

int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_p(void *);
int	ft_printf_d(int n);
int	ft_printf_i(int n);
int	ft_printf_u(unsigned int n);

int	ft_putchar(char c);

#endif
