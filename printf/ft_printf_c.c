
#include "libftprintf.h"
#include "../libft/libft.h"

void	ft_printf_c(char c)
{
	return (write(1, &c, 1));
}
