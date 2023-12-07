/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:16:58 by ghumm             #+#    #+#             */
/*   Updated: 2023/12/07 14:35:20 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	val(const char *format, va_list args, int *count)
{
	if (*format == 'c')
		*count += ft_printf_c(va_arg(args, int));
	else if (*format == 's')
		*count += ft_printf_s(va_arg(args, char *));
	else if (*format == 'p')
		*count += ft_printf_p(va_arg(args, void *));
	else if (*format == 'd')
		*count += ft_printf_d(va_arg(args, int));
	else if (*format == 'i')
		*count += ft_printf_i(va_arg(args, int));
	else if (*format == 'u')
		*count += ft_printf_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		*count += ft_printf_x(va_arg(args, unsigned int));
	else if (*format == 'X')
		*count += ft_printf_xx(va_arg(args, unsigned int));
	else if (*format == '%')
		*count += ft_putchar('%');
	else
		*count += ft_putchar(*format);
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			val(format, args, &count);
//			printf("\n%d\n", count);
			format++;
		}
		count += ft_putchar (*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	int cha = 'A';
	char *str = "";
	int x = 10;
	int	*ptr = &x;
	unsigned int xx= 123456789;
	
	ft_printf("\n");

	ft_printf("ft_printf 'k' : %k \n\n", cha);
//	printf("printf    'k' : %k \n\n", cha);

	ft_printf("%c ", cha);
	printf("printf	  'c' : %c\n\n", cha);

	ft_printf("ft_printf 's' : %s\n", str);
	printf("printf	  's' : %s\n\n", str);

	ft_printf("ft_printf 'p' : %p\n", ptr);
	printf("printf    'p' : %p\n\n", ptr);

	ft_printf("%d\n", x);
	printf("printf    'd' : %d\n\n", x);

	ft_printf("ft_printf 'i' : %i\n", x);
	printf("printf    'i' : %i\n\n", x);

	ft_printf("ft_printf 'u' : %u\n", xx);
	printf("printf    'u' : %u\n\n", xx);

	ft_printf("ft_printf 'x' : %x\n", xx);
	printf("printf    'x' : %x\n\n", xx);

	ft_printf("ft_printf 'X' : %X\n", xx);
	printf("printf    'X' : %X\n\n", xx);

	ft_printf("ft_printf '%%' : %%\n");
	printf("printf    '%%' : %%\n\n");
}*/