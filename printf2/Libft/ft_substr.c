/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:22:14 by ghumm             #+#    #+#             */
/*   Updated: 2023/10/25 15:36:55 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i || len == 0)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	ptr = ((char *)malloc(len + 1));
	if (!(ptr))
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return ((char *)ptr);
}
