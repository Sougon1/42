/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:28:13 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/05 12:02:55 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	i = 0;
	dest1 = (char *) dest;
	src1 = (const char *) src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
