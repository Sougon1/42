/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:35:05 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/03 13:51:18 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;
	size_t	n;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
	n = 0;
	while (n < i)
	{
		ptr[n] = f(n, s[n]);
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
