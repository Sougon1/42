/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:44:25 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 14:51:02 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned char	*ptr;
	size_t			len;

	len = ft_strlen(src);
	ptr = (unsigned char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, src, len +1);
	return ((char *)ptr);
}
