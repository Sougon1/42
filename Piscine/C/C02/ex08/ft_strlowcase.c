/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:09:20 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/13 17:08:03 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strlowcase(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= 'A' && str[j] <= 'Z')
		{
			str[j] += 'a' - 'A';
		}
	j++;
	}
	return (str);
}

/*
int	main(void)
{
	char str[] = "sAlUT";

	printf("%s devient %s", str, ft_strupcase(str));
}*/
