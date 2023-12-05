
#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned long long n)
{
	char	hex[] = "0123456789abcdef";
	int		count;

	count = 0;
	if (n >= 16 )
		ft_putnbr_hex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_printf_p(void *ptr)
{
	int adress_len ;

	if (write(1 ,"0x", 2) == -1)
		return (-1);
	adress_len = ft_putnbr_hex((unsigned long long)ptr);

	return (2 + adress_len) ;
}
