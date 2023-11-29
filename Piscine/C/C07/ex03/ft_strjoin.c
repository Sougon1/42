/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:48:17 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/28 15:59:54 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str) {
    int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

char	*ft_strcat(char *dest, char *src)
{
	char	*dest1;

	dest1 = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest1);
}

char *ft_strjoin(int size, char **strs, char *sep) {
    if (size == 0) {
        char *result = (char *)malloc(sizeof(char));
        *result = '\0';
        return result;
    }

    int sep_len = ft_strlen(sep);
    int total_length = 0;
    char **temp = strs;

    while (*temp) {
        total_length += ft_strlen(*temp);
        temp++;
    }
    total_length += (size - 1) * sep_len;

    char *result = (char *)malloc((total_length + 1) * sizeof(char));
    char *current = result;

    temp = strs;
    while (*temp) {
        ft_strcat(current, *temp);
        current += ft_strlen(*temp);
        if (*(temp + 1)) {
            ft_strcat(current, sep);
            current += sep_len;
        }
        temp++;
    }

    return result;
}

int main() {
    char *strs[] = {"Hello", "world", "!", NULL};
    char *sep = " ";
    int size = 3;

    char *result = ft_strjoin(size, strs, sep);

    printf("Concatenated string: %s\n", result);

    free(result);

    return 0;
}


