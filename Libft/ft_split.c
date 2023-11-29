/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:08:59 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/13 15:17:15 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nbr_mot(char const *s, char c)
{
	int	i;
	int	mot;

	mot = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			mot++;
		}
		s++;
	}
	return (mot);
}

static void	free_mem(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

static char	*mot(const char *s, char c)
{
	size_t	start;
	char	*ptr;

	start = 0;
	while (*s && *s != c)
	{
		start++;
		s++;
	}
	ptr = (char *)malloc(start + 1);
	if (!(ptr))
		return (NULL);
	ft_memcpy(ptr, s - start, start);
	ptr[start] = '\0';
	return (ptr);
}

static char	**sep_mot(const char *s, char c)
{
	int		nbr_mot2;
	char	**ptr;
	int		i;

	nbr_mot2 = nbr_mot(s, c);
	ptr = (char **)malloc((nbr_mot2 + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nbr_mot2)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			ptr[i] = mot(s, c);
			if (!ptr[i] && (free_mem(ptr), 1))
				return (NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (s == NULL)
		return (NULL);
	ptr = sep_mot(s, c);
	if (!ptr)
		return (NULL);
	return (ptr);
}
/*
int main()
{
	const char *str = "aa\0bbb";
	char c = '\0';

	char **res = ft_split(str, c);
	int i = 0;
	while (res[i] != NULL)
	{
		printf ("resultat[%d] = %s\n",i ,res[i]);
		i++;
	}
}*/
