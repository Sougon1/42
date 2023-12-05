
#include "ft_printf.h"

static int	val(const char *format, va_list args)
{
	int count;

	count = 0;
	if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
	{
		format++;
		if (*format == 'c')
			count += ft_printf_c(va_arg(args, int));
/*		else if (*format == 's')
			count += ft_printf_s(va_arg(args, char *));
		else if (*format == 'p')
			count += ft_printf_p(va_arg(args, unsigned int));
		else if (*format == 'd')
			count += ft_printf_d(va_arg(args, int));
		else if (*format == 'i')
			count += ft_printf_i(va_arg(args, int));
		else if (*format == 'u')
			count += ft_printf_u(va_arg(args, unsigned int));
		else if (*format == 'x')
			count += ft_printf_x(va_arg(args, unsigned int));
		else if (*format == 'X')
			count += ft_prinft_X(va_arg(args, unsigned int));
		else if (*format == '%')
			count += ft_putchar('%');*/
		else
			count += ft_putchar(*format);
	}
	else
		count += ft_putchar(*format);
	return (count);
}


int	ft_printf(const char *format, ...)
{
	int	count;
	va_list args;
	va_start(args, format);

	count = 0;

	while(*format)
	{
		count += val(format, args);
		format++;
	}

	va_end(args);

	return (count);
}

int main()
{
	char cha = 'A';

	ft_printf("ft_printf : %c \n", cha);
	printf("printf : %c \n", cha);


}
