#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
    	return (1);
	return (0);
}

int	chec_julia(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '.')
		return (0);
	while (is_digit(*s) && *s != '.' && *s)
		s++;
	if (*s == '.')
		s++;
	while (is_digit(*s) && *s)
		s++;
	if (!*s)
		return (1);
	return (0);
}

double	ft_atod(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while (*s == '+'|| *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return ((integer_part + fractional_part) * sign);
}