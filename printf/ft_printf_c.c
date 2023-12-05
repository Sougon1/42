
#include "ft_printf.h"

int	ft_printf_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
