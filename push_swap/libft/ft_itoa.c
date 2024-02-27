/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:47:19 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/03 11:51:10 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	lenn(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	nneg(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		neg;

	neg = (n < 0);
	len = lenn(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ptr = (char *)malloc(len + 1 + neg);
	if (!ptr)
		return (NULL);
	ptr[len + neg] = '\0';
	while (len > 0)
	{
		ptr[len - 1 + neg] = nneg(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg)
		ptr[0] = '-';
	return (ptr);
}
