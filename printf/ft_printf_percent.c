
#include "ft_printf.h"

int ft_printf_percent(const char **format)
{
    int count = 0;
    while (**format == '%')
    {
        count += ft_putchar('%');
        (*format)++;
    }
    return (count);
}
