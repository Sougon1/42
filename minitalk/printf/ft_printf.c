/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:16:58 by ghumm             #+#    #+#             */
/*   Updated: 2024/01/22 10:50:06 by ghumm            ###   ########.fr       */
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
	{
		*count += ft_putchar('%');
		*count += ft_putchar(*format);
	}
	return (*count);
}

static int	percent(const char **format, va_list args, int *count)
{
	if (**format == '%')
	{
		(*format)++;
		val(*format, args, count);
		(*format)++;
		if (**format == '%')
			percent(format, args, count);
	}		
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		percent(&format, args, &count);
		if (*format == '\0')
			break ;
		count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	int cha = '0';
	char *str = "coucou";
	int x = 42;
	int	*ptr = &x;
	unsigned int xx= 123456789;
	
	printf("\n");

//	ft_printf("%k\n\n", cha);
//	printf("printf    'k' : %k \n\n", cha);

	printf("printf	  'c' : %c\n", cha);
	ft_printf("%c%c", '0', '1');

	printf("\n\n");

	printf("printf	  's' : %s\n", str);
	ft_printf("%s", str);

	printf("\n\n");

	printf("printf    'p' : %p\n", ptr);
	ft_printf("%p", ptr);

	printf("\n\n");

	printf("printf    'd' : %d\n", x);
	ft_printf("%d", x);

	printf("\n\n");

	printf("printf    'i' : %i\n", x);
	ft_printf("%i", x);

	printf("\n\n");

	printf("printf    'u' : %u\n", xx);
	ft_printf("%u", xx);

	printf("\n\n");

	printf("printf    'x' : %x\n", xx);
	ft_printf("%x", xx);

	printf("\n\n");

	printf("printf    'X' : %X\n", xx);
	ft_printf("%X ", xx);

	printf("\n\n");

	printf("printf    '%%%%' : %%\n");
	ft_printf("%%%% ");

	printf("\n");
}*/