#include "fractol.h"

void	init_fract(t_fractol *fract, char *name)
{
	fract->name = name;
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	fract->mlx_win = mlx_new_window(fract->mlx, size, size, fract->name);
	if (!fract->mlx_win)
	{
		free(fract->mlx);
		exit(1);
	}
	fract->image.img = mlx_new_image(fract->mlx, size, size);
	fract->image.addr = mlx_get_data_addr(fract->mlx, 
		&(fract->image.bits_per_pixel)
		, &(fract->image.line_length), &(fract->image.endian));
	fract_centring(fract);
	// mlx_key_hook(fract->mlx_win, key_pres, fract);
	// mlx_mouse_hook(fract->mlx_win, mouse_handling, fract);
}
void	fract_centring(t_fractol *fract)
{
	fract->precision = 42;
	fract->trans.x = -1.337;
	fract->trans.y = -1.337;
	fract->zoom = 0.4 * size;
}
int	main(int ac, char **av)
{
	t_fractol	*fract;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 2 && !ft_strcmp(av[1], "burning_ship"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")
		&& chec_julia(av[2]) && chec_julia(av[3])))
	{
		fract = malloc(sizeof (t_fractol));
		init_fract(fract, av[1]);
		printf("3iw!!\n");
	}
	else
		printf("outch\n");
}