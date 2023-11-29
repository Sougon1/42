/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:48:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/06/13 17:07:05 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strupcase(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= 'a' && str[j] <= 'z')
		{
			str[j] -= 'a' - 'A';
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