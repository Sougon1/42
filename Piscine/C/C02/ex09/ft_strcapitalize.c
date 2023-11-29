/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:25:23 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/20 09:55:22 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= 'A' && str[j] <= 'Z')
		{
			str[j] += 32;
		}
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 32;
		if (!(str[j + 1] >= 'a' && str[j + 1] <= 'z') && \
		((str[j] >= 0 && str[j] <= 47) || (str[j] >= 58 && str[j] <= 64) \
		|| (str[j] >= 91 && str[j] <= 96) || (str[j] >= 123 && str[j] <= 126)))
			j++;
		if ((str[j + 1] >= 'a' && str[j + 1] <= 'z') && \
		((str[j] >= 0 && str[j] <= 47) || (str[j] >= 58 && str[j] <= 64) \
		|| (str[j] >= 91 && str[j] <= 96) || (str[j] >= 123 && str[j] <= 126)))
		{
			str[j + 1] -= 32;
			j++;
		}
	j++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "salUUUT,	?commen#t t{u v}aS ? 42?m*o(t)s qUarante-	deux;cinquante+et+un";

	printf("%s", ft_strcapitalize(str));
}