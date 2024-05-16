/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:26:42 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/16 19:17:58 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_pres(int button, t_fractol *fract)
{
	if (button == 124)
		fract->trans.x -= 50 / fract->zoom;
	else if (button == 123)
		fract->trans.x += 50 / fract->zoom;
	else if (button == 126)
		fract->trans.y += 50 / fract->zoom;
	else if (button == 125)
		fract->trans.y -= 50 / fract->zoom;
	else if (button == 8)
		fract->color++;
	else if (button == 69 && fract->precision < 200)
		fract->precision += 10;
	else if (button == 78 && fract->precision > 10)
		fract->precision -= 10;
	else if (button == 15)
		fract_centring(fract);
	else if (button == 53)
		clean_fract(fract);
	rendring(fract);
	return (0);
}
int	mouse_handling(int button, int x, int y, t_fractol *fract)
{
	double	zoom_factor;

	zoom_factor = 1.4;
	if (button == 5)
	{
		fract->trans.x = (x / fract->zoom + fract->trans.x)
			- x / (fract->zoom * zoom_factor);
		fract->trans.y = (y / fract->zoom + fract->trans.y)
			- y / (fract->zoom * zoom_factor);
		fract->zoom *= zoom_factor;
	}
	if (button == 4)
	{
		fract->trans.x = (x / fract->zoom + fract->trans.x)
			- x / (fract->zoom / zoom_factor);
		fract->trans.y = (y / fract->zoom + fract->trans.y)
			- y / (fract->zoom / zoom_factor);
		fract->zoom /= zoom_factor;
	}
	rendring(fract);
	return (0);
}

int	clean_fract(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx, fract->image.img);
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(1);
	return (1);
}
