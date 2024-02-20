#include "ps.h"

long securityint(char* argv)
{
    long long   i;

    if (i >= 2147483647 || i <= -2147483648)
    {
        ft_printf("Valeur INT depasser");
        return (0);
    }
    return (1);
}
