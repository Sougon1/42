/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:51 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 14:40:07 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	dif;
	char	*ptr;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) && start < end)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	dif = end - start;
	if (dif == SIZE_MAX)
		return (NULL);
	ptr = (char *)malloc(dif + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1 + start, dif);
	ptr[dif] = '\0';
	return (ptr);
}
/*
int main() {
    // Création d'une chaîne très grande
    const char *original = "A B C D E F G H I J K L M \
	N O P Q R S T U V W X Y Z ";

    // Création d'un ensemble de caractères à retirer (set)
    const char *set = " ";

    // Forcer une valeur très grande pour dif

    // Appel de la fonction ft_strtrim
    char *trimmed = ft_strtrim(original, set);

    // Vérification du résultat
    if (trimmed) {
        printf("Chaîne d'origine : '%s'\n", original);
        printf("Chaîne après trim : '%s'\n", trimmed);

        // N'oubliez pas de libérer la mémoire allouée
        free(trimmed);
    } else {
        printf("Erreur lors de l'appel à ft_strtrim\
		(possiblement dépassement de SIZE_MAX).\n");
    }

    return 0;
}*/
