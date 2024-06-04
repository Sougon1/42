/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <ghumm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:40:27 by ghumm             #+#    #+#             */
/*   Updated: 2024/06/04 15:12:13 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	d = (unsigned char *)dest;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

void	resize_tab(char **ptr, size_t *size, size_t *capacity)
{
	char	*new_ptr;

	*capacity *= 2;
	new_ptr = (char *)malloc((*capacity) * sizeof(char));
	if (!new_ptr)
	{
		free(*ptr);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_ptr, *ptr, (*size) * sizeof(char));
	free(*ptr);
	*ptr = new_ptr;
		// printf("Tableau redimensionné à la nouvelle capacité: %zu\n", *capacity);
}

void	ft_tab(char c)
{
	static size_t	capacity=1;
	static char *ptr  = NULL;
	static size_t size = 0;
	// Capacité initiale du tableau// Initialisation de la mémoire si c'est la première fois
	if (ptr == NULL)
	{
		ptr = (char *)malloc(capacity * sizeof(char));
		if (!ptr)
		{
			exit(EXIT_FAILURE);
		}
	} 
	if (size >= capacity)
		resize_tab(&ptr, &size, &capacity);
	ptr[size++] = c;
	if (c == '\0')
	{
		write(1, ptr, size - 1);
		write(1, "\n", 1);
		free(ptr);
		ptr = NULL;
		size = 0;
		capacity = 1;
	}
}


// void	ft_tab(char c)
// {
// 	static char		*ptr = NULL;
// 	static size_t	size = 0;
// 	static size_t	capacity = 1;
// 	char			*new_ptr;

// 	// Initialiser la capacité initiale si c'est la première fois
// 	if (ptr == NULL)
// 	{
// 		ptr = (char *)malloc(capacity * sizeof(char));
// 		if (!ptr)
// 		{
// 			perror("malloc");
// 			exit(EXIT_FAILURE);
// 		}
// 	} // Si la capacité est dépassée,créer un nouveau tableau avec une capacité double
// 	if (size >= capacity)
// 	{
// 		capacity *= 2;
// 		new_ptr = (char *)malloc(capacity * sizeof(char));
// 		if (!new_ptr)
// 		{
// 			free(ptr);
// 			exit(EXIT_FAILURE);
// 					printf("Tableau redimensionné à la nouvelle capacité: %zu\n", capacity);

// 		}                                            
// 			// Copier les données de l'ancien tableau au nouveau tableau
// 		ft_memcpy(new_ptr, ptr, size * sizeof(char));
// 			// Libérer l'ancien tableau et rediriger le pointeur vers le nouveau
// 		free(ptr);
// 		ptr = new_ptr;
// 	}                // Ajouter le caractère et augmenter la taille
// 	ptr[size++] = c; // Afficher le tableau (optionnel, pour vérifier)
// 	// Si le caractère de fin de transmission est reçu, afficher le tableau
// 	if (c == '\0')
// 	{
// 		write(1, ptr, size - 1);
// 			// Afficher les caractères du tableau sauf le caractère nul
// 		write(1, "\n", 1);       // Nouvelle ligne après l'affichage du tableau
// 		// Réinitialiser la taille pour la prochaine réception de message
// 		size = 0;
// 	}
// }


void	handle_signal(int signo, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits_received = 0;

	(void)context;
	if (signo == SIGUSR1)
	{
		c |= (0 << bits_received);
	}
	else if (signo == SIGUSR2)
	{
		c |= (1 << bits_received);
	}
	bits_received++;
	if (bits_received == 8)
	{
		ft_tab(c);
		// write(1, &c, 1);
		bits_received = 0;
		c = 0;
	} // envoi signal au client
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		perror("kill");
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server running with PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction SIGUSR1");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction SIGUSR2");
		return (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
