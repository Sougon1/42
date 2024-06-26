/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:13:53 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/07 13:41:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

# include <fcntl.h> // Ajout de cet en-tête pour open et O_RDONLY
# include <unistd.h> // Ajout de cet en-tête pour read et close

/////////// LIBFT /////////////////////
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *litlle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

int		ft_lstsize(t_list *lst);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
int		ft_isalnum(int a);
int		ft_isalpha(int a);
int		ft_isascii(int a);
int		ft_isdigit(int a);
int		ft_isprint(int a);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *a);

void	ft_lstiter(t_list *lst, void (*f)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int a, size_t v);
void	*ft_calloc(size_t nmemb, size_t size);

//////////// PRINTF ////////////////////////

int	ft_printf(const char *format, ...);

int	ft_printf_c(int c);
int	ft_printf_s(char *str);
int	ft_printf_p(void *ptr);
int	ft_printf_d(int n);
int	ft_printf_i(int n);
int	ft_printf_u(unsigned int n);
int	ft_printf_x(unsigned int n);
int	ft_printf_xx(unsigned int n);

int	ft_putchar(char c);

#endif
