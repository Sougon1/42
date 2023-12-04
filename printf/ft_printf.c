
#include "../Libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (!ft_strchr("cspdiuxX%"))
				break;
			if (format == 'c')
					return (ft_printf_c(va_arg(args, void)));
			else if (format == 's')
					return (ft_printf_s(va_arg(args, char *)));
			else if (format == 'p')
					return (ft_printf_p(va_arg(args, void *)));
			else
				break;
			}
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(args);
}
