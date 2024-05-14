/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:26:54 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/14 10:35:14 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract(t_fractol *fract, char *name)
{
	fract->name = name;
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	fract->mlx_win = mlx_new_window(fract->mlx, SIZE, SIZE, fract->name);
	if (!fract->mlx_win)
	{
		free(fract->mlx);
		exit(1);
	}
	fract->image.img = mlx_new_image(fract->mlx, SIZE, SIZE);
	fract->image.addr = mlx_get_data_addr(fract->image.img,
			&(fract->image.bits_per_pixel), &(fract->image.line_length),
			&(fract->image.endian));
	fract_centring(fract);
	mlx_key_hook(fract->mlx_win, key_pres, fract);
	mlx_mouse_hook(fract->mlx_win, mouse_handling, fract);
	mlx_hook(fract->mlx_win, 17, 0L, clean_fract, fract);
}

void	fract_centring(t_fractol *fract)
{
	fract->precision = 42;
	fract->trans.x = -1.501337;
	fract->trans.y = -1.501337;
	fract->zoom = 0.37 * SIZE;
}
void	leak()
{
	system("leaks fractol");
}
int	main(int ac, char **av)
{
	t_fractol	*fract;

	atexit(leak);
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 2 && !ft_strcmp(av[1], "burning_ship"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")
			&& chec_julia(av[2]) && chec_julia(av[3])))
	{
		fract = malloc(sizeof (t_fractol));
		init_fract(fract, av[1]);
		if (!ft_strcmp(fract->name, "julia"))
		{
			fract->julia.x = ft_atod(av[2]);
			fract->julia.y = ft_atod(av[3]);
		}
		rendring(fract);
		mlx_loop(fract->mlx);
		clean_fract(fract);
		free(fract);
	}
	else
	{
		ft_strput("Availible fractol : mandelbrot, julia and burning_ship\n");
		ft_strput("If you choose julia, you should enter 2 double values!\n");
	}
}
