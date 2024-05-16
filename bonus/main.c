/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:26:54 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/16 19:15:46 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_fract(t_fractol *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	fract->mlx_win = mlx_new_window(fract->mlx, SIZE, SIZE, "burning_ship");
	if (!fract->mlx_win)
		exit(1);
	fract->image.img = mlx_new_image(fract->mlx, SIZE, SIZE);
	if (!fract->image.img)
	{
		mlx_destroy_window(fract->mlx, fract->mlx_win);
		exit(1);
	}
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
	fract->color = 1;
	fract->trans.x = -2.017400;
	fract->trans.y = -2.0;
	fract->zoom = 0.32 * SIZE;
}

int	main()
{
	t_fractol	fract;

	if (SIZE == 0)
		return (1);
	init_fract(&fract);
	rendring(&fract);
	mlx_loop(fract.mlx);
	clean_fract(&fract);
}
