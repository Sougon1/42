/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:38:58 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/20 11:46:46 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	longu;

	longu = 0;
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		longu++;
		size--;
	}
	*dest = '\0';
	return (longu);
}


int main(void)
{
	unsigned int size = 7;
	char dest[5];	
//	char src[] = "Hello  World!";
	char src[] = "1234567890";

	printf("%s\n%d\n",dest, ft_strlcpy(dest, src, size));
	
}
