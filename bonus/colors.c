/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:26:37 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/16 17:59:18 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color(int iter, t_fractol *fract)
{
	int	color_tab[10];

	color_tab[0] = 0x008080;
	color_tab[1] = 0xFF7F50;
	color_tab[2] = 0x6A5ACD;
	color_tab[3] = 0xFFD700;
	color_tab[4] = 0xDA70D6;
	color_tab[5] = 0x87CEEB;
	color_tab[6] = 0x32CD32;
	color_tab[7] = 0xFA8072;
	color_tab[8] = 0xE6E6FA;
	color_tab[9] = 0xFF8C00;
	return (color_tab[(iter + fract->color) % 10]);
}
