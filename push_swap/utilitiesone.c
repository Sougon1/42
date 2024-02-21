
#include "ps.h"


long long   ft_atoll(const char *str)
{
    long long result;
    int sign;
    
    sign = 1;
    result = 0;
    while (*str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        else
            sign = 1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}
