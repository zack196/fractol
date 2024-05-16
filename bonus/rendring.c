/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:27:03 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/16 18:51:02 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	plot_ship(t_fractol *fract, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	z.x = 0;
	z.y = 0;
	c.x = x / fract->zoom + fract->trans.x;
	c.y = y / fract->zoom + fract->trans.y;
	iter = -1;
	while (++iter < fract->precision)
	{
		z = add_complex(square_complex(z), c);
		if (mod(z) >= __DBL_MAX__)
			break ;
	}
	if (iter == fract->precision)
		my_mlx_pixel_put(&(fract->image), x, y, 0x000000);
	else
		my_mlx_pixel_put(&(fract->image), x, y, color(iter, fract));
}

void	rendring(t_fractol *fract)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SIZE)
	{
		y = -1;
		while (++y < SIZE)
			plot_ship(fract, x, y);
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->image.img, 0, 0);
}
