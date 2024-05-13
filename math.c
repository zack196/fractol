#include "fractol.h"

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}
double	abs_val(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}
t_complex	square_complex(t_complex z, char *frac_name)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	if (!ft_strcmp(frac_name, "burning_ship"))
	{
		// printf("in\n");
		res.y = 2 * abs_val(z.x) * abs_val(z.y);
	}
	return (res); 
}
double	mod(t_complex z)
{
	double	mod;

	mod = z.x * z.x + z.y * z.y;
	return (mod); 
}