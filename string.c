#include "fractol.h"

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && s2)
    {
        s1++;
        s2++;
    }
    return (*s2 - *s1);
}

int is_digit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}