
#include "ft_printf.h"

int	ft_printf_i(int n)
{
	int	count;
	char	digit;

	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n > 10)
		count += ft_printf_i(n / 10);
	digit = '0' + n % 10;
	if (ft_putchar(digit) == -1)
		return (-1);
	return (count + 1);
}
