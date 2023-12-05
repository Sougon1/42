#include "ft_printf.h"

int	ft_printf_s(char *str)
{
	int	count;

	count = 0;
	while(*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		count++;
		str++;
	}
	return (count);
}
