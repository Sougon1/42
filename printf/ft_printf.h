
#ifndef PRINTF_H
# define PRINTF_H
# include "Libft/libft.h"

# include <stdarg.h>

int	ft_printf(const char *, ...);

int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_p(void *);
int	ft_printf_d(int n);

int	ft_putchar(char c);

#endif
