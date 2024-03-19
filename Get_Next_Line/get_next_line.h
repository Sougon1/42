/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:32:27 by ghumm             #+#    #+#             */
/*   Updated: 2024/03/19 10:29:10 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <unistd.h> // read
# include <stdlib.h> // malloc/free
//# include <stdio.h>
# include <fcntl.h> // open(..., ...)

char	*get_next_line(int fd);
size_t	ft_strlen(char	*str);
char	*ft_strchr(char *s, int c);
char	*ft_join(char *dest, char *s1, char *s2);
char	*ft_strjoin(char *start, char *buff);

#endif
