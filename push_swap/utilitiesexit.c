/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitiesexit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:38:43 by marvin            #+#    #+#             */
/*   Updated: 2024/03/06 09:44:24 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int my_fileno(FILE *stream)
{
    if (stream == NULL)
        return (-1);
    // Retourner le descripteur de fichier associé au flux
    return (stream->_fileno);
}

char* my_fgets(char* str, int num, FILE* stream)
{
    int bytes_read;
    char c;
    if (num <= 0 || str == NULL || stream == NULL)
        return (NULL); // Vérification des entrées invalides
    bytes_read = read(my_fileno(stream), str, num - 1); // -1 pour réserver l'espace pour le caractère nul
    if (bytes_read <= 0)
        return (NULL); // Aucun caractère lu ou erreur de lecture
    str[bytes_read] = '\0'; // Ajout du caractère de fin de chaîne
    if (str[bytes_read - 1] != '\n')// Si le dernier caractère n'est pas un retour à la ligne, le reste de la ligne est dans le flux
        while (read(my_fileno(stream), &c, 1) > 0 && c != '\n');
    return (str);
}

size_t my_strcspn(const char* str1, const char* str2)
{
    size_t length;
    int i;

    length = 0;
    while (str1[length] != '\0' && str1[length] != '\n')
    {
        i = 0;
        while (str2[i] != '\0')
        {
            if (str1[length] == str2[i])
                return (length);
            i++;
        }
        length++;
    }
    return (length);
}